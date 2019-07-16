#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpart.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setMinimumSize(1498, 1000); setMaximumSize(1498, 1000);
     //设置窗口的最大最小值相同，窗口大小就固定了
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   this->close();//退出游戏按钮
}

void MainWindow::on_pushButton_2_clicked()
{
    HelpDialog a;
     a.setWindowTitle("帮助");//帮助按钮
    a.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    new_win = new mainpart;
    new_win->show();
    new_win->setWindowTitle("口袋妖怪Pet！");//启动游戏按钮，呼出游戏主窗口

    this->close();
}
