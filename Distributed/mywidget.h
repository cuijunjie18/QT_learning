#ifndef MYWIDGET_H
#define MYWIDGET_H
 
#include <QWidget>
#include <QPushButton>//按钮所需头文件
 
//MyWidget公有继承于QWidget，既是说MyWidget也是一个窗口类
class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);//参数主要用于给基类构造函数传参
    ~MyWidget(); //析构函数
	
	QPushButton button;//定义一个按钮对象
	
};
 
#endif // MYWIDGET_H