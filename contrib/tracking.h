
#ifndef _OPENCV3_TRACKING_H_
#define _OPENCV3_TRACKING_H_

#include "../core.h"

#ifdef __cplusplus
#include <opencv2/tracking/tracking.hpp>

extern "C" {
#endif


#ifdef __cplusplus
typedef cv::Ptr<cv::Tracker>* Tracker;
typedef cv::Ptr<cv::TrackerKCF>* TrackerKCF;
typedef cv::Ptr<cv::TrackerCSRT>* TrackerCSRT;
#else
typedef void* Tracker;
typedef void* TrackerKCF;
typedef void* TrackerCSRT;
#endif

DLL_EXPORT bool TrackerSubclass_Init(Tracker self, Mat image, Rect boundingBox);
DLL_EXPORT bool TrackerSubclass_Update(Tracker self, Mat image, Rect* boundingBox);

DLL_EXPORT TrackerKCF TrackerKCF_Create();
DLL_EXPORT void TrackerKCF_Close(TrackerKCF self);

DLL_EXPORT TrackerCSRT TrackerCSRT_Create();
DLL_EXPORT void TrackerCSRT_Close(TrackerCSRT self);


#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_TRACKING_H_
