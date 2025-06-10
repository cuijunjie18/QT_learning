#include "my_window.h"
#include "ui_cjj.h"
#include <QMessageBox>
#include <QTime>
#include <unistd.h>

CJJ_Window::CJJ_Window(QWidget *parent)
    : QMainWindow(parent), 
    ui(new Ui::CJJ_Form) // 创建 UI 对象
{
    ui->setupUi(this); // 设置 UI
    
    // 连接按钮信号到槽函数
    connect(ui->pushButton, &QPushButton::clicked, 
            this, &CJJ_Window::onActionButtonClicked);

    // 连接关闭按钮
    connect(ui->pushButton_2, &QPushButton::clicked,
            this,&CJJ_Window::Test);
}

CJJ_Window::~CJJ_Window() {
    delete ui; // 删除 UI 对象
}

void CJJ_Window::Test(){
    QMessageBox::information(this,NULL,"3秒后关闭窗口");
    sleep(3);
    exit(0);
}

void CJJ_Window::onActionButtonClicked() {
    QMessageBox::information(this, "操作成功", "你点击了按钮！");
    // ui->statuslabel->setText("状态: 按钮已点击 (" + QTime::currentTime().toString() + ")");
    // ui->statuslabel->setStyleSheet("color: #27ae60; font-size: 16px;");
}