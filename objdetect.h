#ifndef _OPENCV3_OBJDETECT_H_
#define _OPENCV3_OBJDETECT_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::CascadeClassifier* CascadeClassifier;
typedef cv::HOGDescriptor* HOGDescriptor;
typedef cv::QRCodeDetector* QRCodeDetector;
#else
typedef void* CascadeClassifier;
typedef void* HOGDescriptor;
typedef void* QRCodeDetector;
#endif

// CascadeClassifier
DLL_EXPORT CascadeClassifier CascadeClassifier_New();
DLL_EXPORT void CascadeClassifier_Close(CascadeClassifier cs);
DLL_EXPORT int CascadeClassifier_Load(CascadeClassifier cs, const char* name);
DLL_EXPORT struct Rects CascadeClassifier_DetectMultiScale(CascadeClassifier cs, Mat img);
DLL_EXPORT struct Rects CascadeClassifier_DetectMultiScaleWithParams(CascadeClassifier cs, Mat img,
        double scale, int minNeighbors, int flags, Size minSize, Size maxSize);

DLL_EXPORT HOGDescriptor HOGDescriptor_New();
DLL_EXPORT void HOGDescriptor_Close(HOGDescriptor hog);
DLL_EXPORT int HOGDescriptor_Load(HOGDescriptor hog, const char* name);
DLL_EXPORT struct Rects HOGDescriptor_DetectMultiScale(HOGDescriptor hog, Mat img);
DLL_EXPORT struct Rects HOGDescriptor_DetectMultiScaleWithParams(HOGDescriptor hog, Mat img,
        double hitThresh, Size winStride, Size padding, double scale, double finalThreshold,
        bool useMeanshiftGrouping);
DLL_EXPORT Mat HOG_GetDefaultPeopleDetector();
DLL_EXPORT void HOGDescriptor_SetSVMDetector(HOGDescriptor hog, Mat det);

DLL_EXPORT struct Rects GroupRectangles(struct Rects rects, int groupThreshold, double eps);

DLL_EXPORT QRCodeDetector QRCodeDetector_New();
DLL_EXPORT const char* QRCodeDetector_DetectAndDecode(QRCodeDetector qr, Mat input,Mat points,Mat straight_qrcode);
DLL_EXPORT bool QRCodeDetector_Detect(QRCodeDetector qr, Mat input,Mat points);
DLL_EXPORT const char* QRCodeDetector_Decode(QRCodeDetector qr, Mat input,Mat inputPoints,Mat straight_qrcode);
DLL_EXPORT void QRCodeDetector_Close(QRCodeDetector qr);
DLL_EXPORT bool QRCodeDetector_DetectMulti(QRCodeDetector qr, Mat input, Mat points);
DLL_EXPORT bool QRCodeDetector_DetectAndDecodeMulti(QRCodeDetector qr, Mat input, CStrings* decoded ,Mat points, struct Mats* mats);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_OBJDETECT_H_
