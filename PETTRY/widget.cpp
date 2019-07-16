#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpart.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(480,500);

        setStyleSheet("QWidget{background:black}");
        setWindowOpacity(0.8);//窗口透明度

        snake.append(QRectF(200,500,snakeNodeWidth,snakeNodeHeight));
        addTopRectF();
        addTopRectF();

        rewardNode.append(QRectF(100,100,snakeNodeWidth,snakeNodeWidth));

        timer = new QTimer;
        connect(timer, SIGNAL(timeout()),this,SLOT(timeOut()));
        //timer->start(time);

        rewardTimer = new QTimer;
        connect(rewardTimer,SIGNAL(timeout()),this,SLOT(rewardTimeOut()));
        //rewardTimer->start(time*30);

 }

Widget::~Widget()
{
    delete ui;
}
//贪吃蛇的主函数
