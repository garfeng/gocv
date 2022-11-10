#ifndef _OPENCV3_FEATURES2D_H_
#define _OPENCV3_FEATURES2D_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::AKAZE>* AKAZE;
typedef cv::Ptr<cv::AgastFeatureDetector>* AgastFeatureDetector;
typedef cv::Ptr<cv::BRISK>* BRISK;
typedef cv::Ptr<cv::FastFeatureDetector>* FastFeatureDetector;
typedef cv::Ptr<cv::GFTTDetector>* GFTTDetector;
typedef cv::Ptr<cv::KAZE>* KAZE;
typedef cv::Ptr<cv::MSER>* MSER;
typedef cv::Ptr<cv::ORB>* ORB;
typedef cv::Ptr<cv::SimpleBlobDetector>* SimpleBlobDetector;
typedef cv::Ptr<cv::BFMatcher>* BFMatcher;
typedef cv::Ptr<cv::FlannBasedMatcher>* FlannBasedMatcher;
typedef cv::Ptr<cv::SIFT>* SIFT;
#else
typedef void* AKAZE;
typedef void* AgastFeatureDetector;
typedef void* BRISK;
typedef void* FastFeatureDetector;
typedef void* GFTTDetector;
typedef void* KAZE;
typedef void* MSER;
typedef void* ORB;
typedef void* SimpleBlobDetector;
typedef void* BFMatcher;
typedef void* FlannBasedMatcher;
typedef void* SIFT;
#endif

DLL_EXPORT AKAZE AKAZE_Create();
DLL_EXPORT void AKAZE_Close(AKAZE a);
DLL_EXPORT struct KeyPoints AKAZE_Detect(AKAZE a, Mat src);
DLL_EXPORT struct KeyPoints AKAZE_DetectAndCompute(AKAZE a, Mat src, Mat mask, Mat desc);

DLL_EXPORT AgastFeatureDetector AgastFeatureDetector_Create();
DLL_EXPORT void AgastFeatureDetector_Close(AgastFeatureDetector a);
DLL_EXPORT struct KeyPoints AgastFeatureDetector_Detect(AgastFeatureDetector a, Mat src);

DLL_EXPORT BRISK BRISK_Create();
DLL_EXPORT void BRISK_Close(BRISK b);
DLL_EXPORT struct KeyPoints BRISK_Detect(BRISK b, Mat src);
DLL_EXPORT struct KeyPoints BRISK_DetectAndCompute(BRISK b, Mat src, Mat mask, Mat desc);

DLL_EXPORT FastFeatureDetector FastFeatureDetector_Create();
DLL_EXPORT FastFeatureDetector FastFeatureDetector_CreateWithParams(int threshold, bool nonmaxSuppression, int type);
DLL_EXPORT void FastFeatureDetector_Close(FastFeatureDetector f);
DLL_EXPORT struct KeyPoints FastFeatureDetector_Detect(FastFeatureDetector f, Mat src);

DLL_EXPORT GFTTDetector GFTTDetector_Create();
DLL_EXPORT void GFTTDetector_Close(GFTTDetector a);
DLL_EXPORT struct KeyPoints GFTTDetector_Detect(GFTTDetector a, Mat src);

DLL_EXPORT KAZE KAZE_Create();
DLL_EXPORT void KAZE_Close(KAZE a);
DLL_EXPORT struct KeyPoints KAZE_Detect(KAZE a, Mat src);
DLL_EXPORT struct KeyPoints KAZE_DetectAndCompute(KAZE a, Mat src, Mat mask, Mat desc);

DLL_EXPORT MSER MSER_Create();
DLL_EXPORT void MSER_Close(MSER a);
DLL_EXPORT struct KeyPoints MSER_Detect(MSER a, Mat src);

DLL_EXPORT ORB ORB_Create();
DLL_EXPORT ORB ORB_CreateWithParams(int nfeatures, float scaleFactor, int nlevels, int edgeThreshold, int firstLevel, int WTA_K, int scoreType, int patchSize, int fastThreshold);
DLL_EXPORT void ORB_Close(ORB o);
DLL_EXPORT struct KeyPoints ORB_Detect(ORB o, Mat src);
DLL_EXPORT struct KeyPoints ORB_DetectAndCompute(ORB o, Mat src, Mat mask, Mat desc);

DLL_EXPORT SimpleBlobDetector SimpleBlobDetector_Create();
DLL_EXPORT SimpleBlobDetector SimpleBlobDetector_Create_WithParams(SimpleBlobDetectorParams params);
DLL_EXPORT void SimpleBlobDetector_Close(SimpleBlobDetector b);
DLL_EXPORT struct KeyPoints SimpleBlobDetector_Detect(SimpleBlobDetector b, Mat src);
DLL_EXPORT SimpleBlobDetectorParams SimpleBlobDetectorParams_Create();

DLL_EXPORT BFMatcher BFMatcher_Create();
DLL_EXPORT BFMatcher BFMatcher_CreateWithParams(int normType, bool crossCheck);
DLL_EXPORT void BFMatcher_Close(BFMatcher b);
DLL_EXPORT struct MultiDMatches BFMatcher_KnnMatch(BFMatcher b, Mat query, Mat train, int k);

DLL_EXPORT FlannBasedMatcher FlannBasedMatcher_Create();
DLL_EXPORT void FlannBasedMatcher_Close(FlannBasedMatcher f);
DLL_EXPORT struct MultiDMatches FlannBasedMatcher_KnnMatch(FlannBasedMatcher f, Mat query, Mat train, int k);

DLL_EXPORT void DrawKeyPoints(Mat src, struct KeyPoints kp, Mat dst, const Scalar s, int flags);

DLL_EXPORT SIFT SIFT_Create();
DLL_EXPORT void SIFT_Close(SIFT f);
DLL_EXPORT struct KeyPoints SIFT_Detect(SIFT f, Mat src);
DLL_EXPORT struct KeyPoints SIFT_DetectAndCompute(SIFT f, Mat src, Mat mask, Mat desc);

DLL_EXPORT void DrawMatches(Mat img1, struct KeyPoints kp1, Mat img2, struct KeyPoints kp2, struct DMatches matches1to2, Mat outImg, const Scalar matchesColor, const Scalar pointColor, struct ByteArray matchesMask, int flags);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_FEATURES2D_H_
