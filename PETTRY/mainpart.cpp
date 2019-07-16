#include "mainpart.h"
#include "ui_mainpart.h"
#include "dayover.h"
#include "helpdialog2.h"
int heart;
QString chengjiu;
int mark;
int z=1;
int fighter=50;

mainpart::mainpart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpart)
{
    ui->setupUi(this);
    setMinimumSize(750,900); setMaximumSize(750,900);
    QFont ft;
    ft.setPointSize(16);

    QString daystring = QString::number(day);//转为字符串
    ui->label->setScaledContents(true);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->label_3->setPalette(pe);
    ui->label_3->setText(daystring);
    ui->label_3->setFont(ft);
    ui->label_7->setFont(ft);
    ui->label_7->setText(mood);
    QFont ft1;
    ft1.setPointSize(14);
    ui->label_10->setFont(ft1);
    ui->label_10->setText("3");
    heart=3;
    ui->label_13->setFont(ft);
    ui->label_13->setText(xinqing());
    ui->label_15->setFont(ft);
    ui->label_15->setText(jiankang());
    ui->label_18->setFont(ft);
    ui->label_18->setText("没有什么事发生~");
    ui->label_19->setFont(ft);
    ui->label_19->setText("pika~pika~");
    ui->label_21->setFont(ft);
    ui->label_21->setText(qinmi());
    ui->label->setScaledContents(true);
        QMovie *movie = new QMovie(":/mainwindow/picture/1394241600864_middle.gif");
        ui->label_22->setMovie(movie);
        movie->start();
        //↑界面各个元素的显示
}


mainpart::~mainpart()
{
    delete ui;
}

QString mainpart::xinqing()//心情字符串跟随mental值更改
{
    if(mental<=20)
       return "绝望";
    else if(mental<=40)
       return "伤心";
    else if(mental>=40&&mental<50)
       return "失落";
    else if(mental==50)
       return "一般般";
    else if(mental<=60&&mental>50)
       return "开心";
    else if(mental<=80&&mental>60)
       return "快乐";
    else if(mental>=80)
       return "幸福";
 };
QString mainpart::jiankang()//健康字符串
{
    if(health<=20)
       return "垂危";
    else if(health<=40)
       return "重病";
    else if(health>=40&&health<50)
       return "不适";
    else if(health==50)
       return "正常";
    else if(health<=60&&health>50)
       return "舒服";
    else if(health<=80&&health>60)
       return "健康";
    else if(health>=80)
       return "超神";
 };
QString mainpart::qinmi()//亲密度字符串
{
    if(qinmidu<=20)
       return "出走";
    else if(qinmidu<=40)
       return "疏远";
    else if(qinmidu>=40&&health<50)
       return "凑合";
    else if(qinmidu==50)
       return "一般";
    else if(qinmidu<=60&&health>50)
       return "良好";
    else if(qinmidu<=80&&health>60)
       return "亲昵";
    else if(qinmidu>=80)
       return "满贯";
 };
void mainpart::gameover()//判断游戏结束，游戏结束时生成成就
{   int i=1,j=0,l=1,c=0;
    int a[5]={health,mental,qinmidu,IQ,fighter};
    if(day<=0)
   {
    for(i=0;i<=4;i++)
        {
           for(j=0;j<=4;j++)
           {
               if(a[i]<a[j])
               {l=0;}

           }
           if(l==1)
           {c=i;}
           else {
               l=1;
           }
        }

    switch(c+1)
    {
    case 1:
        chengjiu="累死皮卡丘（运动成就）";
        mark=health;
        break;
    case 2:
        chengjiu="沟通大师（心理成就）";
        mark=mental;
        break;
    case 3:
        chengjiu="羁绊大师（亲密度成就）";
        mark=qinmidu;
        break;
    case 4:
        chengjiu="教育大家（IQ成就）";
        mark=IQ;
        break;
    case 5:
        chengjiu="杰尼龟杀手（武力值成就）";
        mark=fighter;
        break;
    }
    //↑判断出最终成就
    this->close();//关闭游戏窗口
    new_win2 = new end;
    new_win2->show();
    new_win2->setWindowTitle("GAME OVER");
    //打开结算窗口
    }
 }
void mainpart::on_pushButton_3_clicked()//按下“皮卡丘在做什么按钮”
{
    int i=0;
    heart--;
    i=changeday();//进入“changeday”函数判断，并将返回值赋给i
    if(i==1)
    {
        dowhat();
        shuaxin();//为真启动“干什么函数”和“界面刷新函数”
    }
}

void mainpart::shuaxin()//界面刷新函数
{
        QString heartstring = QString::number(heart);
        ui->label_10->setText(heartstring);
        ui->label_13->setText(xinqing());
        ui->label_15->setText(jiankang());
        ui->label_21->setText(qinmi());
        gameover();//刷新过后还会进入判断游戏是否结束的函数

}
int mainpart::changeday()//更换日期函数
{
    if(heart==-1)//该换日期
    {
        day--;
         heart=3;
         dayover a;
          a.setWindowTitle("事件？？");//呼出一天结束的窗口
          a.exec();
         QString heartstring = QString::number(heart);
         ui->label_10->setText(heartstring);
        QString daystring = QString::number(day);
        ui->label_3->setText(daystring);
        return 0;
    }
    else {
        return 1;//无需更换日期
    }
}
void mainpart::dowhat()//“做什么”函数
{   ui->label_19->setText("观察ing");
    ui->label_18->setText("pika~pika~");
    qsrand(time(nullptr));//生成16以内随机数
    int n = qrand() %16;
    if(z!=n)
    z=n;
    else {
        n++;
      z=n;
    }
    switch(n)
    {
    case 0:
        mood="嗯，在发呆呢";
        break;
    case 1:
        mood="嗯，在盯着你看";
        break;
    case 2:
        mood="嗯，在玩小jiojio";
        break;
    case 3:
        mood="嗯，在跟杰尼龟打招呼^_^";
        break;
    case 4:
        mood="嗯，在偷吃饭团(#^.^#)";
        break;
    case 5:
        mood="嗯，在四处张望";
        break;
    case 6:
        mood="嗯，在四处奔跑O(∩_∩)O";
        break;
    case 7:
        mood="嗯，在玩手机？？？^_^";
        break;
    case 8:
        mood="在翻看精灵图鉴";
        break;
    case 9:
        mood="在睡觉哦Zzzz";
        break;
    case 10:
        mood="在模仿《大侦探皮卡丘》？！";
        break;
    case 11:
        mood="在追逐蝴蝶！O(∩_∩)O";
        break;
    case 12:
        mood="在找藏起来的零食(╥﹏╥)";
        break;
    case 13:
        mood="很想玩贪吃蛇╮(╯▽╰)╭";
        break;
    case 14:
        mood="在摸你的头";
        break;
    case 15:
        mood="在讨表扬O(∩_∩)O";
        break;
    }
    ui->label_7->setText(mood);
    mental+=1;
    IQ+=0;
    qinmidu+=+3;
    health+=0;
    fighter+=-1;//对的数值影响
 }



void mainpart::on_pushButton_7_clicked()//按下帮助按钮
{
    helpdialog2 b;
     b.setWindowTitle("游戏帮助");//呼出帮助窗口
    b.exec();
}

void mainpart::on_pushButton_5_clicked()//猜拳，与之前的dowhat大体相同
{

        int i=0;
        heart--;
        i=changeday();
        if(i==1)
        {
            caiquans();
            shuaxin();
        }


}
void mainpart::caiquans()
{
            caiquan a;
            a.setWindowTitle("来猜拳！");
            a.exec();
            ui->label_19->setText("一起来猜拳！");
            qsrand(time(NULL));
            int n = qrand() % 2;
            if(n==1)
            {ui->label_18->setText("猜拳胜利！");}
            else
             {ui->label_18->setText("猜拳失败...");}
            mental+=0;
            IQ+=1;
            qinmidu+=1;
            health+=0;
            fighter+=0;
}

void mainpart::on_pushButton_clicked()//发呆，与之前的dowhat大体相同
{
    int i=0;
    heart--;
    i=changeday();
    if(i==1)
    {
        fadai();
        shuaxin();
    }

}
void mainpart::fadai()
{    ui->label_19->setText("一起发呆~");
     qsrand(time(NULL));

     int n = qrand() % 12;
      if(z!=n)
      z=n;
      else {
          n++;
        z=n;
      }
      switch(n)
      {
      case 0:
         ui->label_18->setText("睡着了Zzzz");
          break;
      case 1:
          ui->label_18->setText("发呆了2个小时...");
          break;
      case 2:
          ui->label_18->setText("算了我还有QT作业");
          break;
      case 3:
          ui->label_18->setText("发呆比赛获胜？！");
          break;
      case 4:
          ui->label_18->setText("发呆了10个小时...");
          break;
      case 5:
          ui->label_18->setText("偷偷做个鬼脸");
          break;
      case 6:
          ui->label_18->setText("真无聊");
          break;
      case 7:
          ui->label_18->setText("发呆的时候突然放电");
          break;
      case 8:
          ui->label_18->setText("怕不是养了只呆子");
          break;
      case 9:
          ui->label_18->setText("一起发呆感觉还不错");
          break;
      case 10:
          ui->label_18->setText("哦我是有作业的人");
          break;
      case 11:
          ui->label_18->setText("还是玩游戏去吧...");
          break;
        }
       mental+=-2;
       IQ+=1;
       qinmidu+=0;
       health+=0;
       fighter+=-1;

}
void mainpart::on_pushButton_2_clicked()//打杰尼龟，与之前的dowhat大体相同
{
    int i=0;
    heart--;
    i=changeday();
    if(i==1)
    {
        baoda();
        shuaxin();
    }
}
void mainpart::baoda()
{
        ui->label_19->setText("今日份暴打！");
         qsrand(time(NULL));
         int n = qrand() % 19;
         if(z!=n)
         z=n;
         else {
             n++;
           z=n;
         }
          switch(n)
          {
          case 0:
             ui->label_18->setText("光之壁！！！");
              break;
          case 1:
              ui->label_18->setText("被杰尼龟反杀...");
              break;
          case 2:
              ui->label_18->setText("百万拳击！！");
              break;
          case 3:
              ui->label_18->setText("今天的杰尼龟不禁打");
              break;
          case 4:
              ui->label_18->setText("十万伏特！");
              break;
          case 5:
             ui->label_18->setText("居合斩！（误）");
              break;
          case 6:
              ui->label_18->setText("效果拔群！");
              break;
          case 7:
              ui->label_18->setText("引来记者拍照");
              break;
          case 8:
              ui->label_18->setText("皮卡丘还会地球上投？？");
              break;
          case 9:
              ui->label_18->setText("今夜我们都是杰尼龟");
              break;
          case 10:
             ui->label_18->setText("电光石火！");
              break;
          case 11:
              ui->label_18->setText("尾巴铁刃！");
              break;
          case 12:
              ui->label_18->setText("杰尼龟使用了刀背打！");
              break;
          case 13:
              ui->label_18->setText("杰尼龟不省人事...");
              break;
          case 14:
              ui->label_18->setText("我提前拨打了120");
              break;
          case 15:
              ui->label_18->setText("杰尼龟使用了高压水枪");
              break;
          case 16:
              ui->label_18->setText("杰尼龟使用了破坏死光？？");
              break;
          case 17:
              ui->label_18->setText("落雷！！");
              break;
          case 18:
              ui->label_18->setText("杰尼龟使用了火箭头槌");
              break;
            }
          mental+=1;
          IQ+=-2;
          qinmidu+=1;
          health+=1;
          fighter+=3;

}


void mainpart::on_pushButton_6_clicked()//逛商场，与之前的dowhat大体相同
{
    int i=0;
    heart--;
    i=changeday();
    if(i==1)
    {
        shopping();
        shuaxin();
    }
}
void mainpart::shopping()
{   ui->label_19->setText("逛商场ing");
    qsrand(time(NULL));
    int n = qrand() %16;
    if(z!=n)
    z=n;
    else {
        n++;
      z=n;
    }
    switch(n)
    {
    case 0:
        ui->label_18->setText("被杰尼龟一家指责(╥﹏╥)");
        mental+=-6;
        break;
    case 1:
        ui->label_18->setText("吃了好多垃圾食品");
        health-=5;
        break;
    case 2:
        ui->label_18->setText("吃了好多健康食品");
        health+=8;
        break;
    case 3:
        ui->label_18->setText("买到了有用的东西");
        mental+=6;
        break;
    case 4:
        ui->label_18->setText("看电影！！！");
        mental+=5;
        break;
    case 5:
        ui->label_18->setText("皮卡丘还能放我鸽子？");
        qinmidu-=10;
        break;
    case 6:
        ui->label_18->setText("十万伏特点燃全场");
        mental+=-3;
        IQ+=-3;
        qinmidu+=-3;
        health+=-3;
        fighter+=-3;
        break;
    case 7:
        ui->label_18->setText("LOL水友赛，丢人现眼");
        qinmidu+=8;
        IQ+=-3;
        break;
    case 8:
        ui->label_18->setText("吃海底捞");
        mental+=10;
        break;
    case 9:
        ui->label_18->setText("皮卡丘走丢了");
        qinmidu+=6;
        mental+=-8;
        break;
    case 10:
        ui->label_18->setText("一起打电动！");
        health+=-5;
        mental+=8;
        fighter+=8;
        break;
    case 11:
        ui->label_18->setText("买口袋妖怪饭团");
        health+=8;
        mental+=3;
        break;
    case 12:
        ui->label_18->setText("转账多摁了个0");
        mental-=5;
        qinmidu-=5;
        break;
    case 13:
        ui->label_18->setText("支付宝你扫我我扫你？");
        IQ+=25;
        break;
    case 14:
        ui->label_18->setText("LOL水友赛打出4396");
        IQ-=7;
        break;
    case 15:
        ui->label_18->setText("杰尼龟“请客”");
        mental-=3;
        fighter+=10;
        break;
    }
}


void mainpart::on_pushButton_4_clicked()//玩贪吃蛇
{   new_win1 = new Widget;
    new_win1->show();
    new_win1->setWindowTitle("空格开始，方向键操控");//打开贪吃蛇窗口
    day--;
     heart=3;
     dayover a;
      a.setWindowTitle("事件？？");
      a.exec();
     QString heartstring = QString::number(heart);
     ui->label_10->setText(heartstring);
    QString daystring = QString::number(day);
    ui->label_3->setText(daystring);
    IQ+=5;mental+=5;health-=5;qinmidu+=1;fighter-=5;
}
