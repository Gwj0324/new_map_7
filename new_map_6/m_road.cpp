#include "m_road.h"
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QImage>
#include<QPoint>
#include<QDebug>
#include<QVector>
#include<iterator>
#include<iostream>
#include<QBrush>
#pragma execution_character_set("utf-8")
using namespace std;
int FirstFloorShopRecord;
int SecondFloorShopRecord;
int ThirdFloorShopRecord;
extern QPoint end_point;
extern QPoint start_point;
extern int stairs_or_lift;

m_road::m_road(QObject *parent) : QObject(parent)
{
     image1=new QImage(553,391,QImage::Format_ARGB32);
     s1=QPoint( 161 , 61);
     s2=QPoint ( 291 , 61 );
     s3=QPoint ( 144 , 194 );
     s4 =QPoint( 386 , 191 );
     s5=QPoint( 186, 333 );
     ss1=QPoint ( 89 , 59 );
     ss2=QPoint( 240 , 62 );
     l1=QPoint( 343 , 58 );
     ss3=QPoint( 89 , 193 );
     ss4=QPoint ( 265 , 193 );
     l2=QPoint( 342 , 191 );
     ss5=QPoint( 89 , 333 );
     ss6=QPoint( 236 , 331 );
     l3=QPoint( 342 , 329 );
     point00=QPoint( 63 , 35 );
     point01=QPoint ( 102 , 35 );
     point02 =QPoint( 151 , 35 );
     point03 =QPoint( 188 , 35 );
     point04 =QPoint( 226 , 35 );
     point05 =QPoint( 264 , 35 );
     point06=QPoint ( 303 , 35);
     point07 =QPoint( 339 , 35);
     point08=QPoint ( 376 , 35 );
     point09 =QPoint( 409 , 35 );
     point10 =QPoint( 63 , 60 );

     point19=QPoint ( 405 , 60 );
     point20=QPoint ( 63 , 83 );
     point21=QPoint ( 105 , 83 );
     point22 =QPoint( 144 , 83 );
     point23=QPoint ( 185 , 83 );
     point24 =QPoint( 228 , 83 );
     point25=QPoint ( 265 , 83 );
     point26 =QPoint( 304 , 83 );
     point27=QPoint ( 343 , 83 );
     point28=QPoint ( 387 , 83 );
     point29=QPoint ( 405 , 83 );
     point_2_00=QPoint ( 65 , 166 );
     point_2_01 =QPoint( 105 , 166 );
     point_2_02=QPoint ( 144 , 166 );
     point_2_03=QPoint ( 184 , 166 );
     point_2_04=QPoint ( 226 , 166 );
     point_2_05 =QPoint( 265 , 166 );
     point_2_06 =QPoint( 305 , 166 );
     point_2_07 =QPoint( 346 , 166 );
     point_2_08 =QPoint( 386 , 166 );
     point_2_09 =QPoint( 417 , 166 );
     point_2_10=QPoint ( 65 , 194 );

     point_2_19=QPoint ( 417 , 194 );
     point_2_20=QPoint ( 65 , 217 );
     point_2_21=QPoint ( 103 , 217 );
     point_2_22=QPoint ( 144 , 217 );
     point_2_23=QPoint ( 184 , 217 );
     point_2_24 =QPoint( 223 , 217 );
     point_2_25=QPoint ( 265 , 217 );
     point_2_26=QPoint ( 305 , 217 );
     point_2_27=QPoint ( 346 , 217 );
     point_2_28=QPoint ( 386 , 217 );
     point_2_29=QPoint ( 417 , 217 );
     point_3_00=QPoint ( 65 , 304 );
     point_3_01=QPoint ( 104 , 304 );
     point_3_02=QPoint ( 145 , 304 );
     point_3_03=QPoint ( 186 , 304 );
     point_3_04=QPoint ( 226 , 304 );
     point_3_05=QPoint ( 265 , 304 );
     point_3_06=QPoint ( 305 , 304 );
     point_3_07=QPoint ( 346 , 304 );
     point_3_08=QPoint ( 387 , 304 );
     point_3_09=QPoint ( 411 , 304 );
     point_3_10=QPoint ( 65 , 332 );

     point_3_19=QPoint ( 411 , 332 );
     point_3_20=QPoint ( 65 , 356 );
     point_3_21=QPoint ( 104 , 356 );
     point_3_22=QPoint ( 145 , 356 );
     point_3_23=QPoint ( 186 , 356 );
     point_3_24=QPoint ( 227 , 356 );
     point_3_25=QPoint ( 266 , 356 );
     point_3_26=QPoint ( 307 , 356 );
     point_3_27=QPoint ( 348 , 356 );
     point_3_28=QPoint ( 387 , 356 );
     point_3_29=QPoint ( 411 , 356 );
     vector_point_1={
         {point00,point01,point02,point03,point04,point05,point06,point07,point08,point09},
         {point10,point11,point12,point13,point14,point15,point16,point17,point18,point19},
         {point20,point21,point22,point23,point24,point25,point26,point27,point28,point29}
     };
     vector_point_1_copy={point00,point01,point02,point03,point04,point05,point06,point07,point08,point09,
                          point10,point11,point12,point13,point14,point15,point16,point17,point18,point19,
                          point20,point21,point22,point23,point24,point25,point26,point27,point28,point29
     };
     vector_point_2={
         {point_2_00,point_2_01,point_2_02,point_2_03,point_2_04,point_2_05,point_2_06,point_2_07,point_2_08,point_2_09},
         {point_2_10,point_2_11,point_2_12,point_2_13,point_2_14,point_2_15,point_2_16,point_2_17,point_2_18,point_2_19},
         {point_2_20,point_2_21,point_2_22,point_2_23,point_2_24,point_2_25,point_2_26,point_2_27,point_2_28,point_2_29}
     };
     vector_point_2_copy={
         point_2_00,point_2_01,point_2_02,point_2_03,point_2_04,point_2_05,point_2_06,point_2_07,point_2_08,point_2_09,
         point_2_10,point_2_11,point_2_12,point_2_13,point_2_14,point_2_15,point_2_16,point_2_17,point_2_18,point_2_19,
         point_2_20,point_2_21,point_2_22,point_2_23,point_2_24,point_2_25,point_2_26,point_2_27,point_2_28,point_2_29
     };
     vector_point_3={
         {point_3_00,point_3_01,point_3_02,point_3_03,point_3_04,point_3_05,point_3_06,point_3_07,point_3_08,point_3_09},
         {point_3_10,point_3_11,point_3_12,point_3_13,point_3_14,point_3_15,point_3_16,point_3_17,point_3_18,point_3_19},
         {point_3_20,point_3_21,point_3_22,point_3_23,point_3_24,point_3_25,point_3_26,point_3_27,point_3_28,point_3_29}
     };
     vector_point_3_copy={
         point_3_00,point_3_01,point_3_02,point_3_03,point_3_04,point_3_05,point_3_06,point_3_07,point_3_08,point_3_09,
         point_3_10,point_3_11,point_3_12,point_3_13,point_3_14,point_3_15,point_3_16,point_3_17,point_3_18,point_3_19,
         point_3_20,point_3_21,point_3_22,point_3_23,point_3_24,point_3_25,point_3_26,point_3_27,point_3_28,point_3_29
     };
     FirstFloorShopRecord=0;
     SecondFloorShopRecord=0;
     ThirdFloorShopRecord=0;
}
void m_road::drawline(QPoint p,QPoint q)
{
    if(q.y()<127)
    {
        FirstFloorShopRecord++;
    }else if(q.y()<260)
    {
        SecondFloorShopRecord++;
    }else
        {
        ThirdFloorShopRecord++;
    }
   QPainter m_painter2(image1);
   m_painter2.drawPixmap(0,0,553,391,QPixmap(":/new/prefix1/image/back(1).jpg"));
   m_painter2.setRenderHint(QPainter::Antialiasing);//平滑直线
   m_painter2.setPen(QPen(Qt::red,5,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
   QVector<QPoint> storage;//存储路径点，显示路径
   //A*地图
   QVector<QVector<int>> maze = {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
   };
   //起点，终点都在一楼
   if(p.y()<127&&q.y()<127)
   {
       //求距离终点最近的点
       deal_end_near_point(q);
       m_painter2.drawLine(q,vector_point_1_copy[posmin]);

       //求距离起点最近的点，s1起点
       if(p.x()==s1.x()&&p.y()==s1.y())
       {
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
       }
       //求距离起点最近的点，s2起点
       else if(p.x()==s2.x()&&p.y()==s2.y())
       {
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
       }
   }
   //起点在一楼，终点在二楼
   else if(p.y()<127&&q.y()>127&&q.y()<260)
   {
       if(stairs_or_lift==0)
       {
           //起点是s1
           if(p==s1)
           {
               m_painter2.drawLine(p,ss1);
               p=ss3;
           }
           //起点是s2
           else if(p==s2)
           {
               m_painter2.drawLine(p,ss2);
               p=ss4;
           }

           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_2_copy[posmin]);

           //求距离起点（楼梯ss3）最近的点
           if(p.x()==ss3.x()&&p.y()==ss3.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
           }
           //求距离起点（楼梯ss4）最近的点
           else if(p.x()==ss4.x()&&p.y()==ss4.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
           }
       }
       else if(stairs_or_lift==1)
       {
           //起点是s1
           if(p==s1)
           {
               m_painter2.drawLine(p,point03);
               m_painter2.drawLine(point03,point07);
               m_painter2.drawLine(point07,l1);
               p=l2;
           }
           //起点是s2
           else if(p==s2)
           {
               m_painter2.drawLine(p,l1);
               p=l2;
           }

           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_2_copy[posmin]);

           //求距离起点（电梯l2）最近的点
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
       }
   }
   //起点在一楼，终点在三楼
   else if(p.y()<127&&q.y()>260)
   {
       if(stairs_or_lift==0)
       {
           //起点是s1
           if(p==s1)
           {
               m_painter2.drawLine(p,ss1);
               p=ss5;
           }
           //起点是s2
           else if(p==s2)
           {
               m_painter2.drawLine(p,ss2);
               p=ss6;
           }
           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_3_copy[posmin]);

           //求距离起点（楼梯ss5）最近的点
           if(p.x()==ss5.x()&&p.y()==ss5.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
           }
           //求距离起点（楼梯ss6）最近的点
           else if(p.x()==ss6.x()&&p.y()==ss6.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
           }
       }
       else if(stairs_or_lift==1)
       {
           //起点是s1
           if(p==s1)
           {
               m_painter2.drawLine(p,point03);
               m_painter2.drawLine(point03,point07);
               m_painter2.drawLine(point07,l1);
               p=l3;
           }
           //起点是s2
           else if(p==s2)
           {
               m_painter2.drawLine(p,l1);
               p=l3;
           }

           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_3_copy[posmin]);

           //求距离起点（电梯l3）最近的点
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
       }

   }
   //起点在二楼，终点在二楼
   else if(p.y()>127&&p.y()<260&&q.y()>127&&q.y()<260)
   {
       //求距离终点最近的点
       deal_end_near_point(q);
       m_painter2.drawLine(q,vector_point_2_copy[posmin]);

       //求距离起点s3最近的点
       if(p.x()==s3.x()&&p.y()==s3.y())
       {
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
       }
       //求距离起点s4最近的点
       else if(p.x()==s4.x()&&p.y()==s4.y())
       {
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
       }
   }
   //起点在二楼，终点在一楼
   else if(p.y()>127&&p.y()<260&&q.y()<127)
   {
       if(stairs_or_lift=0)
       {
           //起点是s3
           if(p==s3)
           {
               m_painter2.drawLine(p,ss3);
               p=ss1;
           }
           //起点是s4
           else if(p==s4)
           {
               m_painter2.drawLine(p,point_2_08);
               m_painter2.drawLine(point_2_08,point_2_05);
               m_painter2.drawLine(point_2_05,ss4);
               p=ss2;
           }
           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_1_copy[posmin]);

           //求距离起点s3最近的点
           if(p.x()==ss1.x()&&p.y()==ss1.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
           }
           //求距离起点s4最近的点
           else if(p.x()==ss2.x()&&p.y()==ss2.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
           }
       }
       else if(stairs_or_lift==1)
       {
           //起点是s3
           if(p==s3)
           {
               m_painter2.drawLine(p,point_2_02);
               m_painter2.drawLine(point_2_02,point_2_07);
               m_painter2.drawLine(point_2_07,l2);
               p=l1;
           }
           //起点是s4
           else if(p==s4)
           {
               m_painter2.drawLine(p,l2);
               p=l1;
           }

           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_1_copy[posmin]);

           //求距离起点（电梯l2）最近的点
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
       }
   }
   //起点在二楼，终点在三楼
   else if(p.y()>127&&p.y()<260&&q.y()>260)
   {
       if(stairs_or_lift==0)
       {
           //起点是s3
           if(p==s3)
           {
               m_painter2.drawLine(p,ss3);
               p=ss5;
           }
           //起点是s4
           else if(p==s4)
           {
               m_painter2.drawLine(p,point_2_08);
               m_painter2.drawLine(point_2_08,point_2_05);
               m_painter2.drawLine(point_2_05,ss4);
               p=ss6;
           }
           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_3_copy[posmin]);

           //求距离起点（楼梯ss5）最近的点
           if(p.x()==ss5.x()&&p.y()==ss5.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
           }
           //求距离起点（楼梯ss6）最近的点
           else if(p.x()==ss6.x()&&p.y()==ss6.y())
           {
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
           }
       }
       else if(stairs_or_lift==1)
       {
           //起点是s3
           if(p==s3)
           {
               m_painter2.drawLine(p,point_2_02);
               m_painter2.drawLine(point_2_02,point_2_07);
               m_painter2.drawLine(point_2_07,l2);
               p=l3;
           }
           //起点是s4
           else if(p==s4)
           {
               m_painter2.drawLine(p,l2);
               p=l3;
           }

           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_3_copy[posmin]);

           //求距离起点（电梯l2）最近的点
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
       }
   }
   //起点在三楼，终点在三楼
   else if(p.y()>260&&q.y()>260)
   {
       //求距离终点最近的点
       deal_end_near_point(q);
       m_painter2.drawLine(q,vector_point_3_copy[posmin]);
       //求距离起点s5最近的点
       deal_start_near_point(p);
       m_painter2.drawLine(p,vector_point_3_copy[start_near_record]);
   }
   //起点在三楼，终点在一楼
   else if(p.y()>260&&q.y()<127)
   {
       if(stairs_or_lift==0)
       {
           m_painter2.drawLine(p,ss6);
           p=ss2;
           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_1_copy[posmin]);
           //求距离起点ss2最近的点
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
       }
       else if(stairs_or_lift==1)
       {

               m_painter2.drawLine(p,point_3_03);
               m_painter2.drawLine(point_3_03,point_3_07);
               m_painter2.drawLine(point_3_07,l2);
               p=l1;



           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_1_copy[posmin]);

           //求距离起点（电梯l2）最近的点
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_1_copy[start_near_record]);
       }
   }
   //起点在三楼，终点在二楼
   else if(p.y()>260&&q.y()>127&&q.y()<260)
   {
       if(stairs_or_lift==0)
       {
           m_painter2.drawLine(p,ss6);
           p=ss4;
           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_2_copy[posmin]);
           //求距离起点（楼梯ss4）最近的点
           deal_start_near_point(p);
           m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
       }
       else if(stairs_or_lift==1)
       {

               m_painter2.drawLine(p,point_3_03);
               m_painter2.drawLine(point_3_03,point_3_07);
               m_painter2.drawLine(point_3_07,l2);
               p=l2;



           //求距离终点最近的点
           deal_end_near_point(q);
           m_painter2.drawLine(q,vector_point_2_copy[posmin]);

           //求距离起点（电梯l2）最近的点
               deal_start_near_point(p);
               m_painter2.drawLine(p,vector_point_2_copy[start_near_record]);
       }
   }
   //绘制A*路径，单层楼
   AStar *astar = new AStar(3,10,maze);
   //设置起始和结束点
   Point start(start_near__y, start_near__x);
   Point end(end_near__y, end_near__x);
   //A*算法找寻路径
   QVector<Point*> pp=astar->get_path(start,end);
   for(int i=0;i<pp.size();i++)
   {
       qDebug()<<pp[i]->X<<","<<pp[i]->Y;
   }
   //存储路径点
   for (auto &t : pp)
   {
       //maze[t->X][t->Y]=2;
       QPoint point;
       //设置存储几层楼的路径点
       if(p==s1||p==s2||p==ss1||p==ss2||p==l1)
       {
           point=vector_point_1[t->Y][t->X];
       }
       else if(p==ss3||p==ss4||p==s3||p==s4||p==l2)
       {
           point=vector_point_2[t->Y][t->X];
       }
       else if(p==ss5||p==ss6||p==s5||p==l3)
       {
           point=vector_point_3[t->Y][t->X];
       }

       storage.append(point);
   }
   //清空此次寻路路径
   for (auto &t : pp)
   {

       maze[t->Y][t->X]=0;
   }
   //画出存储路径
   for(int i=0;i<storage.length()-1;i++)
   {
       m_painter2.drawLine(storage[i],storage[i+1]);
   }
   //清空数组数据
   pp.clear();
   delete astar;
   deal_end_near.clear();
   deal_start_near.clear();
   qDebug()<<"画图";
}

void m_road::deal_end_near_point(QPoint q)
{
 if(q.y()<127)
 {
     for(int i=0;i<vector_point_1_copy.length();i++)
     {
         deal_end_near.append((q-vector_point_1_copy[i]).manhattanLength());
     }
     QVector<int>::iterator min=std::min_element(std::begin(deal_end_near),std::end(deal_end_near));
     auto positionmin=std::distance(std::begin(deal_end_near),min);
     posmin=positionmin;
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<10;j++)
         {
             if(vector_point_1[i][j].x()==vector_point_1_copy[posmin].x()&&vector_point_1[i][j].y()==vector_point_1_copy[posmin].y())
             {
                 end_near__x=i;
                 end_near__y=j;
             }
         }
     }

 }
 else if(q.y()<260&&q.y()>127)
 {
     //求距离终点最近的点
     for(int i=0;i<vector_point_2_copy.length();i++)
     {
         deal_end_near.append((q-vector_point_2_copy[i]).manhattanLength());
     }
     QVector<int>::iterator min=std::min_element(std::begin(deal_end_near),std::end(deal_end_near));
     auto positionmin=std::distance(std::begin(deal_end_near),min);
     posmin=positionmin;
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<10;j++)
         {
             if(vector_point_2[i][j].x()==vector_point_2_copy[posmin].x()&&vector_point_2[i][j].y()==vector_point_2_copy[posmin].y())
             {
                 end_near__x=i;
                 end_near__y=j;
             }
         }
     }
 }
 else if(q.y()>260)
 {
     for(int i=0;i<vector_point_3_copy.length();i++)
     {
         deal_end_near.append((q-vector_point_3_copy[i]).manhattanLength());
     }
     QVector<int>::iterator min=std::min_element(std::begin(deal_end_near),std::end(deal_end_near));
     auto positionmin=std::distance(std::begin(deal_end_near),min);
     posmin=positionmin;
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<10;j++)
         {
             if(vector_point_3[i][j].x()==vector_point_3_copy[posmin].x()&&vector_point_3[i][j].y()==vector_point_3_copy[posmin].y())
             {
                 end_near__x=i;
                 end_near__y=j;
             }
         }
     }
 }
}

void m_road::deal_start_near_point(QPoint p)
{
    if(p==s1)
    {
        deal_start_near.append((p-vector_point_1_copy[2]).manhattanLength()+(vector_point_1_copy[2]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[3]).manhattanLength()+(vector_point_1_copy[3]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[22]).manhattanLength()+(vector_point_1_copy[22]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[23]).manhattanLength()+(vector_point_1_copy[23]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
           start_near_record=2;
           deal_start_near_point_point=vector_point_1_copy[2];
            break;
        case 1:
             start_near_record=3;
             deal_start_near_point_point=vector_point_1_copy[3];
            break;
        case 2:
             start_near_record=22;
             deal_start_near_point_point=vector_point_1_copy[22];
            break;
        case 3:
             start_near_record=23;
             deal_start_near_point_point=vector_point_1_copy[23];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_1);
    }
    else if(p==s2)
    {
        deal_start_near.append((p-vector_point_1_copy[5]).manhattanLength()+(vector_point_1_copy[5]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[6]).manhattanLength()+(vector_point_1_copy[6]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[25]).manhattanLength()+(vector_point_1_copy[25]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[26]).manhattanLength()+(vector_point_1_copy[26]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=5;
           deal_start_near_point_point=vector_point_1_copy[5];
            break;
        case 1:
            start_near_record=6;
             deal_start_near_point_point=vector_point_1_copy[6];
            break;
        case 2:
            start_near_record=25;
             deal_start_near_point_point=vector_point_1_copy[25];
            break;
        case 3:
            start_near_record=26;
             deal_start_near_point_point=vector_point_1_copy[26];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_1);
    }
    else if(p==ss3)
    {
        deal_start_near.append((p-vector_point_2_copy[0]).manhattanLength()+(vector_point_2_copy[0]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[1]).manhattanLength()+(vector_point_2_copy[1]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[20]).manhattanLength()+(vector_point_2_copy[20]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[21]).manhattanLength()+(vector_point_2_copy[21]-vector_point_2_copy[posmin]).manhattanLength());
       deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=0;
           deal_start_near_point_point=vector_point_2_copy[0];
            break;
        case 1:
             start_near_record=1;
             deal_start_near_point_point=vector_point_2_copy[1];
            break;
        case 2:
             start_near_record=20;
             deal_start_near_point_point=vector_point_2_copy[20];
            break;
        case 3:
             start_near_record=21;
             deal_start_near_point_point=vector_point_2_copy[21];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_2);
    }
    else if(p==ss4)
    {
        deal_start_near.append((p-vector_point_2_copy[5]).manhattanLength()+(vector_point_2_copy[5]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[25]).manhattanLength()+(vector_point_2_copy[26]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=5;
            deal_start_near_point_point=vector_point_2_copy[5];
            break;
        case 1:
            start_near_record=25;
            deal_start_near_point_point=vector_point_2_copy[25];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_2);
    }
    else if(p==ss5)
    {
        deal_start_near.append((p-vector_point_3_copy[0]).manhattanLength()+(vector_point_3_copy[0]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[1]).manhattanLength()+(vector_point_3_copy[1]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[20]).manhattanLength()+(vector_point_3_copy[20]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[21]).manhattanLength()+(vector_point_3_copy[21]-vector_point_3_copy[posmin]).manhattanLength());
       deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=0;
           deal_start_near_point_point=vector_point_3_copy[0];
            break;
        case 1:
             start_near_record=1;
             deal_start_near_point_point=vector_point_3_copy[1];
            break;
        case 2:
             start_near_record=20;
             deal_start_near_point_point=vector_point_3_copy[20];
            break;
        case 3:
             start_near_record=21;
             deal_start_near_point_point=vector_point_3_copy[21];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_3);
    }
    else if(p==ss6)
    {
        deal_start_near.append((p-vector_point_3_copy[4]).manhattanLength()+(vector_point_3_copy[4]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[24]).manhattanLength()+(vector_point_3_copy[24]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[5]).manhattanLength()+(vector_point_3_copy[5]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[25]).manhattanLength()+(vector_point_3_copy[25]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=4;
            deal_start_near_point_point=vector_point_3_copy[4];
            break;
        case 1:
            start_near_record=24;
            deal_start_near_point_point=vector_point_3_copy[24];
            break;
        case 2:
            start_near_record=5;
            deal_start_near_point_point=vector_point_3_copy[5];
            break;
        case 3:
            start_near_record=25;
            deal_start_near_point_point=vector_point_3_copy[25];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_3);
    }
    else if(p==s3)
    {
        deal_start_near.append((p-vector_point_2_copy[2]).manhattanLength()+(vector_point_2_copy[2]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[22]).manhattanLength()+(vector_point_2_copy[22]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=2;
            deal_start_near_point_point=vector_point_2_copy[2];
            break;
        case 1:
            start_near_record=22;
            deal_start_near_point_point=vector_point_2_copy[22];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_2);
    }
    else if(p==s4)
    {
        deal_start_near.append((p-vector_point_2_copy[8]).manhattanLength()+(vector_point_2_copy[8]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[28]).manhattanLength()+(vector_point_2_copy[28]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=8;
            deal_start_near_point_point=vector_point_2_copy[8];
            break;
        case 1:
            start_near_record=28;
            deal_start_near_point_point=vector_point_2_copy[28];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_2);
    }
    else if(p==ss1)
    {
        deal_start_near.append((p-vector_point_1_copy[0]).manhattanLength()+(vector_point_1_copy[0]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[1]).manhattanLength()+(vector_point_1_copy[1]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[20]).manhattanLength()+(vector_point_1_copy[20]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[21]).manhattanLength()+(vector_point_1_copy[21]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
           start_near_record=0;
           deal_start_near_point_point=vector_point_1_copy[0];
            break;
        case 1:
             start_near_record=1;
             deal_start_near_point_point=vector_point_1_copy[1];
            break;
        case 2:
             start_near_record=20;
             deal_start_near_point_point=vector_point_1_copy[20];
            break;
        case 3:
             start_near_record=21;
             deal_start_near_point_point=vector_point_1_copy[21];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_1);
    }
    else if(p==ss2)
    {
        deal_start_near.append((p-vector_point_1_copy[4]).manhattanLength()+(vector_point_1_copy[4]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[5]).manhattanLength()+(vector_point_1_copy[5]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[24]).manhattanLength()+(vector_point_1_copy[24]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[25]).manhattanLength()+(vector_point_1_copy[25]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
           start_near_record=4;
           deal_start_near_point_point=vector_point_1_copy[4];
            break;
        case 1:
             start_near_record=5;
             deal_start_near_point_point=vector_point_1_copy[5];
            break;
        case 2:
           start_near_record=24;
           deal_start_near_point_point=vector_point_1_copy[24];
            break;
        case 3:
             start_near_record=25;
             deal_start_near_point_point=vector_point_1_copy[25];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_1);
    }
    else if(p==s5)
    {
        deal_start_near.append((p-vector_point_3_copy[3]).manhattanLength()+(vector_point_3_copy[3]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[23]).manhattanLength()+(vector_point_3_copy[23]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=3;
            deal_start_near_point_point=vector_point_3_copy[3];
            break;
        case 1:
            start_near_record=23;
            deal_start_near_point_point=vector_point_3_copy[23];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_3);
    }
    else if(p==l2)
    {
        deal_start_near.append((p-vector_point_2_copy[7]).manhattanLength()+(vector_point_2_copy[7]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_2_copy[27]).manhattanLength()+(vector_point_2_copy[27]-vector_point_2_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=7;
            deal_start_near_point_point=vector_point_2_copy[7];
            break;
        case 1:
            start_near_record=27;
            deal_start_near_point_point=vector_point_2_copy[27];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_2);
    }
    else if(p==l3)
    {
        deal_start_near.append((p-vector_point_3_copy[7]).manhattanLength()+(vector_point_3_copy[7]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_3_copy[27]).manhattanLength()+(vector_point_3_copy[27]-vector_point_3_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=7;
            deal_start_near_point_point=vector_point_3_copy[7];
            break;
        case 1:
            start_near_record=27;
            deal_start_near_point_point=vector_point_3_copy[27];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_3);
    }
    else if(p==l2)
    {
        deal_start_near.append((p-vector_point_1_copy[7]).manhattanLength()+(vector_point_1_copy[7]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near.append((p-vector_point_1_copy[27]).manhattanLength()+(vector_point_1_copy[27]-vector_point_1_copy[posmin]).manhattanLength());
        deal_start_near_point_simplify2();
        switch (posmin2) {
        case 0:
            start_near_record=7;
            deal_start_near_point_point=vector_point_1_copy[7];
            break;
        case 1:
            start_near_record=27;
            deal_start_near_point_point=vector_point_1_copy[27];
            break;
        default:
            break;
        }
        //对应点
        deal_start_near_point_simplify(vector_point_1);
    }
}

void m_road::deal_start_near_point_simplify(QVector<QVector<QPoint>> v)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(v[i][j].x()==deal_start_near_point_point.x()&&v[i][j].y()==deal_start_near_point_point.y())
            {
                start_near__x=i;
                start_near__y=j;
            }
        }
    }
}

void m_road::deal_start_near_point_simplify2()
{
    QVector<int>::iterator min2=std::min_element(std::begin(deal_start_near),std::end(deal_start_near));
    auto positionmin2=std::distance(std::begin(deal_start_near),min2);
    posmin2=positionmin2;

}
void m_road::drawimage()
{
    drawline(start_point,end_point);
    qDebug()<<"line已经画了图片";
    emit updateimage(image1);
}
