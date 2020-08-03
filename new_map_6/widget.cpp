#include "widget.h"
#include "ui_widget.h"
#include<QComboBox>
#include<QPaintEvent>
#include<QPushButton>
#include<QPainter>
#include<QMouseEvent>
#include<QDebug>
#include<QPen>
#include<QRect>
#include<QPoint>
#include<QStringList>
#include<QImage>
#include<QCompleter>
#include<QIcon>
#include<QGraphicsDropShadowEffect>
#pragma execution_character_set("utf-8")
QPoint end_point;
QPoint start_point;
int stairs_or_lift;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_image = new QImage();
    ui->dockWidget->hide();
    ui->pushButton_20->close();
    ui->pushButton_21->close();
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
    QGraphicsDropShadowEffect* effect3 = new QGraphicsDropShadowEffect ();
    effect3->setBlurRadius(50); //设置模糊半径为50px
    effect3->setColor(Qt::red); //设置阴影颜色
    effect3->setOffset(0); //设置水平和垂直方向的偏移量都为0
    QGraphicsDropShadowEffect* effect4 = new QGraphicsDropShadowEffect ();
    effect4->setBlurRadius(50); //设置模糊半径为50px
    effect4->setColor(Qt::red); //设置阴影颜色
    effect4->setOffset(0); //设置水平和垂直方向的偏移量都为0
    ui->pushButton->setGraphicsEffect(effect); //为控件应用特效
   ui->pushButton_2->setGraphicsEffect(effect1);
   ui->pushButton_14->setGraphicsEffect(effect2);
   ui->pushButton_20->setGraphicsEffect(effect3);
   ui->pushButton_21->setGraphicsEffect(effect4);
    this->setWindowTitle(QString("室内导航"));
    this->setWindowIcon(QIcon(":/new/prefix1/image/panda.ico"));
    read_file_get_statistic_navigation();
    QStringList list;
    list << "F11店铺" << "F12店铺"<< "F13店铺"<< "F14店铺"<< "F15店铺"
            <<"F16店铺"<< "F17店铺"<< "F18店铺"<< "F19店铺"<< "F110店铺"<< "F111店铺"
              <<"F112店铺" << "F113店铺"<< "F114店铺"<< "F115店铺"<< "F116店铺"
                <<"F117店铺" << "F118店铺"<< "F119店铺"<< "F120店铺"<< "F121店铺"
         << "F122店铺" << "F21店铺" << "F22店铺" << "F23店铺" <<"F24店铺"<< "F25店铺" << "F26店铺" << "F27店铺"
            <<"F28店铺"<< "F29店铺"<< "F210店铺"<< "F211店铺"<< "F212店铺"<< "F213店铺"
               <<"F214店铺"<< "F215店铺"<< "F216店铺"<< "F217店铺"<< "F218店铺"<< "F219店铺"<<"F220店铺"
              << "F221店铺" << "F222店铺"<< "F223店铺"<< "F224店铺"<< "F225店铺"
                          <<"F31店铺"<< "F32店铺"<< "F33店铺"<< "F34店铺"<< "F35店铺"<< "F36店铺"
                            <<"F37店铺" << "F38店铺"<< "F39店铺"<< "F310店铺"<< "F311店铺"
                              <<"F312店铺" << "F313店铺"<< "F314店铺"<< "F315店铺"<< "F316店铺"
                       << "F317店铺" << "F318店铺" << "F319店铺" << "F320店铺" <<"F321店铺"<< "F322店铺";
    QCompleter *completer = new QCompleter(list, this);
    completer->setFilterMode(Qt::MatchContains);
    ui->comboBox->setEditable(true);
    ui->comboBox->setCompleter(completer);
    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&Widget::show_advertisement);
    connect(ui->pushButton_2,&QPushButton::clicked,&road,&m_road::drawimage);
    connect(&road,&m_road::updateimage,this,&Widget::image_receive);
    connect(&advertisement,&Advertisement::deal,this,&Widget::deal_advertisement);
    advertisement.setWindowFlags(Qt::Dialog);
    advertisement.showFullScreen();
    this->setVisible(false);



}
//绘图
void Widget::paintEvent(QPaintEvent *)
{


    QPainter m_painter(this);
    m_painter.drawPixmap(553,0,197,391,QPixmap(":/new/prefix1/image/back2.jpg"));
    QPen pen2;//定义画笔
    pen2.setWidth(5);
    pen2.setColor(Qt::red);
    pen2.setStyle(Qt::DotLine);
    m_painter.setPen(pen2);
    QRect target(0,0,553,391);
    QRect source(0,0,553,391);

    if(record==5)
    {
       ui->label->close();
       m_painter.drawImage(target,*m_image,source);

    }
}
//测量坐标
void Widget::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if (event->button() == Qt::LeftButton){
        //qDebug() << "left click";
        QPoint sPoint2=QCursor::pos();
        QPoint windowPoint = this->mapFromGlobal(sPoint2);
          qDebug() << "QPoint point_3_" << "(" << windowPoint.rx() << "," << windowPoint.ry() << ");";
    }
    // 如果是鼠标右键按下
    else if (event->button() == Qt::RightButton){
        //qDebug() << "right click";

    }
    else if (event->button() == Qt::MidButton){
        //qDebug() << "mid click";

    }
}
//接受图片，更新窗口
void Widget::image_receive(QImage *temp)
{
    delete m_image;
    m_image=temp;
    record=5;
    qDebug() <<"图片收到";
    update();
}

void Widget::show_stairs_lift()
{
    if(end_point.y()<127)
    {
        ui->label_7->setText(QString("终点在一楼"));
        if(start_point.y()>127)
        {
            ui->pushButton_20->show();
            ui->pushButton_21->show();
        }
    }
    else if(end_point.y()>127&&end_point.y()<260)
    {
        ui->label_7->setText(QString("终点在二楼"));
        if(start_point.y()<127||start_point.y()>260)
        {
            ui->pushButton_20->show();
            ui->pushButton_21->show();
        }
    }
    else if(end_point.y()>260)
    {
        ui->label_7->setText(QString("终点在三楼"));
        if(start_point.y()<260)
        {
            ui->pushButton_20->show();
            ui->pushButton_21->show();
        }
    }
}

void Widget::read_file_get_statistic_navigation()
{
    QString path ="../data.txt";
    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file;
        file.setFileName(path);
        //打开文件，只读方式
        bool isOk=file.open(QIODevice::ReadOnly);
        if(isOk==true)
        {
            //读文件
            QByteArray array = file.readAll();
            bool ok;
           statistic_navigation= array.toInt(&ok,10);
        }
        //关闭文件
        file.close();
    }
}

void Widget::show_advertisement()
{
        this->hide();
        advertisement.show();
        m_timer->stop();
}
Widget::~Widget()
{
    delete m_image;
    delete ui;
}
//显示浮动窗口
void Widget::on_pushButton_clicked()
{
    ui->dockWidget->show();
}
//得到终点坐标
void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="F11店铺")
    {
      end_point.setX(63);
      end_point.setY(18);
    }
    else if(arg1=="F12店铺")
    {
        end_point.setX(102);
        end_point.setY(18);
    }
    else if(arg1=="F13店铺")
    {
        end_point.setX(151);
        end_point.setY(18);
    }
    else if(arg1=="F14店铺")
    {
        end_point.setX(188);
        end_point.setY(18);
    }
    else if(arg1=="F15店铺")
    {
        end_point.setX(226);
        end_point.setY(18);
    }
    else if(arg1=="F16店铺")
    {
        end_point.setX(264);
        end_point.setY(18);
    }
    else if(arg1=="F17店铺")
    {
        end_point.setX(303);
        end_point.setY(18);
    }
    else if(arg1=="F18店铺")
    {
        end_point.setX(339);
        end_point.setY(18);
    }
    else if(arg1=="F19店铺")
    {
        end_point.setX(376);
        end_point.setY(18);
    }
    else if(arg1=="F110店铺")
    {
        end_point.setX(425);
        end_point.setY(18);
    }
    else if(arg1=="F111店铺")
    {
        end_point.setX(420);
        end_point.setY(57);
    }
    else if(arg1=="F112店铺")
    {
        end_point.setX(416);
        end_point.setY(96);
    }
    else if(arg1=="F113店铺")
    {
        end_point.setX(387);
        end_point.setY(96);
    }
    else if(arg1=="F114店铺")
    {
        end_point.setX(343);
        end_point.setY(96);
    }
    else if(arg1=="F115店铺")
    {
        end_point.setX(304);
        end_point.setY(96);
    }
    else if(arg1=="F116店铺")
    {
        end_point.setX(265);
        end_point.setY(96);
    }
    else if(arg1=="F117店铺")
    {
        end_point.setX(228);
        end_point.setY(96);
    }
    else if(arg1=="F118店铺")
    {
        end_point.setX(185);
        end_point.setY(96);
    }
    else if(arg1=="F119店铺")
    {
        end_point.setX(144);
        end_point.setY(96);
    }
    else if(arg1=="F120店铺")
    {
        end_point.setX(105);
        end_point.setY(96);
    }
    else if(arg1=="F121店铺")
    {
        end_point.setX(62);
        end_point.setY(96);
    }
    else if(arg1=="F122店铺")
    {
        end_point.setX(50);
        end_point.setY(60);
    }
    else if(arg1=="F21店铺")
    {
        end_point.setX(65);
        end_point.setY(145);
    }
    else if(arg1=="F22店铺")
    {
        end_point.setX(105);
        end_point.setY(145);
    }
    else if(arg1=="F23店铺")
    {
        end_point.setX(144);
        end_point.setY(145);
    }
    else if(arg1=="F24店铺")
    {
        end_point.setX(184);
        end_point.setY(145);
    }
    else if(arg1=="F25店铺")
    {
        end_point.setX(226);
        end_point.setY(145);
    }
    else if(arg1=="F26店铺")
    {
        end_point.setX(265);
        end_point.setY(145);
    }
    else if(arg1=="F27店铺")
    {
        end_point.setX(305);
        end_point.setY(145);
    }
    else if(arg1=="F28店铺")
    {
        end_point.setX(346);
        end_point.setY(145);
    }
    else if(arg1=="F29店铺")
    {
        end_point.setX(386);
        end_point.setY(145);
    }
    else if(arg1=="F210店铺")
    {
        end_point.setX(405);
        end_point.setY(145);
    }
    else if(arg1=="F211店铺")
    {
        end_point.setX(431);
        end_point.setY(195);
    }
    else if(arg1=="F212店铺")
    {
        end_point.setX(417);
        end_point.setY(233);
    }
    else if(arg1=="F213店铺")
    {
        end_point.setX(386);
        end_point.setY(233);
    }
    else if(arg1=="F214店铺")
    {
        end_point.setX(346);
        end_point.setY(233);
    }
    else if(arg1=="F215店铺")
    {
        end_point.setX(305);
        end_point.setY(233);
    }
    else if(arg1=="F216店铺")
    {
        end_point.setX(265);
        end_point.setY(233);
    }
    else if(arg1=="F217店铺")
    {
        end_point.setX(223);
        end_point.setY(233);
    }
    else if(arg1=="F218店铺")
    {
        end_point.setX(184);
        end_point.setY(233);
    }
    else if(arg1=="F219店铺")
    {
        end_point.setX(144);
        end_point.setY(233);
    }
    else if(arg1=="F220店铺")
    {
        end_point.setX(103);
        end_point.setY(233);
    }
    else if(arg1=="F221店铺")
    {
      end_point.setX(65);
      end_point.setY(233);
    }
    else if(arg1=="F222店铺")
    {
        end_point.setX(51);
        end_point.setY(195);
    }
    else if(arg1=="F223店铺")
    {
        end_point.setX(191);
        end_point.setY(191);
    }
    else if(arg1=="F224店铺")
    {
        end_point.setX(228);
        end_point.setY(191);
    }
    else if(arg1=="F31店铺")
    {
        end_point.setX(65);
        end_point.setY(287);
    }
    else if(arg1=="F32店铺")
    {
        end_point.setX(104);
        end_point.setY(287);
    }
    else if(arg1=="F33店铺")
    {
        end_point.setX(145);
        end_point.setY(287);
    }
    else if(arg1=="F34店铺")
    {
        end_point.setX(186);
        end_point.setY(287);
    }
    else if(arg1=="F35店铺")
    {
        end_point.setX(226);
        end_point.setY(287);
    }
    else if(arg1=="F36店铺")
    {
        end_point.setX(265);
        end_point.setY(287);
    }
    else if(arg1=="F37店铺")
    {
        end_point.setX(305);
        end_point.setY(287);
    }
    else if(arg1=="F38店铺")
    {
        end_point.setX(346);
        end_point.setY(287);
    }
    else if(arg1=="F39店铺")
    {
        end_point.setX(387);
        end_point.setY(287);
    }
    else if(arg1=="F310店铺")
    {
        end_point.setX(411);
        end_point.setY(287);
    }
    else if(arg1=="F311店铺")
    {
        end_point.setX(424);
        end_point.setY(330);
    }
    else if(arg1=="F312店铺")
    {
        end_point.setX(418);
        end_point.setY(370);
    }
    else if(arg1=="F313店铺")
    {
        end_point.setX(387);
        end_point.setY(370);
    }
    else if(arg1=="F314店铺")
    {
        end_point.setX(348);
        end_point.setY(370);
    }
    else if(arg1=="F315店铺")
    {
        end_point.setX(307);
        end_point.setY(370);
    }
    else if(arg1=="F316店铺")
    {
        end_point.setX(266);
        end_point.setY(370);
    }
    else if(arg1=="F317店铺")
    {
        end_point.setX(227);
        end_point.setY(370);
    }
    else if(arg1=="F318店铺")
    {
        end_point.setX(186);
        end_point.setY(370);
    }
    else if(arg1=="F319店铺")
    {
        end_point.setX(145);
        end_point.setY(370);
    }
    else if(arg1=="F320店铺")
    {
        end_point.setX(104);
        end_point.setY(370);
    }
    else if(arg1=="F321店铺")
    {
        end_point.setX(65);
        end_point.setY(370);
    }
    else if(arg1=="F322店铺")
    {
        end_point.setX(50);
        end_point.setY(333);
    }
    show_stairs_lift();
    ui->pushButton_20->show();
     ui->pushButton_21->show();
}

void Widget::on_pushButton_3_clicked()
{
    str1="F";
}

void Widget::on_pushButton_4_clicked()
{
    if(str3!="")
    {
        str4="0";
    }
    else if(str2!="")
    {
        str3="0";
    }
    else
    {
        str2="0";
    }
}

void Widget::on_pushButton_5_clicked()
{
    if(str3!="")
    {
        str4="1";
    }
    else if(str2!="")
    {
        str3="1";
    }
    else
    {
        str2="1";
    }
}

void Widget::on_pushButton_6_clicked()
{
    if(str3!="")
    {
        str4="2";
    }
    else if(str2!="")
    {
        str3="2";
    }
    else
    {
        str2="2";
    }
}

void Widget::on_pushButton_7_clicked()
{
    if(str3!="")
    {
        str4="3";
    }
    else if(str2!="")
    {
        str3="3";
    }
    else
    {
        str2="3";
    }
}

void Widget::on_pushButton_8_clicked()
{
    if(str3!="")
    {
        str4="4";
    }
    else if(str2!="")
    {
        str3="4";
    }
    else
    {
        str2="4";
    }
}

void Widget::on_pushButton_9_clicked()
{
    if(str3!="")
    {
        str4="5";
    }
    else if(str2!="")
    {
        str3="5";
    }
    else
    {
        str2="5";
    }
}

void Widget::on_pushButton_10_clicked()
{
    if(str3!="")
    {
        str4="6";
    }
    else if(str2!="")
    {
        str3="6";
    }
    else
    {
        str2="6";
    }
}

void Widget::on_pushButton_11_clicked()
{
    if(str3!="")
    {
        str4="7";
    }
    else if(str2!="")
    {
        str3="7";
    }
    else
    {
        str2="7";
    }
}

void Widget::on_pushButton_12_clicked()
{
    if(str3!="")
    {
        str4="8";
    }
    else if(str2!="")
    {
        str3="8";
    }
    else
    {
        str2="8";
    }
}

void Widget::on_pushButton_13_clicked()
{
    if(str3!="")
    {
        str4="9";
    }
    else if(str2!="")
    {
        str3="9";
    }
    else
    {
        str2="9";
    }
}
//显示终点,得到终点坐标
void Widget::on_pushButton_14_clicked()
{
    str5=QString("%1%2%3%4店铺").arg(str1).arg(str2).arg(str3).arg(str4);
    ui->label_2->setText(str5);
    QString arg1=str5;
    str2="";
    str3="";
    str4="";
    if(arg1=="F11店铺")
    {
      end_point.setX(63);
      end_point.setY(18);
    }
    else if(arg1=="F12店铺")
    {
        end_point.setX(102);
        end_point.setY(18);
    }
    else if(arg1=="F13店铺")
    {
        end_point.setX(151);
        end_point.setY(18);
    }
    else if(arg1=="F14店铺")
    {
        end_point.setX(188);
        end_point.setY(18);
    }
    else if(arg1=="F15店铺")
    {
        end_point.setX(226);
        end_point.setY(18);
    }
    else if(arg1=="F16店铺")
    {
        end_point.setX(264);
        end_point.setY(18);
    }
    else if(arg1=="F17店铺")
    {
        end_point.setX(303);
        end_point.setY(18);
    }
    else if(arg1=="F18店铺")
    {
        end_point.setX(339);
        end_point.setY(18);
    }
    else if(arg1=="F19店铺")
    {
        end_point.setX(376);
        end_point.setY(18);
    }
    else if(arg1=="F110店铺")
    {
        end_point.setX(425);
        end_point.setY(18);
    }
    else if(arg1=="F111店铺")
    {
        end_point.setX(420);
        end_point.setY(57);
    }
    else if(arg1=="F112店铺")
    {
        end_point.setX(416);
        end_point.setY(96);
    }
    else if(arg1=="F113店铺")
    {
        end_point.setX(387);
        end_point.setY(96);
    }
    else if(arg1=="F114店铺")
    {
        end_point.setX(343);
        end_point.setY(96);
    }
    else if(arg1=="F115店铺")
    {
        end_point.setX(304);
        end_point.setY(96);
    }
    else if(arg1=="F116店铺")
    {
        end_point.setX(265);
        end_point.setY(96);
    }
    else if(arg1=="F117店铺")
    {
        end_point.setX(228);
        end_point.setY(96);
    }
    else if(arg1=="F118店铺")
    {
        end_point.setX(185);
        end_point.setY(96);
    }
    else if(arg1=="F119店铺")
    {
        end_point.setX(144);
        end_point.setY(96);
    }
    else if(arg1=="F120店铺")
    {
        end_point.setX(105);
        end_point.setY(96);
    }
    else if(arg1=="F121店铺")
    {
        end_point.setX(62);
        end_point.setY(96);
    }
    else if(arg1=="F122店铺")
    {
        end_point.setX(50);
        end_point.setY(60);
    }
    else if(arg1=="F21店铺")
    {
        end_point.setX(65);
        end_point.setY(145);
    }
    else if(arg1=="F22店铺")
    {
        end_point.setX(105);
        end_point.setY(145);
    }
    else if(arg1=="F23店铺")
    {
        end_point.setX(144);
        end_point.setY(145);
    }
    else if(arg1=="F24店铺")
    {
        end_point.setX(184);
        end_point.setY(145);
    }
    else if(arg1=="F25店铺")
    {
        end_point.setX(226);
        end_point.setY(145);
    }
    else if(arg1=="F26店铺")
    {
        end_point.setX(265);
        end_point.setY(145);
    }
    else if(arg1=="F27店铺")
    {
        end_point.setX(305);
        end_point.setY(145);
    }
    else if(arg1=="F28店铺")
    {
        end_point.setX(346);
        end_point.setY(145);
    }
    else if(arg1=="F29店铺")
    {
        end_point.setX(386);
        end_point.setY(145);
    }
    else if(arg1=="F210店铺")
    {
        end_point.setX(405);
        end_point.setY(145);
    }
    else if(arg1=="F211店铺")
    {
        end_point.setX(431);
        end_point.setY(195);
    }
    else if(arg1=="F212店铺")
    {
        end_point.setX(417);
        end_point.setY(233);
    }
    else if(arg1=="F213店铺")
    {
        end_point.setX(386);
        end_point.setY(233);
    }
    else if(arg1=="F214店铺")
    {
        end_point.setX(346);
        end_point.setY(233);
    }
    else if(arg1=="F215店铺")
    {
        end_point.setX(305);
        end_point.setY(233);
    }
    else if(arg1=="F216店铺")
    {
        end_point.setX(265);
        end_point.setY(233);
    }
    else if(arg1=="F217店铺")
    {
        end_point.setX(223);
        end_point.setY(233);
    }
    else if(arg1=="F218店铺")
    {
        end_point.setX(184);
        end_point.setY(233);
    }
    else if(arg1=="F219店铺")
    {
        end_point.setX(144);
        end_point.setY(233);
    }
    else if(arg1=="F220店铺")
    {
        end_point.setX(103);
        end_point.setY(233);
    }
    else if(arg1=="F221店铺")
    {
      end_point.setX(65);
      end_point.setY(233);
    }
    else if(arg1=="F222店铺")
    {
        end_point.setX(51);
        end_point.setY(195);
    }
    else if(arg1=="F223店铺")
    {
        end_point.setX(191);
        end_point.setY(191);
    }
    else if(arg1=="F224店铺")
    {
        end_point.setX(228);
        end_point.setY(191);
    }
    else if(arg1=="F31店铺")
    {
        end_point.setX(65);
        end_point.setY(287);
    }
    else if(arg1=="F32店铺")
    {
        end_point.setX(104);
        end_point.setY(287);
    }
    else if(arg1=="F33店铺")
    {
        end_point.setX(145);
        end_point.setY(287);
    }
    else if(arg1=="F34店铺")
    {
        end_point.setX(186);
        end_point.setY(287);
    }
    else if(arg1=="F35店铺")
    {
        end_point.setX(226);
        end_point.setY(287);
    }
    else if(arg1=="F36店铺")
    {
        end_point.setX(265);
        end_point.setY(287);
    }
    else if(arg1=="F37店铺")
    {
        end_point.setX(305);
        end_point.setY(287);
    }
    else if(arg1=="F38店铺")
    {
        end_point.setX(346);
        end_point.setY(287);
    }
    else if(arg1=="F39店铺")
    {
        end_point.setX(387);
        end_point.setY(287);
    }
    else if(arg1=="F310店铺")
    {
        end_point.setX(411);
        end_point.setY(287);
    }
    else if(arg1=="F311店铺")
    {
        end_point.setX(424);
        end_point.setY(330);
    }
    else if(arg1=="F312店铺")
    {
        end_point.setX(418);
        end_point.setY(370);
    }
    else if(arg1=="F313店铺")
    {
        end_point.setX(387);
        end_point.setY(370);
    }
    else if(arg1=="F314店铺")
    {
        end_point.setX(348);
        end_point.setY(370);
    }
    else if(arg1=="F315店铺")
    {
        end_point.setX(307);
        end_point.setY(370);
    }
    else if(arg1=="F316店铺")
    {
        end_point.setX(266);
        end_point.setY(370);
    }
    else if(arg1=="F317店铺")
    {
        end_point.setX(227);
        end_point.setY(370);
    }
    else if(arg1=="F318店铺")
    {
        end_point.setX(186);
        end_point.setY(370);
    }
    else if(arg1=="F319店铺")
    {
        end_point.setX(145);
        end_point.setY(370);
    }
    else if(arg1=="F320店铺")
    {
        end_point.setX(104);
        end_point.setY(370);
    }
    else if(arg1=="F321店铺")
    {
        end_point.setX(65);
        end_point.setY(370);
    }
    else if(arg1=="F322店铺")
    {
        end_point.setX(50);
        end_point.setY(333);
    }
    show_stairs_lift();
    ui->pushButton_20->show();
     ui->pushButton_21->show();
}
//设置起始点
void Widget::on_pushButton_15_clicked()
{
    start_point.setX(161);
    start_point.setY(61);
    ui->label_6->setText(QString("起点在一楼"));
}

void Widget::on_pushButton_16_clicked()
{
    start_point.setX(291);
    start_point.setY(61);
    ui->label_6->setText(QString("起点在一楼"));
}

void Widget::on_pushButton_17_clicked()
{
    start_point.setX(144);
    start_point.setY(194);
    ui->label_6->setText(QString("起点在二楼"));
}

void Widget::on_pushButton_18_clicked()
{
    start_point.setX(386);
    start_point.setY(191);
     ui->label_6->setText(QString("起点在二楼"));
}

void Widget::on_pushButton_19_clicked()
{
    start_point.setX(186);
    start_point.setY(333);
     ui->label_6->setText(QString("起点在三楼"));
}

void Widget::on_pushButton_20_clicked()
{
    stairs_or_lift=0;
    statistic_navigation++;
    QString path ="../data.txt";
     QFile file;
    file.setFileName(path);
   QString e= QString::number(statistic_navigation);
   file.open(QIODevice::WriteOnly|QIODevice::Text);
   file.write(e.toUtf8());
   file.flush();
   file.close();
}

void Widget::on_pushButton_21_clicked()
{
    stairs_or_lift=1;
    statistic_navigation++;
    QString path ="../data.txt";
     QFile file;
    file.setFileName(path);
   QString e= QString::number(statistic_navigation);
   file.open(QIODevice::WriteOnly|QIODevice::Text);
   file.write(e.toUtf8());
   file.flush();
   file.close();
}

void Widget::deal_advertisement()
{
    this->show();
    advertisement.close();
    m_timer->start(SLEEPTIME);
}
