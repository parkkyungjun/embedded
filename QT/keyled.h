#ifndef KEYLED_H
#define KEYLED_H
/* kccistc embedded & iot by ksh */
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QSocketNotifier>

class Keyled : public QWidget
{
    Q_OBJECT
public:
    explicit Keyled(QWidget *parent = 0);
    ~Keyled();

private:
    int keyledFd;
    QSocketNotifier* pKeyledNotifier;
    QFile* pFile;

signals:
  void updateKeydataSig(int);

public slots:
    void readKeyData(int);
    void writeLedData(int);
};

#endif // KEYLEDCLASS_H
