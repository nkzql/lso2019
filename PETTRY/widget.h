#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QRectF>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QMainWindow>
#include <QImage>
#include "helpdialog.h"
#include "mainpart.h"
#include <string>
#include "dayover.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    void addTopRectF();
    void addDownRectF();
    void addLeftRectF();
    void addRightRectF();
    void deleteLastRectF();
    bool snakeStrike();
    enum Move{Left,Right,Up,Down};
protected slots:
    void timeOut();
    void rewardTimeOut();

private:
    Ui::Widget *ui;
    QList<QRectF> snake;//贪吃蛇本体
    int snakeNodeWidth = 10;
    int snakeNodeHeight = 10;
    QTimer *timer;
    QTimer *rewardTimer;
    int time = 100;
    int moveFlage = Up;
    bool gameOver = false;
    bool gameStart = false;
    QList<QRectF> rewardNode;//奖励节
};

#endif // WIDGET_H
//贪吃蛇的头文件
