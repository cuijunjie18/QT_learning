#include <QApplication>
#include <QWidget>
#include <QPushButton> //按钮所需头文件
 
int main(int argc, char *argv[])
{
	QApplication app(argc, argv); //初始化
	
	QWidget w;
	w.show();
	
	//新增的代码
	//创建一个内容为"^_^"的按钮，需要头文件：#include <QPushButton>
	QPushButton button("^_^"); 
	
	//按钮指定窗口为其父对象，即按钮放在窗口上
	button.setParent(&w);
	
	button.show(); //显示按钮
	
	
	app.exec(); //主事件循环
	
	return 0;
}