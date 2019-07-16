#ifndef CAIQUAN_H
#define CAIQUAN_H

#include <QDialog>

namespace Ui {
class caiquan;
}

class caiquan : public QDialog
{
    Q_OBJECT

public:
    explicit caiquan(QWidget *parent = nullptr);
    ~caiquan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
//猜拳的三个按钮槽
private:
    Ui::caiquan *ui;
};

#endif // CAIQUAN_H
//猜拳的头文件
