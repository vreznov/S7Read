#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    KInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::KInit()
{
    tmr.setInterval(200);
    s7r.setIp("192.168.0.202");
    connect(&tmr, &QTimer::timeout, &s7r, &KS7Reader::Req);
    connect(&tmr, &QTimer::timeout, this, &MainWindow::refresh);

}

void MainWindow::on_pushButton_clicked()
{
    s7r.setIp(ui->lineEdit_3->text(), ui->lineEdit->text().toShort());
    int ret = s7r.cnnt();
    if(!ret)
        tmr.start();
    else
    {
        QMessageBox::information(this, "错误", "连接PLC出错");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    tmr.stop();
    s7r.dis_cnnt();
}

void MainWindow::refresh()
{
    ui->lcdNumber->display(s7r.getCtData(0));
    ui->lcdNumber_2->display(s7r.getCtData(1) / 10.0);
}
