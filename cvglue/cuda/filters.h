#ifndef _GOCV_CUDA_FILTERS_H_
#define _GOCV_CUDA_FILTERS_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/cudafilters.hpp>
extern "C" {
#endif
#include "cuda.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::cuda::Filter>* GaussianFilter;
typedef cv::Ptr<cv::cuda::Filter>* SobelFilter;
#else
typedef void* GaussianFilter;
typedef void* SobelFilter;
#endif

// GaussianFilter
DLL_EXPORT GaussianFilter CreateGaussianFilter(int srcType, int dstType, Size ksize, double sigma1);
DLL_EXPORT GaussianFilter CreateGaussianFilterWithParams(int srcType, int dstType, Size ksize, double sigma1, double sigma2, int rowBorderMode, int columnBorderMode);
DLL_EXPORT void GaussianFilter_Close(GaussianFilter gf);
DLL_EXPORT void GaussianFilter_Apply(GaussianFilter gf, GpuMat img, GpuMat dst, Stream s);

// SobelFilter
DLL_EXPORT SobelFilter CreateSobelFilter(int srcType, int dstType, int dx, int dy);
DLL_EXPORT SobelFilter CreateSobelFilterWithParams(int srcType, int dstType, int dx, int dy, int ksize, double scale, int rowBorderMode, int columnBorderMode);
DLL_EXPORT void SobelFilter_Close(SobelFilter sf);
DLL_EXPORT void SobelFilter_Apply(SobelFilter sf, GpuMat img, GpuMat dst, Stream s);

#ifdef __cplusplus
}
#endif

#endif //_GOCV_CUDA_FILTERS_H_
