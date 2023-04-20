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
typedef cv::KalmanFilter* KalmanFilter;
#else
typedef void* BackgroundSubtractorMOG2;
typedef void* BackgroundSubtractorKNN;
typedef void* Tracker;
typedef void* TrackerMIL;
typedef void* TrackerGOTURN;
typedef void* KalmanFilter;
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

DLL_EXPORT KalmanFilter KalmanFilter_New(int dynamParams, int measureParams);
DLL_EXPORT KalmanFilter KalmanFilter_NewWithParams(int dynamParams, int measureParams, int controlParams, int type);
DLL_EXPORT void KalmanFilter_Close(KalmanFilter kf);

DLL_EXPORT void KalmanFilter_Init(KalmanFilter kf, int dynamParams, int measureParams);
DLL_EXPORT void KalmanFilter_InitWithParams(KalmanFilter kf, int dynamParams, int measureParams, int controlParams, int type);
DLL_EXPORT Mat KalmanFilter_Predict(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_PredictWithParams(KalmanFilter kf, Mat control);
DLL_EXPORT Mat KalmanFilter_Correct(KalmanFilter kf, Mat measurement);

DLL_EXPORT Mat KalmanFilter_GetStatePre(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetStatePost(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetTransitionMatrix(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetControlMatrix(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetMeasurementMatrix(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetProcessNoiseCov(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetMeasurementNoiseCov(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetErrorCovPre(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetGain(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetErrorCovPost(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetTemp1(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetTemp2(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetTemp3(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetTemp4(KalmanFilter kf);
DLL_EXPORT Mat KalmanFilter_GetTemp5(KalmanFilter kf);

DLL_EXPORT void KalmanFilter_SetStatePre(KalmanFilter kf, Mat statePre);
DLL_EXPORT void KalmanFilter_SetStatePost(KalmanFilter kf, Mat statePost);
DLL_EXPORT void KalmanFilter_SetTransitionMatrix(KalmanFilter kf, Mat transitionMatrix);
DLL_EXPORT void KalmanFilter_SetControlMatrix(KalmanFilter kf, Mat controlMatrix);
DLL_EXPORT void KalmanFilter_SetMeasurementMatrix(KalmanFilter kf, Mat measurementMatrix);
DLL_EXPORT void KalmanFilter_SetProcessNoiseCov(KalmanFilter kf, Mat processNoiseCov);
DLL_EXPORT void KalmanFilter_SetMeasurementNoiseCov(KalmanFilter kf, Mat measurementNoiseCov);
DLL_EXPORT void KalmanFilter_SetErrorCovPre(KalmanFilter kf, Mat errorCovPre);
DLL_EXPORT void KalmanFilter_SetGain(KalmanFilter kf, Mat gain);
DLL_EXPORT void KalmanFilter_SetErrorCovPost(KalmanFilter kf, Mat errorCovPost);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_VIDEO_H_
