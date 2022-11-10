#ifndef _OPENCV3_CUDA_H_
#define _OPENCV3_CUDA_H_

#include "../mvsc.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>

extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::cuda::GpuMat* GpuMat;
typedef cv::cuda::Stream* Stream;
#else
typedef void* GpuMat;
typedef void* Stream;
#endif

DLL_EXPORT GpuMat GpuMat_New();
DLL_EXPORT GpuMat GpuMat_NewFromMat(Mat mat);
DLL_EXPORT GpuMat GpuMat_NewWithSize(int rows, int cols, int type);
DLL_EXPORT void GpuMat_Upload(GpuMat m, Mat data, Stream s);
DLL_EXPORT void GpuMat_Download(GpuMat m, Mat dst, Stream s);
DLL_EXPORT void GpuMat_Close(GpuMat m);
DLL_EXPORT int GpuMat_Empty(GpuMat m);
DLL_EXPORT void GpuMat_ConvertTo(GpuMat m, GpuMat dst, int type, Stream s);
DLL_EXPORT void GpuMat_CopyTo(GpuMat m, GpuMat dst, Stream s);
DLL_EXPORT GpuMat GpuMat_Reshape(GpuMat m, int cn, int rows);
DLL_EXPORT int GpuMat_Cols(GpuMat m);
DLL_EXPORT int GpuMat_Rows(GpuMat m);
DLL_EXPORT int GpuMat_Channels(GpuMat m);
DLL_EXPORT int GpuMat_Type(GpuMat m);

DLL_EXPORT void PrintCudaDeviceInfo(int device);
DLL_EXPORT void PrintShortCudaDeviceInfo(int device);
DLL_EXPORT int GetCudaEnabledDeviceCount();
DLL_EXPORT int GetCudaDevice();
DLL_EXPORT void SetCudaDevice(int device);
DLL_EXPORT void ResetCudaDevice();

DLL_EXPORT Stream Stream_New();
DLL_EXPORT void Stream_Close(Stream s);
DLL_EXPORT bool Stream_QueryIfComplete(Stream s);
DLL_EXPORT void Stream_WaitForCompletion(Stream s);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CUDA_H_
