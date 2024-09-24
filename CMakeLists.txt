cmake_minimum_required(VERSION 3.12)
project(async_log_cpp)

# 优化编译项
ADD_DEFINITIONS( -O3 )

# 引入C++17 库
set(CMAKE_CXX_STANDARD 17)

# 生成位置无关代码
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 指定boost查找的根路径
set(CMAKE_PREFIX_PATH "/home/wujiaxiang/work/boost")

# 找boost的组件
find_package(Boost REQUIRED COMPONENTS log)

# 源文件
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 导入源文件，编译成库
add_library(async_log_cpp ${SOURCES})

# 链接boost头文件路径
target_include_directories(async_log_cpp PRIVATE ${Boost_INCLUDE_DIRS})

# 链接相关库
target_link_libraries(async_log_cpp PRIVATE ${Boost_LIBRARIES})