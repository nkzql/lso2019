#include "caiquan.h"
#include "ui_caiquan.h"

caiquan::caiquan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::caiquan)
{
    ui->setupUi(this);
}

caiquan::~caiquan()
{
    delete ui;
}

void caiquan::on_pushButton_clicked()
{
    this->close();
}

void caiquan::on_pushButton_2_clicked()
{
    this->close();
}

void caiquan::on_pushButton_3_clicked()
{
    this->close();
}
//三个按钮按下后都是关闭窗口
