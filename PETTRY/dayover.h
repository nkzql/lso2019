#ifndef DAYOVER_H
#define DAYOVER_H

#include <QDialog>
#include <QPushButton>
#include "mainpart.h"
namespace Ui {
class dayover;
}

class dayover : public QDialog
{
    Q_OBJECT

public:
    explicit dayover(QWidget *parent = nullptr);
    ~dayover();




private slots:


private:
    Ui::dayover *ui;
};
class untitled:public QObject
 {
    Q_OBJECT
   public:
    untitled();
    void heartshuaxin();
signals:
    void signal1();
   };

#endif // DAYOVER_H
//每天结束后的提示框
