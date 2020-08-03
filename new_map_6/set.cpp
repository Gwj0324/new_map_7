#include "set.h"
#include "ui_set.h"
#include<QFile>
#include<QDebug>
#include<QGraphicsDropShadowEffect>
#pragma execution_character_set("utf-8")
int time_set;
extern int FirstFloorShopRecord;
extern int SecondFloorShopRecord;
extern int ThirdFloorShopRecord;

Set::Set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set)
{
    ui->setupUi(this);
    time_set=10000;
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect ();
    effect->setBlurRadius(50); //设置模糊半径为50px
    effect->setColor(Qt::red); //设置阴影颜色
    effect->setOffset(0); //设置水平和垂直方向的偏移量都为0
    QGraphicsDropShadowEffect* effect1 = new QGraphicsDropShadowEffect ();
    effect1->setBlurRadius(50); //设置模糊半径为50px
    effect1->setColor(Qt::red); //设置阴影颜色
    effect1->setOffset(0); //设置水平和垂直方向的偏移量都为0
    ui->pushButton->setGraphicsEffect(effect); //为控件应用特效
    ui->pushButton_2->setGraphicsEffect(effect1);
}

Set::~Set()
{
    delete ui;
}

void Set::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="10秒")
    {
        time_set=10000;
    }
    else if(arg1=="20秒")
    {
        time_set=20000;
    }
    else if(arg1=="30秒")
    {
        time_set=30000;
    }
    else if(arg1=="40秒")
    {
        time_set=40000;
    }
    else if(arg1=="50秒")
    {
        time_set=50000;
    }
    else if(arg1=="60秒")
    {
        time_set=60000;
    }
}

void Set::on_pushButton_clicked()
{
    emit sure();
}

void Set::on_pushButton_2_clicked()
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
           int number= array.toInt(&ok,10);
            qDebug()<<number;
            //显示到编辑区
            ui->textBrowser->setText(array);
        }
        //关闭文件
        file.close();
    }
}

void Set::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    if(arg1=="一楼店铺")
    {
        QString b1=QString("%1").arg(FirstFloorShopRecord);
        ui->textBrowser_2->setText(b1);
    }else if(arg1=="二楼店铺")
    {
       QString b1=QString("%1").arg(SecondFloorShopRecord);
        ui->textBrowser_2->setText(b1);
    }else if(arg1=="三楼店铺")
    {
        QString b1=QString("%1").arg(ThirdFloorShopRecord);
        ui->textBrowser_2->setText(b1);
    }
}
