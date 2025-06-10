#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 前向声明 UI 命名空间
namespace Ui {
    class CJJ_Form;
}

class CJJ_Window : public QMainWindow {
    Q_OBJECT

public:
    explicit CJJ_Window(QWidget *parent = nullptr);
    ~CJJ_Window();
    void Test();

private slots:
    void onActionButtonClicked();

private:
    Ui::CJJ_Form *ui; // 指向 UI 对象的指针
};

#endif // MAINWINDOW_H