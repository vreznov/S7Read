#include "ks7reader.h"

enum class reg_type //寄存器类型
{
    mBit = 0x01,
    mByte = 0x02,
    mWord = 0x04,
    mDouble = 0x06
};

KS7Reader::KS7Reader(QObject *parent) : QObject(parent)
{
    KInit();
}

int KS7Reader::cnnt()
{
    int ret = clt.ConnectTo(_ip.toStdString().c_str(), m_pack, m_slot);

    return ret;
}

void KS7Reader::dis_cnnt()
{
    if(isConnected())
    {
        clt.Disconnect();
    }
}

/* get_tempture 获取温度数据
 * <fml_sh> 要返回写入的数组，因为返回只能用指针，但是形参可以用数组并且限制大小
 * */
void KS7Reader::GetTempture(float (&fml_sh)[MAX_TEMP])
{
    Q_UNUSED(fml_sh)
    // 直接拷贝即可，连续内存组成连续的数据
//    ushort temp[MAX_TEMP] = {0.0};
//    memcpy(temp, m_data, sizeof(temp));

//    for(int i=0;i<MAX_TEMP;i++)
//    {
//        fml_sh[i] = temp[i] / 1000.0f;
//    }
}

void KS7Reader::KInit()
{

}

void KS7Reader::Req()
{
//    ReadTempture();
    ReqData(2, 0, 8);
}

void KS7Reader::ReadTempture()
{
    if(isConnected())
    {
        // 从DB2读取10个word
        memset(_temData, 0, sizeof(_temData));
        int ret = clt.DBRead(2, 0, 2*10, _temData);

        quint8 temp[MAX_TEMP*2] = {0};
        memcpy(temp, _temData, sizeof(_temData));
        //读取的数据需要进行高低位互换
        if(!ret)
        {
            for(int i=0;i<MAX_TEMP;i++)
            {
                quint16 hbyte = ((quint16)temp[i*2])<<8;
                quint16 lbyte = (quint16)temp[i*2+1];
                m_tempreture[i] = (hbyte + lbyte) / 10.0;
            }
        }
    }
}

void KS7Reader::ReqData(int fml_db, int fml_stIndex, int fml_len)
{

    memset(_ctData, 0, sizeof(_ctData));
//    int ret = clt.DBRead(23, 0, 4, _ctData);
    int ret = clt.DBRead(fml_db, fml_stIndex, fml_len, _ctData);
    if(ret != 0)
    {
        cout<<"read error"<<endl;
    }
    else
    {
        quint8 temp[40] = {0};
        memcpy(temp, _ctData, sizeof(_ctData));
        //读取的数据需要进行高低位互换
        if(!ret)
        {
            for(int i=0;i<10;i++)
            {
                S7_DINT byte1 = ((S7_DINT)temp[i*4])<<24;
                S7_DINT byte2 = (S7_DINT)temp[i*4+1]<<16;
                S7_DINT byte3 = ((S7_DINT)temp[i*4+2])<<8;
                S7_DINT byte4 = (S7_DINT)temp[i*4+3];
                _ctData[i] = byte1 + byte2 + byte3 + byte4;
            }
        }
        cout<<"read val: "<<_ctData[0]<<endl;
//        printf("read val is: %08x\r\n", _ctData[0]);
    }
}


void KS7Reader::GetCpuInfo()
{
    TS7CpuInfo cinfo = {};
    int ret = clt.GetCpuInfo(&cinfo);
    mc<<"readccpu info"<<ret<<me;
}

void KS7Reader::setIp(QString fml_ip, short fml_slot)
{
    _ip = fml_ip;
    m_slot = fml_slot;
}

qint32 KS7Reader::getCtData(int fml_index)
{
    return _ctData[fml_index];
}

bool KS7Reader::isConnected()
{
    return clt.Connected;
}

