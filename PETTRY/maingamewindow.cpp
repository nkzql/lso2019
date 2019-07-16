#include "maingame.h"
#include "ui_maingame.h"

maingame::maingame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maingame)
{
    ui->setupUi(this);
    resize(192,500);

}

maingame::~maingame()
{
    delete ui;
}
