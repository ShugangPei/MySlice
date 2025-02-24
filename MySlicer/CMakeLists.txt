cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(MySlicer VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 添加可执行文件
add_executable(MySlicer src/main.cpp src/STLReader.cpp src/Point3D.cpp)
