cmake_minimum_required(VERSION 3.12)
project(logTest)

ADD_DEFINITIONS( -O3 )

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "~/work/boost")

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED COMPONENTS log thread)

add_executable(logTest test.cpp)

target_link_directories(logTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../build/)

target_link_libraries(logTest PRIVATE async_log_cpp ${Boost_LIBRARIES})
