/*
 WiFiEsp test: ClientTest
http://www.kccistc.net/
작성일 : 2019.12.17 
작성자 : IoT 임베디드 KSH
*/
#define DEBUG
//#define DEBUG_WIFI

#define AP_SSID "iotsystem0"
#define AP_PASS "iotsystem00"
#define SERVER_NAME "192.168.10.49"
#define SERVER_PORT 5000
#define LOGID "FARM1_F1"
#define PASSWD "PASSWD"

#define WIFITX 7  //7:TX -->ESP8266 RX
#define WIFIRX 6 //6:RX-->ESP8266 TX

#define DHTPIN 4
#define DHTTYPE DHT11
#define RELAY 8
#define TOYANG 1
#define CMD_SIZE 50
#define ARR_CNT 5    

#include<math.h>
#include <DHT.h>
#include "WiFiEsp.h"
#include "SoftwareSerial.h"
#include <MsTimer2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <stdlib.h>

DHT dht(DHTPIN, DHTTYPE);

char sendBuf[CMD_SIZE];
char command[CMD_SIZE];
bool timerIsrFlag = false;
unsigned int secCount;

char sendId[10]="FARM1_AD";
#include "Adafruit_CCS811.h"
#include <Adafruit_NeoPixel.h>
#define PIN            5
#define NUMPIXELS      25
 
Adafruit_CCS811 ccs;
SoftwareSerial wifiSerial(WIFIRX, WIFITX); 
WiFiEspClient client;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int R=0,G=0,B=0;
void setup() {

    pinMode(RELAY, OUTPUT);
    
    digitalWrite(RELAY, LOW);
    ccs.begin();
    ccs.available();
    Serial.begin(115200); //DEBUG

    dht.begin();
    wifi_Setup();

    MsTimer2::set(1000, timerIsr); // 1000ms period
    MsTimer2::start();
    pixels.begin();
    delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(client.available()) {
    socketEvent();
  }
  if (timerIsrFlag)
  {
    timerIsrFlag = false; 
    if(!(secCount%5))
    {
      if (!client.connected()) { 
        server_Connect();
      }
      int Soil_moisture = analogRead(A1);
      int h = dht.readHumidity(); 
      int t = dht.readTemperature();
      int co2 = rand()%9 +40;
      int tvoc = rand()%9 +10;
      // ccs.geteCO2()/10
      // ccs.getTVOC()
      sprintf(sendBuf,"[%s]SENSOR@%d@%d@%d@%d@%d\n",sendId,abs(Soil_moisture-1023)/10,h,t,co2,tvoc);    
      client.write(sendBuf,strlen(sendBuf));
      client.flush();

      Serial.print("습도 : "); 
      Serial.print(h);
      Serial.println(" %"); 
      Serial.print("온도 : "); 
      Serial.print(t); 
      Serial.println(" 'C"); 
      Serial.println();
      if(abs(Soil_moisture-1023)/10 < 60){
//        Serial.println(abs(Soil_moisture-1023)/10);
        digitalWrite(RELAY, HIGH);
//        sprintf(sendBuf,"[%s]WATER PUMP ON %d\n",sendId,abs(Soil_moisture-1023)/10);    
//        client.write(sendBuf,strlen(sendBuf));
//        client.flush();
      }
      else{
        digitalWrite(RELAY, LOW);
//        sprintf(sendBuf,"[%s]WATER PUMP OFF %d\n",sendId,abs(Soil_moisture-1023)/10);    
//        client.write(sendBuf,strlen(sendBuf));
//        client.flush();
      }
    }
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(R,G,B)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }     
  }
}
void socketEvent()
{
  
  int i=0;
  char * pToken;
  char * pArray[ARR_CNT]={0};
  char recvBuf[CMD_SIZE]={0}; 
  int len;

  memset(command,0x00,sizeof(command));
  sendBuf[0] ='\0';
  len =client.readBytesUntil('\n',recvBuf,CMD_SIZE); 
  client.flush();
#ifdef DEBUG
  Serial.print("recv : ");
  Serial.println(recvBuf);
#endif
  pToken = strtok(recvBuf,"[@]");
  while(pToken != NULL)
  {
    pArray[i] =  pToken;
    if(++i >= ARR_CNT)
      break;
    pToken = strtok(NULL,"[@]");
  }
    if(!strcmp(pArray[0],"SNR_ARD"))
  {
    strcpy(command,pArray[1]);
    Serial.println(command);
  }
//  if(!strncmp(pArray[1]," New",4))  // New Connected
//  {
//    Serial.write('\n');
//    strcpy(lcdLine2,"Server Connected");
//    lcdDisplay(0,1,lcdLine2);
//    return ;
//  }
  else if(!strncmp(pArray[1]," Alr",4)) //Already logged
  {
    Serial.write('\n');
    client.stop();
    server_Connect();
    return ;
  }
  else if(!strcmp(pArray[1],"REDON"))
  {
    R = 150;
  }
  else if(!strcmp(pArray[1],"REDOFF"))
  {
    R = 0;
  }
  else if(!strcmp(pArray[1],"BLUEON"))
  {
    B = 150;
  }
  else if(!strcmp(pArray[1],"BLUEOFF"))
  {
    B = 0;
  }
  else if(!strcmp(pArray[1],"PURPLEON"))
  {
    R = 150;
    B = 150;
  }
  else if(!strcmp(pArray[1],"PURPLEOFF"))
  {
    R = 0;
    B = 0;
  }
  Serial.print(pArray[1]);
  client.write(sendBuf,strlen(sendBuf));
  client.flush();

#ifdef DEBUG
  Serial.print(", send : ");
  Serial.print(sendBuf);
#endif
}
void timerIsr()
{
  timerIsrFlag = true;
  secCount++;
}
void wifi_Setup() {
  wifiSerial.begin(19200);
  wifi_Init();
  server_Connect();
}
void wifi_Init()
{
  do {
    WiFi.init(&wifiSerial);
    if (WiFi.status() == WL_NO_SHIELD) {
#ifdef DEBUG_WIFI    
      Serial.println("WiFi shield not present");
#endif 
    }
    else
      break;   
  }while(1);

#ifdef DEBUG_WIFI    
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(AP_SSID);
#endif     
  while(WiFi.begin(AP_SSID, AP_PASS) != WL_CONNECTED) {   
#ifdef DEBUG_WIFI  
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(AP_SSID);   
#endif   
  }
//  sprintf(lcdLine1,"ID:%s",LOGID);  
//  lcdDisplay(0,0,lcdLine1);
//  sprintf(lcdLine2,"%d.%d.%d.%d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3]);
//  lcdDisplay(0,1,lcdLine2);
  
#ifdef DEBUG_WIFI      
  Serial.println("You're connected to the network");    
  printWifiStatus();
#endif 
}
int server_Connect()
{
#ifdef DEBUG_WIFI     
  Serial.println("Starting connection to server...");
#endif  

  if (client.connect(SERVER_NAME, SERVER_PORT)) {
#ifdef DEBUG_WIFI     
    Serial.println("Connect to server");
#endif  
    client.print("["LOGID":"PASSWD"]"); 
  }
  else
  {
#ifdef DEBUG_WIFI      
     Serial.println("server connection failure");
#endif    
  } 
}
void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
