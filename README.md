
# SpecGAN: AI光谱图像生成工具

`SpecGAN` 是一款专为实验室环境打造的高性能桌面应用程序。它采用现代化的深色主题UI，通过瑞芯微（Rockchip）NPU 对基于 Pix2Pix (GAN) 的深度学习模型进行硬件加速，为科研人员提供了一个专业、高效、直观的光谱图像转换与生成解决方案。

本应用基于 C++ 和 Qt 框架开发，充分释放了嵌入式设备的AI算力。


---

## ✨ 功能特性

* **现代化UI设计**: 采用“未来科技实验室”风格的深色主题，提供沉浸式、专业的视觉体验。
* **高性能推理**: 基于瑞芯微 NPU 进行硬件加速，实现毫秒级的模型推理，告别漫长等待。
* **专业领域聚焦**: 专为光谱图像的 Pix2Pix 转换任务设计，精准服务科研需求。
* **直观交互流程**: 清晰的“选择-转换-保存”三步操作，无需学习成本即可上手。
* **完整部署方案**: 支持编译后一键安装到系统，可像原生软件一样从桌面菜单直接启动和卸载。

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
    * `librknnrt.so`: 运行时库，通常已包含在开发板的固件中。
    * `rknn_api.h`: C API 头文件，需要您从官方SDK中获取并放置在项目的 `include/` 目录下。

---

## 🚀 如何使用

### 方式一：直接运行 (开发模式)

1.  **克隆项目**
    ```bash
    git clone <https://github.com/Bruce-USTC/gan_qt_app>
    cd gan_qt_app
    ```

2.  **编译项目**
    ```bash
    mkdir build
    cd build
    cmake ..
    make -j4
    ```

3.  **运行程序**
    编译成功后，请**返回到项目根目录**运行程序：
    ```bash
    cd ..
    ./build/SpecGAN
    ```

### 方式二：安装到系统后使用 (推荐)

1.  **准备文件**
    确保项目根目录下有 `icon.png` (应用图标) 和 `SpecGAN.desktop` (桌面快捷方式) 文件。

2.  **编译项目**
    请先按照上面的步骤完成编译。

3.  **安装项目**
    在 `build` 目录下，执行安装命令（需要管理员权限）：
    ```bash
    sudo make install
    ```

4.  **从桌面菜单启动**
    安装成功后，您可以点击桌面左下角的应用程序菜单，或在“图形”“科学”分类下找到名为 **“SpecGAN Tool”** 的图标，直接点击即可启动。

5.  **卸载程序**
    若要卸载，同样在 `build` 目录下执行：
    ```bash
    sudo make uninstall
    ```

---

## 📁 项目结构

````


├── build/              \# 编译产物目录
├── include/
│   └── rknn\_api.h      \# RKNN API 头文件
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
└── README.md           \# 本文档

````

---

## 📄 许可 (License)

本项目采用 [MIT](https://choosealicense.com/licenses/mit/) 许可。
