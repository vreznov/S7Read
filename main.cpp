#include <QApplication>

#include <iostream>
#include <QObject>
#include <QString>
#include <QTimer>
#include "m_macro.h"
#include "mainwindow.h"

void tmot();

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mw;
    mw.show();

//    QTimer tmr;
//    tmr.setInterval(1000);

//    KS7Reader s7r;
//    s7r.setIp("192.168.0.40");
//    s7r.cnnt();

//    s7r.GetCpuInfo();


//    int i = 0;
//    while (i < 500) {
//        mc<<i<<"  ";
//        s7r.Req();
//        i++;
//        Sleep(1000);
//    }


//    s7r.dis_cnnt();

    return a.exec();
}
