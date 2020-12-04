cmake_minimum_required(VERSION 3.17)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../so)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

include_directories("/usr/local/include ${JNI_INCLUDE_DIRS}")
link_directories("/usr/local/lib")

add_library(cpp SHARED nsu_fit_CpuInfo.h CpuInfo.cpp)

target_link_libraries(cpp ${JNI_LIBRARIES})

target_include_directories(cpp PUBLIC ${JNI_INCLUDE_DIRS})
