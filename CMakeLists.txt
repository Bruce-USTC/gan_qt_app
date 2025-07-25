cmake_minimum_required(VERSION 3.14)
# 项目名称统一为 SpecGAN
project(SpecGAN LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 寻找 Qt5 和 OpenCV 依赖 ---
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenCV REQUIRED)

# --- 配置 RKNN 头文件路径 ---
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- 启用 Qt 的自动工具 ---
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# --- 定义可执行文件及其源文件 ---
add_executable(SpecGAN
    src/main.cpp
    src/MainWindow.h
    src/MainWindow.cpp
    src/MainWindow.ui
    src/RknnProcessor.h
    src/RknnProcessor.cpp
)

# --- 链接所有需要的库 ---
target_link_libraries(SpecGAN
    PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    ${OpenCV_LIBS}
    rknnrt 
)

# =====================================================
# --- 安装规则 (当执行 "sudo make install") ---
# =====================================================

# 1. 安装可执行文件到 /usr/local/bin
install(TARGETS SpecGAN
    RUNTIME DESTINATION bin
)

# 2. 安装模型文件夹到 /usr/local/share/SpecGAN/
install(DIRECTORY models
    DESTINATION share/SpecGAN
)

# 3. 安装桌面快捷方式到 /usr/share/applications
install(FILES SpecGAN.desktop
    DESTINATION share/applications
)

# 4. 安装图标到 /usr/share/pixmaps
install(FILES icon.png
    DESTINATION share/pixmaps
    RENAME SpecGAN.png
)

# =======================================================
# --- 卸载规则 (当执行 "sudo make uninstall") ---
# =======================================================

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E remove "/usr/local/bin/SpecGAN"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "/usr/local/share/SpecGAN"
    COMMAND ${CMAKE_COMMAND} -E remove "/usr/share/applications/SpecGAN.desktop"
    COMMAND ${CMAKE_COMMAND} -E remove "/usr/share/pixmaps/SpecGAN.png"
    COMMENT "正在卸载 SpecGAN..."
)
