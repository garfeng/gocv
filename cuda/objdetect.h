#ifndef _OPENCV3_GPU_H_
#define _OPENCV3_GPU_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaobjdetect.hpp>

extern "C" {
#endif

#include "../core.h"
#include "cuda.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::cuda::CascadeClassifier>* CascadeClassifier_GPU;
typedef cv::Ptr<cv::cuda::HOG>* HOG;
#else
typedef void* CascadeClassifier_GPU;
typedef void* HOG;
#endif

// CascadeClassifier
DLL_EXPORT CascadeClassifier_GPU CascadeClassifier_GPU_Create(const char*  cascade_name);
DLL_EXPORT struct Rects CascadeClassifier_GPU_DetectMultiScale(CascadeClassifier_GPU cs, GpuMat img);

// HOG
DLL_EXPORT HOG HOG_Create();
DLL_EXPORT HOG HOG_CreateWithParams(Size winSize, Size blockSize, Size blockStride, Size cellSize, int nbins);
DLL_EXPORT struct Rects HOG_DetectMultiScale(HOG hog, GpuMat img);
DLL_EXPORT GpuMat HOG_Compute(HOG hog, GpuMat img);
DLL_EXPORT Mat HOG_GetPeopleDetector(HOG hog);
DLL_EXPORT void HOG_SetSVMDetector(HOG hog, Mat det);
DLL_EXPORT int HOG_GetDescriptorFormat(HOG hog);
DLL_EXPORT size_t HOG_GetBlockHistogramSize(HOG hog);
DLL_EXPORT size_t HOG_GetDescriptorSize(HOG hog);
DLL_EXPORT bool HOG_GetGammaCorrection(HOG hog);
DLL_EXPORT int HOG_GetGroupThreshold(HOG hog);
DLL_EXPORT double HOG_GetHitThreshold(HOG hog);
DLL_EXPORT double HOG_GetL2HysThreshold(HOG hog);
DLL_EXPORT int HOG_GetNumLevels(HOG hog);
DLL_EXPORT double HOG_GetScaleFactor(HOG hog);
DLL_EXPORT double HOG_GetWinSigma(HOG hog);
DLL_EXPORT struct Size HOG_GetWinStride(HOG hog);
DLL_EXPORT void HOG_SetDescriptorFormat(HOG hog, int descrFormat);
DLL_EXPORT void HOG_SetGammaCorrection(HOG hog, bool gammaCorrection);
DLL_EXPORT void HOG_SetGroupThreshold(HOG hog, int groupThreshold);
DLL_EXPORT void HOG_SetHitThreshold(HOG hog, double hitThreshold);
DLL_EXPORT void HOG_SetL2HysThreshold(HOG hog, double thresholdL2hys);
DLL_EXPORT void HOG_SetNumLevels(HOG hog, int nlevels);
DLL_EXPORT void HOG_SetScaleFactor(HOG hog, double scale0);
DLL_EXPORT void HOG_SetWinSigma(HOG hog, double winSigma);
DLL_EXPORT void HOG_SetWinStride(HOG hog, Size dsize);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_GPU_H_
