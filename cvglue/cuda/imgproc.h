#ifndef _OPENCV3_CUDA_IMGPROC_H_
#define _OPENCV3_CUDA_IMGPROC_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaarithm.hpp>
extern "C" {
#endif
#include "cuda.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::cuda::CannyEdgeDetector>* CannyEdgeDetector;
typedef cv::Ptr<cv::cuda::HoughLinesDetector>* HoughLinesDetector;
typedef cv::Ptr<cv::cuda::HoughSegmentDetector>* HoughSegmentDetector;
#else
typedef void* CannyEdgeDetector;
typedef void* HoughLinesDetector;
typedef void* HoughSegmentDetector;
#endif

// standalone functions
DLL_EXPORT void GpuCvtColor(GpuMat src, GpuMat dst, int code, Stream s);

// CannyEdgeDetector
DLL_EXPORT CannyEdgeDetector CreateCannyEdgeDetector(double lowThresh, double highThresh);
DLL_EXPORT CannyEdgeDetector CreateCannyEdgeDetectorWithParams(double lowThresh, double highThresh, int appertureSize, bool L2gradient);
DLL_EXPORT void CannyEdgeDetector_Close(CannyEdgeDetector det);
DLL_EXPORT void CannyEdgeDetector_Detect(CannyEdgeDetector det, GpuMat img, GpuMat dst, Stream s);
DLL_EXPORT int CannyEdgeDetector_GetAppertureSize(CannyEdgeDetector det);
DLL_EXPORT double CannyEdgeDetector_GetHighThreshold(CannyEdgeDetector det);
DLL_EXPORT bool CannyEdgeDetector_GetL2Gradient(CannyEdgeDetector det);
DLL_EXPORT double CannyEdgeDetector_GetLowThreshold(CannyEdgeDetector det);
DLL_EXPORT void CannyEdgeDetector_SetAppertureSize(CannyEdgeDetector det, int appertureSize);
DLL_EXPORT void CannyEdgeDetector_SetHighThreshold(CannyEdgeDetector det, double highThresh);
DLL_EXPORT void CannyEdgeDetector_SetL2Gradient(CannyEdgeDetector det, bool L2gradient);
DLL_EXPORT void CannyEdgeDetector_SetLowThreshold(CannyEdgeDetector det, double lowThresh);

// HoughLinesDetector
DLL_EXPORT HoughLinesDetector HoughLinesDetector_Create(double rho, double theta, int threshold);
DLL_EXPORT HoughLinesDetector HoughLinesDetector_CreateWithParams(double rho, double theta, int threshold, bool sort, int maxlines);
DLL_EXPORT void HoughLinesDetector_Close(HoughLinesDetector hld);
DLL_EXPORT void HoughLinesDetector_Detect(HoughLinesDetector hld, GpuMat img, GpuMat dst, Stream s);

// HoughSegmentDetector
DLL_EXPORT HoughSegmentDetector HoughSegmentDetector_Create(double rho, double theta, int minLineLength, int maxLineGap);
DLL_EXPORT void HoughSegmentDetector_Close(HoughSegmentDetector hsd);
DLL_EXPORT void HoughSegmentDetector_Detect(HoughSegmentDetector hsd, GpuMat img, GpuMat dst, Stream s);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CUDA_IMGPROC_H_
