cmake_minimum_required(VERSION 3.0 )

project(cvglue)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_HOST_WIN32 EQUAL 1)
set(OpenCV_DIR C:/opencv/install-vs/install)
else()
set(OpenCV_DIR $ENV{HOME}/opencv/)
endif()

find_package(OpenCV REQUIRED)

message("OPENCV_DIR: " ${OpenCV_INCLUDE_DIRS})

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE sources *.cpp cuda/*.cpp contrib/*.cpp)

add_library(cvglue STATIC ${sources})
target_link_libraries(cvglue  ${OpenCV_LIBS})
