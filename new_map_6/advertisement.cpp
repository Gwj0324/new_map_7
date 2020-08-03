#include "advertisement.h"
#include "ui_advertisement.h"
#include<QGraphicsDropShadowEffect>
#include<QDebug>
#include<QDesktopWidget>
#include<QRect>
#pragma execution_character_set("utf-8")
extern int time_set; //计时器时间间隔
Advertisement::Advertisement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Advertisement)
{
    movie1=new QMovie(":/new/prefix1/image/advertisement1.gif");
    movie2=new QMovie(":/new/prefix1/image/advertisement2.gif");
    movie3=new QMovie(":/new/prefix1/image/advertisement3.gif");
    ui->setupUi(this);
    //设置控件位置
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect rect=desktopWidget->geometry();
    int x=ui->label->width();
    int y=ui->label->height();
    ui->label->move(rect.width()/2-x/2,rect.height()/2-y/2);
    ui->widget_2->move(rect.width()/2+x/2,rect.height()/2-y/2);

    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit->close();
    ui->pushButton_3->close();

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect ();
    effect->setBlurRadius(50); //设置模糊半径为50px
    effect->setColor(Qt::red); //设置阴影颜色
    effect->setOffset(0); //设置水平和垂直方向的偏移量都为0
    QGraphicsDropShadowEffect* effect1 = new QGraphicsDropShadowEffect ();
    effect1->setBlurRadius(50); //设置模糊半径为50px
    effect1->setColor(Qt::red); //设置阴影颜色
    effect1->setOffset(0); //设置水平和垂直方向的偏移量都为0
    QGraphicsDropShadowEffect* effect2 = new QGraphicsDropShadowEffect ();
    effect2->setBlurRadius(50); //设置模糊半径为50px
    effect2->setColor(Qt::red); //设置阴影颜色
    effect2->setOffset(0); //设置水平和垂直方向的偏移量都为0
    ui->pushButton->setGraphicsEffect(effect); //为控件应用特效
    ui->pushButton_2->setGraphicsEffect(effect1);
    ui->pushButton_3->setGraphicsEffect(effect2);

    movie_record=0;
    movie = new QMovie(":/new/prefix1/image/advertisement1.gif");
    ui->label->setMovie(movie);
    movie->start();

    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&Advertisement::start_movie);
    connect(ui->pushButton,&QPushButton::clicked,this,&Advertisement::show_widget);
    connect(&set,&Set::sure,this,&Advertisement::time_start);

    time_start();

}

Advertisement::~Advertisement()
{
    delete movie;
    delete movie1;
    delete movie2;
    delete movie3;
    delete ui;
}

void Advertisement::start_movie()
{
    if(movie_record==0)
    {
       movie3->stop();
       movie_record++;
       ui->label->setMovie(movie1);
       movie1->start();
    }
    else if(movie_record==1)
    {
        movie1->stop();
        movie_record++;
        ui->label->setMovie(movie2);
        movie2->start();

    }
     else if(movie_record==2)
    {
        movie2->stop();
        movie_record=0;
        ui->label->setMovie(movie3);
        movie3->start();
    }


}

void Advertisement::show_widget()
{
    emit deal();
}

void Advertisement::time_start()
{
   m_timer->start(time_set);
}

void Advertisement::on_pushButton_2_clicked()
{
    ui->label_2->show();
    ui->lineEdit->show();
    ui->pushButton_3->show();
}

void Advertisement::on_pushButton_3_clicked()
{
  QString str= ui->lineEdit->text();
  if(str=="123456")
  {
      ui->label_2->hide();
      ui->lineEdit->close();
      ui->pushButton_3->hide();
      ui->label_3->hide();
      ui->lineEdit->clear();
      set.show();
  }
  else
  {
      ui->label_3->show();
  }
}
