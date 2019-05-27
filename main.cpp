#include <QCoreApplication>

#include <iostream>
#include <QObject>
#include <QString>
#include <QTimer>
#include "ks7reader.h"

void tmot();

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer tmr;
    tmr.setInterval(1000);

    KS7Reader s7r;
    s7r.setIp("192.168.0.1");
    s7r.cnnt();



//    QObject::connect(&tmr, &QTimer::timeout, &s7r, &KS7Reader::Req, Qt::DirectConnection);
//    tmr.start();

    int i = 0;
    while (i < 100) {
        s7r.Req();
        i++;
        Sleep(1000);
    }
//    s7r.Req();
//    cout<<s7r.getCtData()<<endl;


    s7r.dis_cnnt();

    return a.exec();
}
