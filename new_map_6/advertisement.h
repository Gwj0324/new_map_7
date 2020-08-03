#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include <QWidget>
#include<QMovie>
#include<QTimer>
#include"set.h"

namespace Ui {
class Advertisement;
}

class Advertisement : public QWidget
{
    Q_OBJECT

public:
    explicit Advertisement(QWidget *parent = 0);
    ~Advertisement();
    void start_movie();
    void show_widget();
    void time_start();

    int movie_record;
signals:
    void deal();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Advertisement *ui;
    QTimer *m_timer;
    Set set;
    QMovie *movie;
    QMovie *movie1;
    QMovie *movie2;
    QMovie *movie3;



};

#endif // ADVERTISEMENT_H
