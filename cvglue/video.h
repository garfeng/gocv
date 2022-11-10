#ifndef _OPENCV3_VIDEO_H_
#define _OPENCV3_VIDEO_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::BackgroundSubtractorMOG2>* BackgroundSubtractorMOG2;
typedef cv::Ptr<cv::BackgroundSubtractorKNN>* BackgroundSubtractorKNN;
typedef cv::Ptr<cv::Tracker>* Tracker;
typedef cv::Ptr<cv::TrackerMIL>* TrackerMIL;
typedef cv::Ptr<cv::TrackerGOTURN>* TrackerGOTURN;
#else
typedef void* BackgroundSubtractorMOG2;
typedef void* BackgroundSubtractorKNN;
typedef void* Tracker;
typedef void* TrackerMIL;
typedef void* TrackerGOTURN;
#endif

DLL_EXPORT BackgroundSubtractorMOG2 BackgroundSubtractorMOG2_Create();
DLL_EXPORT BackgroundSubtractorMOG2 BackgroundSubtractorMOG2_CreateWithParams(int history, double varThreshold, bool detectShadows);
DLL_EXPORT void BackgroundSubtractorMOG2_Close(BackgroundSubtractorMOG2 b);
DLL_EXPORT void BackgroundSubtractorMOG2_Apply(BackgroundSubtractorMOG2 b, Mat src, Mat dst);

DLL_EXPORT BackgroundSubtractorKNN BackgroundSubtractorKNN_Create();
DLL_EXPORT BackgroundSubtractorKNN BackgroundSubtractorKNN_CreateWithParams(int history, double dist2Threshold, bool detectShadows);

DLL_EXPORT void BackgroundSubtractorKNN_Close(BackgroundSubtractorKNN b);
DLL_EXPORT void BackgroundSubtractorKNN_Apply(BackgroundSubtractorKNN b, Mat src, Mat dst);

DLL_EXPORT void CalcOpticalFlowPyrLK(Mat prevImg, Mat nextImg, Mat prevPts, Mat nextPts, Mat status, Mat err);
DLL_EXPORT void CalcOpticalFlowPyrLKWithParams(Mat prevImg, Mat nextImg, Mat prevPts, Mat nextPts, Mat status, Mat err, Size winSize, int maxLevel, TermCriteria criteria, int flags, double minEigThreshold);
DLL_EXPORT void CalcOpticalFlowFarneback(Mat prevImg, Mat nextImg, Mat flow, double pyrScale, int levels,
                              int winsize, int iterations, int polyN, double polySigma, int flags);

DLL_EXPORT double FindTransformECC(Mat templateImage, Mat inputImage, Mat warpMatrix, int motionType, TermCriteria criteria, Mat inputMask, int gaussFiltSize);

DLL_EXPORT bool Tracker_Init(Tracker self, Mat image, Rect boundingBox);
DLL_EXPORT bool Tracker_Update(Tracker self, Mat image, Rect* boundingBox);

DLL_EXPORT TrackerMIL TrackerMIL_Create();
DLL_EXPORT void TrackerMIL_Close(TrackerMIL self);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_VIDEO_H_
