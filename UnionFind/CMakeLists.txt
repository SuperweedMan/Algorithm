cmake_minimum_required(VERSION 3.0.0)
project(UnionFind VERSION 0.1.0)

# 添加源文件
aux_source_directory(./src SOURCE)

# 生成静态库
add_library(${PROJECT_NAME} STATIC ${SOURCE})
add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
add_library(${PROJECT_NAME}shared SHARED ${SOURCE})
add_library(sharedlib::${PROJECT_NAME} ALIAS ${PROJECT_NAME}shared)

# 链接静态库  因为应用到了同层的库，所以只能被上一层的引用
target_link_libraries(${PROJECT_NAME} PUBLIC lib::Util)
target_link_libraries(${PROJECT_NAME}shared PUBLIC lib::Util)

# 添加头文件
target_include_directories(${PROJECT_NAME} PUBLIC ./inc)
target_include_directories(${PROJECT_NAME}shared PUBLIC ./inc)