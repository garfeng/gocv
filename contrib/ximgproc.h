#ifndef _OPENCV3_XIMGPROC_H_
#define _OPENCV3_XIMGPROC_H_

#include "../mvsc.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/ximgproc.hpp>
extern "C" {
#endif

#include "../core.h"

DLL_EXPORT void anisotropicDiffusion(Mat src, Mat dst, float alpha, float K, int niters);
DLL_EXPORT void edgePreservingFilter(Mat src, Mat dst, int d, float threshold);
DLL_EXPORT void niBlackThreshold(Mat src, Mat dst, float maxValue, int type, int blockSize, float k, int binarizationMethod, float r);
DLL_EXPORT void PeiLinNormalization(Mat src, Mat dst);
DLL_EXPORT void thinning(Mat src, Mat dst, int typ);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_XIMGPROC_H
