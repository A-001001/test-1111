#include "ai.h"

AI::AI(QObject *parent) : QObject(parent),scoreMap(20, vector<int>(20, 0))
{

}

void AI::calculateScore(vector<vector<int>> vec)
{
    int personNum=0;//棋手方（黑棋）连续有多少个连续棋子
    int aiNum=0;//AI(白棋)连续有多少个连续的棋子
    int emptyNum=0;//该方向上空白位的个数


    int size=20;
    //对每个点进行遍历
    for(int row=0;row<size;row++)
    {
        for(int col=0;col<size;col++)
        {
            //清零
            aiNum=0;
            personNum=0;
            emptyNum=0;
            //对每个点计算

            if(vec[row][col]==0)
            {
                continue;
            }

            for(int y=-1;y<=1;y++)
            {
                for(int x=-1;x<=1;x++)
                {
                    if(y==0&&x==0)
                    {
                        continue;
                    }
                    //假设黑棋在该位置落子，会构成什么棋型
                    for(int i=1;i<=4;i++)
                    {
                        int curRow=row+i*y;//竖坐标
                        int curCol=col+i*x;//横坐标
                        //判断是否是黑棋并且是否在范围内
                        if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==1)
                        {
                            personNum++;
                        }
                        else if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==0)
                        {
                            emptyNum++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //反向继续计算
                    for(int i=1;i<=4;i++)
                    {
                        int curRow=row-i*y;//竖坐标
                        int curCol=col-i*x;//横坐标
                        //判断是否是黑棋并且是否在范围内
                        if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==1)
                        {
                            personNum++;
                        }
                        else if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==0)
                        {
                            emptyNum++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if(personNum==1)//连2
                    {
                        scoreMap[row][col]+=10;
                    }
                    else if(personNum==2)//判断三联
                    {
                        if(emptyNum==1)//死三
                        {
                            scoreMap[row][col]+=30;
                        }
                        else if(emptyNum==2)//活三
                        {
                            scoreMap[row][col]+=40;
                        }
                    }
                    else if(personNum==3)//判断四联
                    {
                        if(emptyNum==1)//死四
                        {
                            scoreMap[row][col]+=60;
                        }
                        else if(emptyNum==2)//活四
                        {
                            scoreMap[row][col]+=200;
                        }
                    }
                    else if(personNum==4)//p判断五连
                    {
                        scoreMap[row][col]=20000;
                    }

                    //假设白棋在该位置落子，会构成
                    emptyNum=0;
                    //假设白棋落子会构成什么棋型
                    for(int i=0;i<=4;i++)
                    {
                        int curRow=row+i*y;
                        int curCol=col+i*x;

                        if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==2)
                        {
                            aiNum++;
                        }
                        else if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==0)
                        {
                            emptyNum++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }


                    //反向继续计算
                    for(int i=1;i<=4;i++)
                    {
                        int curRow=row-i*y;//竖坐标
                        int curCol=col-i*x;//横坐标
                        //判断是否是黑棋并且是否在范围内
                        if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==2)
                        {
                            aiNum++;
                        }
                        else if(curRow>=0&&curRow<size&&curCol>=0&&curCol<size&&vec[curRow][curCol]==0)
                        {
                            emptyNum++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }

                    //白棋评分
                    if(aiNum==0)//什么都没有全是空位
                    {
                        scoreMap[row][col]+=5;

                    }
                    else if(aiNum==1)
                    {
                        scoreMap[row][col]+=10;
                    }
                    else if(aiNum==2)//判断三联
                    {
                        if(emptyNum==1)//死三
                        {
                            scoreMap[row][col]+=25;
                        }
                        else if(emptyNum==2)//活三
                        {
                            scoreMap[row][col]+=50;
                        }
                    }
                    else if(aiNum==3)//判断四联
                    {
                        if(emptyNum==1)//死四
                        {
                            scoreMap[row][col]+=60;
                        }
                        else if(emptyNum==2)//活四
                        {
                            scoreMap[row][col]+=10000;
                        }
                    }
                    else if(aiNum>=4)//p判断五连
                    {
                        scoreMap[row][col]=30000;
                    }

                }
            }

        }
    }


}
