## 资源文件的添加

### 背景

qt自带的资源文件的使用方法效率会比直接指定路径要高

### 编写资源文件

模板如下

```vim
<!DOCTYPE RCC>
<RCC version="1.0">
    <qresource prefix="/">
        <file>icons/stop.png</file>
    </qresource>
</RCC>
```

要求的目录结构如下

```shell
├── resources
│   ├── icons
│   │   └── stop.png
│   └── res.qrc
```

### .pro文件中添加资源文件

```vim
# Input
FORMS += UI/demo.ui
SOURCES += src/main.cpp
RESOURCES += resources/res.qrc
```

### 两种路径使用方法

```cpp
    // 法一
    set_icon(":/icons/stop.png");

    // 法二
    set_icon("resources/icons/stop.png");
```

## deepseek对资源文件解释

在Qt中，这两种资源使用方法有本质区别，分别对应不同的资源管理机制：

### 1. `":/icons/stop.png"` (Qt资源系统)
```cpp
set_icon(":/icons/stop.png");
```
- **编译时嵌入**：资源被编译进可执行文件二进制中
- **路径特征**：以冒号开头的虚拟路径 (`:/`)
- **需要配置**：必须在`.qrc`文件中声明：
  ```xml
  <RCC>
    <qresource prefix="/icons">
      <file>resources/icons/stop.png</file>
    </qresource>
  </RCC>
  ```
- **优点**：
  - 程序单文件分发，无需额外资源文件
  - 资源路径固定，不受部署环境影响
  - 访问速度快（内存读取）
- **缺点**：
  - 增大可执行文件体积
  - 修改资源需重新编译程序
  - 无法动态更新资源

### 2. `"resources/icons/stop.png"` (文件系统路径)
```cpp
set_icon("resources/icons/stop.png");
```
- **运行时加载**：从磁盘文件系统读取
- **路径特征**：普通相对/绝对路径
- **无需配置**：不需要`.qrc`文件支持
- **优点**：
  - 可执行文件体积小
  - 资源可动态替换（热更新）
  - 便于管理大量资源（如图片/视频）
- **缺点**：
  - 部署需附带资源文件夹
  - 路径依赖工作目录（可能找不到文件）
  - 读取速度慢于内存访问

---

### ✅ 关键区别总结

| 特性               | `:/` 资源系统                     | 文件系统路径                  |
|--------------------|----------------------------------|------------------------------|
| **资源位置**       | 嵌入可执行文件内部               | 外部独立文件                 |
| **部署要求**       | 只需单个可执行文件              | 需附带资源文件夹             |
| **运行时修改**     | 不可能                          | 可直接替换文件               |
| **加载速度**       | ★★★ 快（内存读取）              | ★☆☆ 慢（磁盘I/O）           |
| **适用场景**       | 核心图标/小体积静态资源         | 大文件/需动态更新的资源      |
| **路径基准**       | 相对于.qrc资源根                | 相对于工作目录               |

---

### 工作目录问题详解（文件系统路径常见陷阱）
当使用 `"resources/icons/stop.png"` 时：
```cpp
// 依赖当前工作目录（Working Directory）
QDir::currentPath(); // 决定相对路径的基准
```
- **调试时**：IDE通常将构建目录设为工作目录
- **发布后**：工作目录可能是：
  - Windows：可执行文件所在目录
  - macOS：`YourApp.app/Contents/MacOS/`
  - Linux：执行命令的终端路径

**解决方案**（确保找到文件）：
```cpp
// 方法1：使用应用程序目录绝对路径
QString appDir = QCoreApplication::applicationDirPath();
set_icon(appDir + "/resources/icons/stop.png");

// 方法2：使用Qt资源路径（推荐）
set_icon(":/icons/stop.png"); // 最可靠的方案
```

---

### 最佳实践建议
1. **小型静态资源**（图标/UI文件/翻译）：
   ```cpp
   // 使用资源系统，避免部署问题
   set_icon(":/icons/stop.png");
   ```

2. **大型动态资源**（用户文档/下载内容）：
   ```cpp
   // 使用绝对文件路径
   QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
   set_icon(path + "/user_content/stop.png");
   ```

3. **混合使用**（开发期文件系统，发布版嵌入）：
   ```cpp
   #ifdef QT_DEBUG
       set_icon("resources/icons/stop.png");  // 调试时从文件加载
   #else
       set_icon(":/icons/stop.png");          // 发布版用嵌入资源
   #endif
   ```

> 💡 **重要提示**：使用文件系统路径时，务必通过`QFile::exists()`检查文件是否存在，避免静默失败！