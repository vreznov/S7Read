#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "ks7reader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void KInit();
    QTimer tmr;
    KS7Reader s7r;


private slots:
    void on_pushButton_clicked();  //开始

    void on_pushButton_2_clicked();  //停止

    void refresh();  //刷新界面数据显示

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
