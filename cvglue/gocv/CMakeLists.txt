cmake_minimum_required(VERSION 3.0 )

project(gocv)

find_package(OpenCV REQUIRED)


include_directories(
    ${PROJECT_SOURCE_DIR}/../../
    ${OpenCV_INCLUDE_DIRS}
)

file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/*.cpp)

add_library(gocv SHARED ${sources})
target_link_libraries(gocv  ${OpenCV_LIBS})
