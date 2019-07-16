#include "shiyan.h"
#include "ui_shiyan.h"

shiyan::shiyan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shiyan)
{
    ui->setupUi(this);
}

shiyan::~shiyan()
{
    delete ui;
}
