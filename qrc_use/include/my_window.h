#ifndef MY_WINDOW_H
#define MY_WINDOW_H

#include "ui_demo.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_icon(const QString &filename);
private slots:

private:
    Ui::MainWindow *ui;
};

#endif