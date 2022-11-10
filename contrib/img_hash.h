#ifndef _OPENCV3_IMG_HASH_H_
#define _OPENCV3_IMG_HASH_H_

#include "../mvsc.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/img_hash.hpp>
extern "C" {
#endif

#include "../core.h"

DLL_EXPORT void pHashCompute(Mat inputArr, Mat outputArr);
DLL_EXPORT double pHashCompare(Mat a, Mat b);
DLL_EXPORT void averageHashCompute(Mat inputArr, Mat outputArr);
DLL_EXPORT double averageHashCompare(Mat a, Mat b);
DLL_EXPORT void blockMeanHashCompute(Mat inputArr, Mat outputArr, int mode);
DLL_EXPORT double blockMeanHashCompare(Mat a, Mat b, int mode);
DLL_EXPORT void colorMomentHashCompute(Mat inputArr, Mat outputArr);
DLL_EXPORT double colorMomentHashCompare(Mat a, Mat b);
DLL_EXPORT void marrHildrethHashCompute(Mat inputArr, Mat outputArr, float alpha, float scale);
DLL_EXPORT double marrHildrethHashCompare(Mat a, Mat b, float alpha, float scale);
DLL_EXPORT void radialVarianceHashCompute(Mat inputArr, Mat outputArr, double sigma, int numOfAngleLine);
DLL_EXPORT double radialVarianceHashCompare(Mat a, Mat b, double sigma, int numOfAngleLine);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_IMG_HASH_H_
