#ifndef _OPENCV3_XFEATURES2D_H_
#define _OPENCV3_XFEATURES2D_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::xfeatures2d::SURF>* SURF;
#else
typedef void* SURF;
#endif

DLL_EXPORT SURF SURF_Create();
DLL_EXPORT void SURF_Close(SURF f);
DLL_EXPORT struct KeyPoints SURF_Detect(SURF f, Mat src);
DLL_EXPORT struct KeyPoints SURF_DetectAndCompute(SURF f, Mat src, Mat mask, Mat desc);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_XFEATURES2D_H_
