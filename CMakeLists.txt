cmake_minimum_required(VERSION 3.14)
# 1. 项目名称已更改
project(SpecGAN LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 寻找 Qt5 和 OpenCV ---
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenCV REQUIRED)

# --- 配置我们项目自己的 RKNN 头文件 ---
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- 启用 Qt 的自动工具 ---
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# --- 添加源文件 ---
# 2. 可执行文件名已更改
add_executable(SpecGAN
    src/main.cpp
    src/MainWindow.h
    src/MainWindow.cpp
    src/MainWindow.ui
    src/RknnProcessor.h
    src/RknnProcessor.cpp
)

# --- 链接所有需要的库 ---
# 3. 链接目标名已更改
target_link_libraries(SpecGAN
    PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    ${OpenCV_LIBS}
    rknnrt
)

# --- 安装规则 ---

# 1. 安装可执行文件
# 将编译好的 SpecGAN 程序安装到系统的 /usr/local/bin 目录
install(TARGETS SpecGAN
    RUNTIME DESTINATION bin
)

# 2. 安装模型文件
# 将 models 文件夹及其内容安装到 /usr/local/share/SpecGAN/ 目录下
install(DIRECTORY models
    DESTINATION share/SpecGAN
)

# 3. 安装桌面快捷方式
# 将我们创建的 .desktop 文件安装到系统能识别的应用程序目录
install(FILES SpecGAN.desktop
    DESTINATION share/applications
)

# 4. 安装图标
# 将 icon.png 文件安装到系统的图标目录，并重命名为 SpecGAN.png
install(FILES icon.png
    DESTINATION share/pixmaps
    RENAME SpecGAN.png
)
