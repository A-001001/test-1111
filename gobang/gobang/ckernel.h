#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include"packdef.h"
#include"mainwindow.h"
#include"checkerboard.h"
#include"QMessageBox"


//class CKernel;//声明有CKernel这个类，然后在定义这个类，否则就会陷入定义映射表没有类，先定义类没有映射表的循环
//typedef void(CKernel::*FUN)(long ISendIp, char *buf, int nLen);

class Ckernel : public QObject
{
    Q_OBJECT
public:
    explicit Ckernel(QObject *parent = 0);
    ~Ckernel();
    //初始化协议映射表
    void setProtocalMap();
signals:


public slots:
    //点击本地游戏按钮的处理函数
    void slot_LocalGames();
    //胜利信号传递
    void slot_WinGames(int color);
private:
    //协议映射表，协议头映射处理函数
    //FUN m_netProtocalMap[_DEF_PROTOCAL_COUNT];
    //登录注册界面对象；
    MainWindow* m_pMainWindow;
    checkerboard*m_pCheckerBoard;
};

#endif // CKERNEL_H
