#ifndef _OPENCV3_VIDEO_H_
#define _OPENCV3_VIDEO_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/bgsegm.hpp>
extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::bgsegm::BackgroundSubtractorCNT>* BackgroundSubtractorCNT;
#else
typedef void* BackgroundSubtractorCNT;
#endif

DLL_EXPORT BackgroundSubtractorCNT BackgroundSubtractorCNT_Create();
DLL_EXPORT void BackgroundSubtractorCNT_Close(BackgroundSubtractorCNT b);
DLL_EXPORT void BackgroundSubtractorCNT_Apply(BackgroundSubtractorCNT b, Mat src, Mat dst);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_VIDEO_H_
