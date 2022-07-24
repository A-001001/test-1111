#include "ckernel.h"

#define NetPckFunMap(a) m_netProtocalMap[a-_DEF_PROTOCAL_BASE-10]

Ckernel::Ckernel(QObject *parent) : QObject(parent)
{
    setProtocalMap();
    //初始化游戏开始界面
    m_pMainWindow=new MainWindow;
    m_pCheckerBoard=new checkerboard;
    m_pMainWindow->showNormal();
    //绑定发送本地游戏的信号和槽函数
    connect(m_pMainWindow,SIGNAL(SIG_LocalGames()),this,SLOT(slot_LocalGames()));
    //绑定发送游戏的信号和槽函数
    connect(m_pCheckerBoard,SIGNAL(SIG_win(int)),this,SLOT(slot_WinGames(int)));

}

Ckernel::~Ckernel()
{

}

void Ckernel::setProtocalMap()
{
   // memset(m_netProtocalMap,0,sizeof(m_netProtocalMap));

}

void Ckernel::slot_LocalGames()
{
    m_pMainWindow->hide();
    m_pCheckerBoard->showNormal();
}

void Ckernel::slot_WinGames(int color)
{
    if(color==1)
    {
        QMessageBox::about(m_pCheckerBoard,"WIN","黑色胜利");
    }else
    {
        QMessageBox::about(m_pCheckerBoard,"WIN","白色胜利");
    }
}


