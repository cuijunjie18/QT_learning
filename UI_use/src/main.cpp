#include <QApplication>
#include <QWidget>
#include <ui_demo.h>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QMainWindow q;

    Ui::MainWindow a;
    a.setupUi(&q);
    q.show();

    return app.exec();
}