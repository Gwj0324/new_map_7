#ifndef M_ROAD_H
#define M_ROAD_H

#include <QObject>
#include<QPoint>
#include<QImage>
#include<QVector>
#include "astar.h"

class m_road : public QObject
{
    Q_OBJECT
public:
    explicit m_road(QObject *parent = nullptr);
    void drawline(QPoint p,QPoint q);//画路径
    void deal_end_near_point(QPoint q);//寻找离终点最近的路径点
    void deal_start_near_point(QPoint p);//寻找离起点最近的路径点
    void deal_start_near_point_simplify(QVector<QVector<QPoint>> v);//简化代码
    void deal_start_near_point_simplify2();//简化代码

    QImage *image1;
    int end_near__x;
    int end_near__y;
    int start_near__x;
    int start_near__y;
    int posmin;
    int posmin2;
    int start_near_record;
    QPoint deal_start_near_point_point;
    QVector<QVector<QPoint>> vector_point_1;//一楼路径点
    QVector<QPoint> vector_point_1_copy;//一楼路径副本
    QVector<QVector<QPoint>> vector_point_2;//二楼路径点
    QVector<QPoint> vector_point_2_copy;//二楼路径副本
    QVector<QVector<QPoint>> vector_point_3;//三楼路径点
    QVector<QPoint> vector_point_3_copy;//三楼路径副本
    QVector<int> deal_end_near;
    QVector<int> deal_start_near;
    QPoint s1 ;
    QPoint s2 ;
    QPoint s3 ;
    QPoint s4 ;
    QPoint s5;
    QPoint ss1 ;
    QPoint ss2;
    QPoint l1;
    QPoint ss3;
    QPoint ss4;
    QPoint l2;
    QPoint ss5;
    QPoint ss6;
    QPoint l3;
    QPoint point00;
    QPoint point01 ;
    QPoint point02;
    QPoint point03 ;
    QPoint point04;
    QPoint point05;
    QPoint point06;
    QPoint point07;
    QPoint point08 ;
    QPoint point09 ;
    QPoint point10;
    QPoint point11;
    QPoint point12;
    QPoint point13;
    QPoint point14;
    QPoint point15;
    QPoint point16;
    QPoint point17;
    QPoint point18;
    QPoint point19 ;
    QPoint point20 ;
    QPoint point21 ;
    QPoint point22 ;
    QPoint point23;
    QPoint point24 ;
    QPoint point25;
    QPoint point26 ;
    QPoint point27;
    QPoint point28 ;
    QPoint point29;
    QPoint point_2_00 ;
    QPoint point_2_01 ;
    QPoint point_2_02;
    QPoint point_2_03 ;
    QPoint point_2_04 ;
    QPoint point_2_05;
    QPoint point_2_06 ;
    QPoint point_2_07 ;
    QPoint point_2_08 ;
    QPoint point_2_09 ;
    QPoint point_2_10;
    QPoint point_2_11;
    QPoint point_2_12;
    QPoint point_2_13;
    QPoint point_2_14;
    QPoint point_2_15;
    QPoint point_2_16;
    QPoint point_2_17;
    QPoint point_2_18;
    QPoint point_2_19 ;
    QPoint point_2_20 ;
    QPoint point_2_21 ;
    QPoint point_2_22 ;
    QPoint point_2_23;
    QPoint point_2_24 ;
    QPoint point_2_25 ;
    QPoint point_2_26;
    QPoint point_2_27 ;
    QPoint point_2_28 ;
    QPoint point_2_29 ;
    QPoint point_3_00;
    QPoint point_3_01 ;
    QPoint point_3_02 ;
    QPoint point_3_03;
    QPoint point_3_04;
    QPoint point_3_05 ;
    QPoint point_3_06 ;
    QPoint point_3_07;
    QPoint point_3_08 ;
    QPoint point_3_09 ;
    QPoint point_3_10 ;
    QPoint point_3_11;
    QPoint point_3_12;
    QPoint point_3_13;
    QPoint point_3_14;
    QPoint point_3_15;
    QPoint point_3_16;
    QPoint point_3_17;
    QPoint point_3_18;
    QPoint point_3_19 ;
    QPoint point_3_20 ;
    QPoint point_3_21;
    QPoint point_3_22;
    QPoint point_3_23 ;
    QPoint point_3_24 ;
    QPoint point_3_25 ;
    QPoint point_3_26 ;
    QPoint point_3_27 ;
    QPoint point_3_28 ;
    QPoint point_3_29 ;

signals:
    void updateimage(QImage *temp);


public slots:
    void drawimage();

};

#endif // M_ROAD_H
