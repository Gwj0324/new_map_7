#include "widget.h"
#include <QApplication>
#include <QFile>
#include <vld.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加载样式表
    QFile file(":/StyleSheet/style.css");
    file.open(QIODevice::ReadOnly);
    QString css =file.readAll();
    qApp->setStyleSheet(css);
    file.close();

    Widget w;

    return a.exec();
}
