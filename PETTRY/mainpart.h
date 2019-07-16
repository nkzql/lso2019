#ifndef MAINPART_H
#define MAINPART_H

#include <QMainWindow>
#include <QPixmap>
#include <QTime>
#include <QObject>
#include "helpdialog.h"
#include "caiquan.h"
#include "widget.h"
#include "end.h"
#include <QMovie>  //动图

extern int heart;  //行动点数，extern是全局变量的一种方式
extern QString chengjiu;  //字符串类型的“成就”变量
extern int mark;          //最后结算页面写的分数
extern int z;              //后续用来判断事件框内信息是否重复显示的变量
extern int fighter;        //武力值
class Widget;
namespace Ui {
class mainpart;
}

class mainpart : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpart(QWidget *parent = nullptr);
    ~mainpart();
      int day=60,IQ=50,health=50,mental=50,qinmidu=50;

      QString mood="在发呆";
      void shuaxin();
      int changeday();
      void dowhat();
      void caiquans();
      void fadai();
      void baoda();
      void shopping();
      QString xinqing();//心情字符串
      QString jiankang();//健康字符串
      QString qinmi();//亲密度字符串
      void gameover();
      Widget *new_win1;
      end *new_win2;



private slots:
      void on_pushButton_3_clicked();


      void on_pushButton_7_clicked();

      void on_pushButton_5_clicked();

      void on_pushButton_clicked();

      void on_pushButton_2_clicked();

      void on_pushButton_6_clicked();

      void on_pushButton_4_clicked();

private:
    Ui::mainpart *ui;
};


#endif // MAINPART_H
