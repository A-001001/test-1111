#include "checkerboard.h"
#include "ui_checkerboard.h"
#include<QPainter>
#include <QMouseEvent>
//图片类文件
#include<QPixmap>//QPixmap继承了QPaintDevice,指令主要功能是针对屏幕优化的图片，如背景图
#include<QBitmap>//QBitmap继承自QPixmap
#include<QImage>//提供像素级别的操作

checkerboard::checkerboard(QWidget *parent) :
    QWidget(parent),vec(size1, vector<int>(size2, 0)),
    ui(new Ui::checkerboard)
{
    ui->setupUi(this);
    chessX = -1;
    chessY = -1;

}

checkerboard::~checkerboard()
{
    delete ui;
}

void checkerboard::paintEvent(QPaintEvent *event)
{
    gridW = (width()-350) / 20;		//窗口宽度分20份
    gridH = (height()-50) / 20;		//窗口高低分20份

    startX = gridW;
    startY = gridH;

    QPainter p(this);

    QPixmap pix;

    //加载背景图片的像素图
    pix.load(":/res/BackGround1.png");

    //绘制背景图自适应扩大
    p.drawPixmap(0,0, this->width(), this->height(),pix);		//设置背景图

    QPen pen;
    pen.setWidth(4);		//设置线宽
    p.setPen(pen);

    for (int i = 0; i < 20; ++i)
    {
        p.drawLine(startX, startY + i * gridH, gridW * 19 + startX, startY + i * gridH);		//画横线
        p.drawLine(startX + gridW * i, startY, startX + i * gridW, startY + gridH * 19);
    }
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(vec[i][j]==1)
            {
                //加载黑棋棋子图片的像素图
                pix.load(":/res/kuro.png");
                //将其画在棋盘上
                p.drawPixmap(startX-25 + j*gridW, startY-25 + i * gridH, gridW, gridH,pix);
            }
            if(vec[i][j]==2)
            {
                //加载黑棋棋子图片的像素图
                pix.load(":/res/shiro.png");
                //将其画在棋盘上
                p.drawPixmap(startX-25 + j*gridW, startY-25 + i * gridH, gridW, gridH,pix);
            }
        }
    }

    if (chessX != -1 && chessY != -1&&who==1)
    {

        if(vec[chessY][chessX]==0)
        {
            //加载黑棋棋子图片的像素图
            pix.load(":/res/kuro.png");
            //将其画在棋盘上
            p.drawPixmap(startX-25 + chessX*gridW, startY-25 + chessY * gridH, gridW, gridH,pix);
            vec[chessY][chessX]=who;
            win(chessX,chessY,who);
        }
        else
        {
            who--;
        }
        who++;
    }
    else if (chessX != -1 && chessY != -1&&who==2)
    {

        if(vec[chessY][chessX]==0)
        {
            //加载白棋棋子图片的像素图
            pix.load(":/res/shiro.png");
            //将其画在棋盘上
            p.drawPixmap(startX-25 + chessX*gridW, startY-25 + chessY * gridH, gridW, gridH,pix);
            vec[chessY][chessX]=who;
            win(chessX,chessY,who);
        }
        else
        {
            who++;
        }
        who--;
    }




}

void checkerboard::mousePressEvent(QMouseEvent *event)
{
    //获取点击的坐标
    int x = event->x();
    int y = event->y();




    //要保证点击在棋盘里
    if (x >= startX && x <= startX + 19 * gridW&& y >= startY && y <= startY + 19 * gridH)
    {
        //棋盘的位置转换成坐标下标值
        chessX = (x - startX+25) / gridW;
        chessY = (y - startY+25) / gridH;

        //更新窗口，间接调用 paintEvent() 函数
        update();
    }


}

void checkerboard::win(int x, int y,int color)
{
    //横向判断是否胜利
    if(Hwin(x,y))
    {

        Q_EMIT SIG_win(color);
    }
    //纵向判断是否胜利
    if(Zwin(x,y))
    {

        Q_EMIT SIG_win(color);
    }
    //左斜判断是否胜利
    if(Zxwin(x,y))
    {

        Q_EMIT SIG_win(color);
    }
    //右斜判断是否胜利
    if(Yxwin(x,y))
    {

        Q_EMIT SIG_win(color);
    }
}
//横向判断
bool checkerboard::Hwin(int x,int y)
{
    int sucess=1;
    int color=vec[y][x];
    int h=0;
    int i,j;
    i=x-1;
    j=x+1;
    while(1)
    {
        if(i>=0&&vec[y][i]==color)
        {

            sucess++;
            i--;
            h=-1;

        }
        h++;
        if(j<20&&vec[y][j]==color)
        {

            sucess++;
            j++;
            h=-1;
        }
        h++;
        if(sucess>4)
        {
            break;
        }
        if(h>=2)
        {
            return false;
        }
    }
    return true;
}
//纵向判断
bool checkerboard::Zwin(int x, int y)
{
    int sucess=1;
    int color=vec[y][x];
    int h=0;
    int i,j;
    i=y-1;
    j=y+1;
    while(1)
    {
        if(i>=0&&vec[i][x]==color)
        {

            sucess++;
            i--;
            h=-1;

        }
        h++;
        if(j<20&&vec[j][x]==color)
        {

            sucess++;
            j++;
            h=-1;
        }
        h++;
        if(sucess>4)
        {
            break;
        }
        if(h>=2)
        {
            return false;
        }
    }
    return true;
}
//判断左斜
bool checkerboard::Zxwin(int x, int y)
{
    int sucess=1;
    int color=vec[y][x];
    int h=0;
    int i1,i2,j1,j2;
    i1=y-1;
    i2=x-1;
    j1=y+1;
    j2=x+1;
    while(1)
    {
        if(i1>=0&&i2>=0&&vec[i1][i2]==color)
        {

            sucess++;
            i1--;
            i2--;
            h=-1;

        }
        h++;
        if(j1<20&&j2<20&&vec[j1][j2]==color)
        {

            sucess++;
            j1++;
            j2++;
            h=-1;
        }
        h++;
        if(sucess>4)
        {
            break;
        }
        if(h>=2)
        {
            return false;
        }
    }
    return true;
}
//判断右斜
bool checkerboard::Yxwin(int x, int y)
{
    int sucess=1;
    int color=vec[y][x];
    int h=0;
    int i1,i2,j1,j2;
    i1=y-1;
    i2=x+1;
    j1=y+1;
    j2=x-1;
    while(1)
    {
        if(i1>=0&&i2>=0&&vec[i1][i2]==color)
        {

            sucess++;
            i1--;
            i2++;
            h=-1;

        }
        h++;
        if(j1<20&&j2<20&&vec[j1][j2]==color)
        {

            sucess++;
            j1++;
            j2--;
            h=-1;
        }
        h++;
        if(sucess>4)
        {
            break;
        }
        if(h>=2)
        {
            return false;
        }
    }
    return true;
}



