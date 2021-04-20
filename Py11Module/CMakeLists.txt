cmake_minimum_required(VERSION 3.0.0)
project(Algorithm VERSION 0.1.0)

# 设置so库输出的位置
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python)

# 添加pybind11
find_package(pybind11 REQUIRED)

# 添加执行
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCES)
aux_source_directory(${PROJECT_SOURCE_DIR}/in INC)
pybind11_add_module(${PROJECT_NAME} ${SOURCES} ${INC})

# 添加头文件
target_include_directories(${PROJECT_NAME} PUBLIC ./inc)

# 链接了非本目录下的文件，需要上层cmakelists文件。
target_link_libraries(${PROJECT_NAME} PUBLIC lib::Sort sharedlib::UnionFind lib::Util pybind11::headers)