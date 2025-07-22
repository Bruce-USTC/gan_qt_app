# SpecGAN: 光谱图像转换工具

`SpecGAN` 是一个专为实验室环境设计的桌面应用程序。它利用瑞芯微（Rockchip）NPU 对基于 Pix2Pix (GAN) 的深度学习模型进行加速，实现对光谱图像的快速转换与生成。

本应用基于 C++ 和 Qt 框架开发，提供了一个简洁直观的图形用户界面，方便科研人员进行操作。

---

## ✨ 功能特性

* **图形用户界面 (GUI)**: 提供简单易用的“选择-转换-保存”三步操作流程。
* **高性能**: 基于瑞芯微 NPU 进行硬件加速，实现毫秒级模型推理。
* **专业领域**: 专为光谱图像的 Pix2Pix 转换任务设计。
* **跨平台**: 基于 Qt 开发，具备良好的跨平台潜力。
* **易于部署**: 支持编译后安装到系统，可从桌面菜单直接启动。

---

## 🛠️ 环境依赖与准备 (Prerequisites)

在编译和运行本项目前，请确保您的开发板（目标设备）已安装以下环境：

* **硬件**: 一块搭载了瑞芯微 NPU 的开发板 (例如: LubanCat-5, RK3588)。
* **操作系统**: 带有桌面环境的 Linux 系统 (例如: Ubuntu 20.04)。
* **核心编译工具**:

```bash
sudo apt-get install build-essential cmake git
```

* **Qt5 开发套件**:

```bash
sudo apt-get install qtcreator qtbase5-dev
```

* **OpenCV 开发库**:

```bash
sudo apt-get install libopencv-dev
```

* **RKNN 库**:
    * `librknn.so`: 运行库，通常已包含在开发板的固件中。
    * `rknn_api.h`: C API 头文件，需要您从官方SDK中获取并放置在项目的 `include/` 目录下。

---

## 🚀 如何使用

### 方式一：直接运行 (开发模式)

1. **克隆项目**

```bash
git clone <你的项目仓库地址>
cd gan_qt_app
```

2. **编译项目**

```bash
mkdir build
cd build
cmake ..
make -j4
```

3. **运行程序**
编译成功后，请**返回到项目根目录**运行程序：

```bash
cd ..
./build/SpecGAN
```


### 方式二：安装到系统后使用 (推荐)

1. **编译项目**
请先按照上面的步骤完成编译。
2. **安装项目**
在 `build` 目录下，执行安装命令（需要管理员权限）：

```bash
sudo make install
```

3. **从桌面菜单启动**
安装成功后，您可以点击桌面左上角的应用程序菜单，在“图形”或“科学”分类下找到名为 **“SpecGAN Tool”** 的图标，直接点击即可启动。

---

## 📁 项目结构

├── build/              \# 编译产物目录
├── include/
│   └── rknn_api.h      \# RKNN API 头文件
├── models/
│   └── ... .rknn       \# 存放 .rknn 模型文件
├── src/
│   ├── MainWindow.cpp  \# 主窗口实现
│   ├── MainWindow.h    \# 主窗口定义
│   ├── MainWindow.ui   \# UI 界面文件
│   ├── RknnProcessor.cpp \# RKNN 处理器实现
│   ├── RknnProcessor.h \# RKNN 处理器定义
│   └── main.cpp        \# 程序主入口
├── CMakeLists.txt      \# 项目编译配置文件
├── SpecGAN.desktop     \# 桌面快捷方式文件
├── icon.png            \# 应用程序图标
└── README. md           \# 本文档

## 📄 许可 (License)

本项目采用 [MIT](https://choosealicense.com/licenses/mit/) 许可。

