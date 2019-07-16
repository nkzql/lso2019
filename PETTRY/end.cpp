#include "end.h"
#include "ui_end.h"
#include "mainpart.h"

end::end(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
    QFont ft1;
    ft1.setPointSize(30);
    QFont ft3;
        ft3.setPointSize(70);
        //设置字体大小样式
    ui->label_2->setFont(ft1);
    ui->label_2->setText(chengjiu);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::blue);
    //↑设置字体颜色样式
    ui->label_4->setPalette(pe);
    ui->label_4->setFont(ft3);
    QString markstring = QString::number(mark);//转为字符串
    ui->label_4->setText(markstring);
    //↑结算界面显示的各个元素↑
}

end::~end()
{
    delete ui;
}
