#include "ai.h"

AI::AI(QObject *parent) : QObject(parent),scoreMap(20, vector<int>(20, 0))
{

}

void AI::calculateScore(vector<vector<int>> vec)
{
    int presonNum=0;//棋手方（黑棋）连续有多少个连续棋子
    int aiNum=0;//AI(白棋)连续有多少个连续的棋子


    int size=20;
    for(int row=0;row<size;row++)
    {
        for(int col=0;col<size;col++)
        {
            //对每个点计算
            if(vec[row][col]==0)
            {
                continue;
            }

            for(int y=-1;y<=1;y++)
            {
                for(int x=-1;x<1;x++)
                {
                    if(y==0&&x==0)
                    {
                        continue;
                    }

                }
            }

        }
    }


}
