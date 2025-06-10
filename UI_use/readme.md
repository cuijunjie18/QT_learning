## UI使用

### uic编译.ui文件

```shell
uic demo.ui > demo.h
```

### ui头文件使用

```cpp
    QMainWindow q;
    Ui_MainWindow a;
    a.setupUi(&q);  / 将对应的UI设置在主窗口
    q.show();
```