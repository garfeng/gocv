cmake_minimum_required(VERSION 3.0 )

project(cvglue)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_HOST_WIN32 EQUAL 1)
    set(OpenCV_DIR C:/opencv/4.6.0-cuda/3.5-8.6/)
    set(CUDA_TOOLKIT_ROOT_DIR D:/cuda/)
else()
    set(OpenCV_DIR $ENV{HOME}/opencv/install/lib/cmake/opencv4/)
endif()

if(CMAKE_HOST_WIN32 EQUAL 1)
    set(CMAKE_INSTALL_PREFIX C:/opencv/cvglue)
else()
    set(CMAKE_INSTALL_PREFIX /usr/local/)
endif()


add_subdirectory(gocv)
add_subdirectory(contrib)
add_subdirectory(cuda)

install(TARGETS gocv gocv_contrib gocv_cuda 
    EXPORT gocv
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)


