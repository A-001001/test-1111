#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    //发送按钮按下信号给ckernel
     void SIG_LocalGames();
private slots:
    //本地游戏按钮按下操作
    void on_m_pButton_1_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
