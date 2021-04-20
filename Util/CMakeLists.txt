cmake_minimum_required(VERSION 3.0.0)
project(Util VERSION 0.1.0)

# 添加源文件
aux_source_directory(./src SOURCE)

# 生成静态库
add_library(${PROJECT_NAME} STATIC ${SOURCE})
add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# 添加头文件
target_include_directories(${PROJECT_NAME} PUBLIC ./inc)
