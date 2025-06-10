## UI使用

### 生成.ui文件

在 Ubuntu 内置的QT5-designer中设计好UI后保存，即为.ui文件了

### 获取.ui文件对应的.h头文件

- 法一：手动编译
```shell
uic demo.ui > demo.h
```

- 法二：在qt的.pro文件中指定.ui文件
```vim
FORMS += UI/demo.ui
qmake
```

### ui头文件使用

```cpp
    QMainWindow q;
    Ui_MainWindow a;
    a.setupUi(&q);  / 将对应的UI设置在主窗口
    q.show();
```