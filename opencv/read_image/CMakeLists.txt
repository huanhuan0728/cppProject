cmake_minimum_required(VERSION 3.10)
project(CameraApp)

# 查找 OpenCV 包，确保 OpenCV 已经安装
find_package(OpenCV REQUIRED)

# 指定生成的可执行文件和源文件
add_executable(camera_app camera_app.cpp)

# 链接 OpenCV 库到你的项目
target_link_libraries(camera_app ${OpenCV_LIBS})
