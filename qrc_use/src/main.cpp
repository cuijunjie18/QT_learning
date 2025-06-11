#include <QApplication>
#include <QMainWindow>
#include "my_window.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    MainWindow my_window;
    my_window.show();

    return app.exec();
}