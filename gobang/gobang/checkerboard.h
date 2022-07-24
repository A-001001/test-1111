#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

#include <QWidget>
#include<vector>
using namespace std;

namespace Ui {
class checkerboard;
}

class checkerboard : public QWidget
{
    Q_OBJECT

public:
    explicit checkerboard(QWidget *parent = 0);
    ~checkerboard();
signals:
    void SIG_win(int color);
protected:
    //重绘背景以及棋子事件
    void paintEvent(QPaintEvent *event);
    //捕捉鼠标落点
    void mousePressEvent(QMouseEvent *event);
    //判断总胜负
    void win(int x,int y,int color);
    //判断横胜负
    bool Hwin(int x,int y);
    //判断纵胜负
    bool Zwin(int x,int y);
    //判断左斜胜负
    bool Zxwin(int x,int y);
    //判断右鞋胜负
    bool Yxwin(int x,int y);
private:
    Ui::checkerboard *ui;

    int gridW;		//格子的宽度
    int gridH;		//格子的高度
    int startX;		//起始横坐标
    int startY;		//起始纵坐标

    int chessX, chessY;	//棋盘下标
    int size1=20;
    int size2=20;

    vector<vector<int>> vec;
    int who=1;//0为没下棋，1为黑棋，2为白棋
};

#endif // CHECKERBOARD_H
