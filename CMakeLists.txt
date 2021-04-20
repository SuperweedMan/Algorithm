cmake_minimum_required(VERSION 3.0.0)
project(AlgorithmTop VERSION 0.1.0)

include(CTest)
enable_testing()

# 对所有target增加定义
add_compile_options(-DDEBUG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 添加子工程
add_subdirectory(Sort)
add_subdirectory(UnionFind)
add_subdirectory(Util)
add_subdirectory(Py11Module)


# # 添加pybind11
# find_package(pybind11 REQUIRED)

# # 添加执行
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC lib::Sort lib::UnionFind lib::Util)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
