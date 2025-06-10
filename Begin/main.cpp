#include <QApplication>
#include <QWidget>
 
int main(int argc, char *argv[])
{
	QApplication app(argc, argv); //初始化
	
	QWidget w;
	w.show();
	
	app.exec(); //主事件循环
	
	return 0;
}