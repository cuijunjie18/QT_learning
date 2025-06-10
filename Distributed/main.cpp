#include <QApplication>
#include "mywidget.h"//自定义类的头文件
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w; //创建MyWidget的对象
    w.show();
 
    return a.exec();
}