# Use CUDA on Windows


## Overview

1. Compile the cpp source of gocv to a dll via Visual studio.
2. Link the dll via cgo.

## Detail steps

1. Prepare the OpenCV With CUDA. You may download it here: https://github.com/cudawarped/opencv_contrib/releases#, or build it by yourself.

2. Clone or download the branch `cuda_win`.
``` shell
git clone https://github.com/garfeng/gocv.git
git checkout cuda_win
```

3. Build cpp sources with Visual studio
``` shell
cd gocv/cvglue/
mkdir build 
cd build
cmake .. -G "Visual Studio 17 2022"
```

    Before run cmake, may need to edit the CMakeLists.txt in cvglue:
``` js
// set to the opencv installed dir, where locates the OpenCVConfig.cmake
set(OpenCV_DIR C:/opencv/4.6.0-cuda/3.5-8.6/) 

// set to the cuda toolkit installed dir 
set(CUDA_TOOLKIT_ROOT_DIR D:/cuda/) 
```

CMake will Generate a Visual studio solution in the build dir. Open the `cvglue.sln` with VS, then build `Release x64`, build project `INSTALL` in the solution explorer. 
It will copy all of the dlls to dir `C:/opencv/cvglue`

``` shell
admin@pc MINGW64 /c/opencv/cvglue
$ tree
.
├── bin
│   ├── gocv.dll
│   ├── gocv_contrib.dll
│   └── gocv_cuda.dll
└── lib
    ├── gocv.lib
    ├── gocv_contrib.lib
    └── gocv_cuda.lib

2 directories, 6 files
```
4. Test
``` shell
cd gocv/cmd/cuda
go build main.go
```

``` shell
admin@pc MINGW64 $GOPATH/src/github.com/garfeng/gocv/cmd/cuda
$ go build main.go

admin@pc MINGW64 $GOPATH/src/github.com/garfeng/gocv/cmd/cuda
$ ./main.exe
main.exe: error while loading shared libraries: gocv.dll: cannot open shared object file: No such file or directory

admin@pc MINGW64 $GOPATH/src/github.com/garfeng/gocv/cmd/cuda
$ cp /c/opencv/cvglue/bin/*.dll ./

admin@pc MINGW64 $GOPATH/src/github.com/garfeng/gocv/cmd/cuda
$ ls
gocv.dll  gocv_contrib.dll  gocv_cuda.dll  main.exe  main.go

admin@pc MINGW64 $GOPATH/src/github.com/garfeng/gocv/cmd/cuda
$ ./main.exe
gocv version: 0.31.0
cuda information:
Device 0:  "NVIDIA GeForce RTX 3050 Ti Laptop GPU"  4096Mb, sm_86, Driver/Runtime ver.11.80/11.80
```

A YoloV5 example can be found here: https://github.com/garfeng/go_yolov5


## Usage

1. Create your go project.

2. Import `gocv.io/x/gocv` as usually.

3. Add the following line to your go.mod

``` go.mod
replace gocv.io/x/gocv v0.31.0 => github.com/garfeng/gocv v0.31.5
```
