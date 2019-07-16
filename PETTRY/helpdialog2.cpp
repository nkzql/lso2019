#include "helpdialog2.h"
#include "ui_helpdialog2.h"

helpdialog2::helpdialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpdialog2)
{
    ui->setupUi(this);
}

helpdialog2::~helpdialog2()
{
    delete ui;
}

void helpdialog2::on_pushButton_clicked()
{
    this->close();
}
