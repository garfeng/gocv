cmake_minimum_required(VERSION 3.0 )

project(gocvcuda)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

message("OPENCV_DIR: " ${OpenCV_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}/../../cuda
    ${OpenCV_INCLUDE_DIRS}
)

file(GLOB_RECURSE sources *.cpp)

add_library(gocvcuda SHARED ${sources})
target_link_libraries(gocvcuda  gocv ${OpenCV_LIBS})

