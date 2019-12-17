#ifndef KS7READER_H
#define KS7READER_H

#define S7_INT qint16
#define S7_DINT qint32


#include <iostream>
#include "s7_client.h"
#include <QObject>
#include <QString>
#include "m_macro.h"

using namespace std;
// PLC读取
class KS7Reader : public QObject
{
    Q_OBJECT
public:
    explicit KS7Reader(QObject *parent = nullptr);

    int cnnt(); //连接到PLC
    void dis_cnnt(); //断开连接
    void GetTempture(float (&fml_sh)[MAX_TEMP]); //返回温度数据数组
    bool isConnected(); //返回连接状态
    double m_tempreture[MAX_TEMP] = {0.0};

    void GetCpuInfo();
private:
    void KInit();
    void ReadTempture(); //从PLC读取温度
    //! 从PLC读取数据
    //! @param fml_db: 要读取的 DB编号
    //! @param fml_stIndex :索引起始地址
    //! @param fml_len: 数据字节长度
    void ReqData(int fml_db = 0, int fml_stIndex = 0, int fml_len = 4); //读取计数数据

    TSnap7Client clt; //PLC client对象

    S7_INT _temData[MAX_TEMP] = {}; //接收的温度数据，10word/20bytes
    S7_DINT _ctData[10] = {}; //接收的次数数据

    QString _ip= "192.168.0.10";
    short m_pack = 0; //机架0
    short m_slot = 1; //s7-1200 槽号1. s7-300槽号2

public:
    void setIp(QString fml_ip, short fml_slot=1);
    S7_DINT getCtData(int fml_index = 0);
signals:

public slots:
    void Req(); //查询数据
};

#endif // S7_READER_H
