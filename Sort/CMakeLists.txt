cmake_minimum_required(VERSION 3.0.0)
project(Sort VERSION 0.1.0)

# 添加源文件
aux_source_directory(./src SOURCE)


# 生成库
add_library(${PROJECT_NAME} INTERFACE)
add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} INTERFACE lib::Util)
target_include_directories(${PROJECT_NAME} INTERFACE ./inc)

# 生成库
# add_library(${PROJECT_NAME} STATIC ${SOURCE})
# add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
# add_library(${PROJECT_NAME}shared SHARED ${SOURCE})
# add_library(sharedlib::${PROJECT_NAME} ALIAS ${PROJECT_NAME}shared)
# add_library(${PROJECT_NAME} STATIC ${SOURCE})
# add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# 链接静态库
# target_link_libraries(${PROJECT_NAME}shared PUBLIC lib::Util)
# target_link_libraries(${PROJECT_NAME} PUBLIC lib::Util)

# 添加头文件
# target_include_directories(${PROJECT_NAME} PUBLIC ./inc)
# target_include_directories(${PROJECT_NAME}shared PUBLIC ./inc)
# target_include_directories(${PROJECT_NAME} PUBLIC ./inc)