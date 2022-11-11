cmake_minimum_required(VERSION 3.0 )

project(gocv_contrib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

message("OPENCV_DIR: " ${OpenCV_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}/../../contrib
    ${OpenCV_INCLUDE_DIRS}
)

file(GLOB_RECURSE sources *.cpp)

add_library(gocv_contrib SHARED ${sources})
target_link_libraries(gocv_contrib  gocv ${OpenCV_LIBS})

