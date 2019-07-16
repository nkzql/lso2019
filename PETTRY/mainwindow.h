#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "helpdialog.h"
#include "mainpart.h"
#include <string>
#include "dayover.h"
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    mainpart *new_win;




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();





private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
//最最开始的游戏界面
