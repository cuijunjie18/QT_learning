#include "mywidget.h"
 
//构造函数
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)//通过参数列表给基类构造函数传参
{
	button.setText("^_^"); //设置按钮的内容"^_^"
	
	//指定父对象
	//this指向主函数( main() )的对象w
	//最终button放在w窗口的上面
	button.setParent(this);
}
 
//析构函数
MyWidget::~MyWidget()
{
 
}