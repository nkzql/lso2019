#include "dayover.h"
#include "ui_dayover.h"
#include "mainpart.h"
#include <QMovie>

dayover::dayover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dayover)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie(":/mainwindow/picture/1394241600864_middle.gif");
    ui->label_22->setMovie(movie);
    movie->start();
//动态图片显示

}


dayover::~dayover()
{
    delete ui;
}




