## UI使用2——将UI的一些对象的信号连接到槽函数

### 标准结构

```shell
.
├── bin
│   └── UI_use2
├── build
│   ├── main.o
│   ├── moc_my_window.o
│   └── my_window.o
├── build.sh
├── compile_commands.json
├── include
│   ├── moc_predefs.h
│   ├── my_window.h
│   └── ui_cjj.h
├── Makefile
├── moc_my_window.cpp
├── readme.md
├── src
│   ├── main.cpp
│   └── my_window.cpp
├── UI
│   └── cjj.ui
└── UI_use2.pro
```

### 细节注意

- 注意.pro中自动生成的头文件影响，每次会覆盖自己的修改，所以建议用手动生成
- 标准的my_window.h如下
```cpp
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

private slots:
    void onActionButtonClicked();

private:
    Ui::CJJ_Form *ui; // 指向 UI 对象的指针
};

#endif // MAINWINDOW_H
```

由于用了一些非c++原生的语法，所以需要在.pro文件中指定需要通过moc编译的头文件

```vim
HEADERS += include/my_window.h
```