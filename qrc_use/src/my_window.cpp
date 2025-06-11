#include "my_window.h"
#include <QWidget>

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 法一
    set_icon(":/icons/stop.png");

    // 法二
    set_icon("resources/icons/stop.png");
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::set_icon(const QString &filename){
    ui->pushButton->setFixedSize(200,200);
    ui->pushButton->setIcon(QIcon(filename));
    ui->pushButton->setIconSize(QSize(200,200));
    ui->pushButton->setStyleSheet(
        // "background-color: rgba(0,0,0,0);"
        "background-color: transparent;"
        "border: none;"
    );
}