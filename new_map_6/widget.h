#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>
#include<QPoint>
#include<QImage>
#include<QTimer>
#include"m_road.h"
#include"advertisement.h"
#define SLEEPTIME 90000
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void image_receive(QImage *temp);
    void show_stairs_lift();
    void read_file_get_statistic_navigation();
    void show_advertisement();


private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void deal_advertisement();

private:
    Ui::Widget *ui;
    QImage *m_image;
    m_road road;
    int record;
    QString str1;
    QString str2;
    QString str3;
    QString str4;
    QString str5;
    Advertisement advertisement;
    int statistic_navigation;//导航次数统计
    QTimer *m_timer;
};

#endif // WIDGET_H
