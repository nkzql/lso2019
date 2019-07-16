#ifndef HELPDIALOG2_H
#define HELPDIALOG2_H

#include <QDialog>

namespace Ui {
class helpdialog2;
}

class helpdialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit helpdialog2(QWidget *parent = nullptr);
    ~helpdialog2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::helpdialog2 *ui;
};

#endif // HELPDIALOG2_H
