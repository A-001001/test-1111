#ifndef AI_H
#define AI_H

#include <QObject>
#include"checkerboard.h"

class AI : public QObject
{
    Q_OBJECT
public:
    explicit AI(QObject *parent = 0);

private:
    void calculateScore(vector<vector<int>> vec);
signals:

public slots:

private:

    vector<vector<int>> scoreMap;
    //定义窗口类

    checkerboard*che;
};

#endif // AI_H
