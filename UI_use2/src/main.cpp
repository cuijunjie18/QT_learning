#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include "my_window.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    CJJ_Window a;
    a.show();

    return app.exec();
}