#ifndef _OPENCV3_SVD_H_
#define _OPENCV3_SVD_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>

extern "C" {
#endif

#include "core.h"

DLL_EXPORT void SVD_Compute(Mat src, Mat w, Mat u, Mat vt);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_SVD_H