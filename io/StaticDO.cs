using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Reflection;
using System.Runtime.InteropServices;
using Automation.BDaq;

namespace DO_StaticDO
{
   class StaticDO
   {
        static void blow(int nDelay)
        {
            string deviceDescription = "PCI-1730,BID#0";
            string profilePath = "D:\\profile_i\\dev2.xml";

            int startPort = 0;
            int portCount = 1;
            ErrorCode errorCode = ErrorCode.Success;


            InstantDoCtrl instantDoCtrl = new InstantDoCtrl();

            try
            {
                instantDoCtrl.SelectedDevice = new DeviceInformation(deviceDescription);
                errorCode = instantDoCtrl.LoadProfile(profilePath);
                if (BioFailed(errorCode))
                {
                    throw new Exception();
                }

                byte[] bufferForWriting = new byte[64];

                    for (int j = 0; j < 2; j++)
                    {
                        for (int i = 0; i < portCount; ++i)
                        {
                            string data;
                            if (j == 0)
                                data = "0x01";
                            else
                                data = "0x00";
                            

                            bufferForWriting[i] = byte.Parse(data.Contains("0x") ? data.Remove(0, 2) : data, System.Globalization.NumberStyles.HexNumber);

                        }
                        errorCode = instantDoCtrl.Write(startPort, portCount, bufferForWriting);
                        if (BioFailed(errorCode))
                        {
                            throw new Exception();
                        }
                        Console.WriteLine("DO output completed !");
                        if (j == 0)
                        {
                        Console.WriteLine("sleep!");
                            Thread.Sleep(nDelay);
                        }
                    }

                }
            
            catch (Exception e)
            {
                string errStr = BioFailed(errorCode) ? " Some error occurred. And the last error code is " + errorCode.ToString()
                                                           : e.Message;
                Console.WriteLine(errStr);
            }

      }

        static void Main(string[] args)
        {
            string deviceDescription = "PCI-1730,BID#0";

            string profilePath = "D:\\profile_i\\dev2.xml";
            int startPort = 0;
            int portCount = 1;
            ErrorCode errorCode = ErrorCode.Success;
            InstantDiCtrl instantDiCtrl = new InstantDiCtrl();
            try
            {
                instantDiCtrl.SelectedDevice = new DeviceInformation(deviceDescription);
                errorCode = instantDiCtrl.LoadProfile(profilePath);
                if (BioFailed(errorCode))
                {
                    throw new Exception();
                }

                Console.WriteLine("Reading ports' status is in progress..., any key to quit!\n");

                byte[] buffer = new byte[64];
                do
                {
                    
                    errorCode = instantDiCtrl.Read(startPort, portCount, buffer);
                    if (BioFailed(errorCode))
                    {
                        throw new Exception();
                    }
                    for (int i = 0; i < portCount; ++i)
                    {
                        int intbyte = buffer[0];
                        Console.WriteLine(" DI port {0} status : 0x{1:x}\n", startPort + i, buffer[i]);

                        if (buffer[0] == 5)
                        {
                            Console.WriteLine("good\n");
                            blow(10);
                        }
                    }
                    Thread.Sleep(1);
                } while (!Console.KeyAvailable);
            }
            catch (Exception e)
            {
                string errStr = BioFailed(errorCode) ? " Some error occurred. And the last error code is " + errorCode.ToString()
                                                          : e.Message;
                Console.WriteLine(errStr);
            }
            finally
            {
                instantDiCtrl.Dispose();
                Console.ReadKey(false);
            }
        }
        static bool BioFailed(ErrorCode err)
        {
            return err < ErrorCode.Success && err >= ErrorCode.ErrorHandleNotValid;
        }
    }
}
