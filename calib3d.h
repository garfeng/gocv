#ifndef _OPENCV3_CALIB_H_
#define _OPENCV3_CALIB_H_

#include "mvsc.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>

extern "C" {
#endif

#include "core.h"

//Calib
DLL_EXPORT void Fisheye_UndistortImage(Mat distorted, Mat undistorted, Mat k, Mat d);
DLL_EXPORT void Fisheye_UndistortImageWithParams(Mat distorted, Mat undistorted, Mat k, Mat d, Mat knew, Size size);
DLL_EXPORT void Fisheye_UndistortPoints(Mat distorted, Mat undistorted, Mat k, Mat d, Mat R, Mat P);
DLL_EXPORT void Fisheye_EstimateNewCameraMatrixForUndistortRectify(Mat k, Mat d, Size imgSize, Mat r, Mat p, double balance, Size newSize, double fovScale);

DLL_EXPORT void InitUndistortRectifyMap(Mat cameraMatrix,Mat distCoeffs,Mat r,Mat newCameraMatrix,Size size,int m1type,Mat map1,Mat map2);
DLL_EXPORT Mat GetOptimalNewCameraMatrixWithParams(Mat cameraMatrix,Mat distCoeffs,Size size,double alpha,Size newImgSize,Rect* validPixROI,bool centerPrincipalPoint);
DLL_EXPORT double CalibrateCamera(Points3fVector objectPoints, Points2fVector imagePoints, Size imageSize, Mat cameraMatrix, Mat distCoeffs, Mat rvecs, Mat tvecs, int flag);
DLL_EXPORT void Undistort(Mat src, Mat dst, Mat cameraMatrix, Mat distCoeffs, Mat newCameraMatrix);
DLL_EXPORT void UndistortPoints(Mat distorted, Mat undistorted, Mat k, Mat d, Mat r, Mat p);
DLL_EXPORT bool FindChessboardCorners(Mat image, Size patternSize, Mat corners, int flags);
DLL_EXPORT bool FindChessboardCornersSB(Mat image, Size patternSize, Mat corners, int flags);
DLL_EXPORT bool FindChessboardCornersSBWithMeta(Mat image, Size patternSize, Mat corners, int flags, Mat meta);
DLL_EXPORT void DrawChessboardCorners(Mat image, Size patternSize, Mat corners, bool patternWasFound);
DLL_EXPORT Mat EstimateAffinePartial2D(Point2fVector from, Point2fVector to);
DLL_EXPORT Mat EstimateAffinePartial2DWithParams(Point2fVector from, Point2fVector to, Mat inliers, int method, double ransacReprojThreshold, size_t maxIters, double confidence, size_t refineIters);
DLL_EXPORT Mat EstimateAffine2D(Point2fVector from, Point2fVector to);
DLL_EXPORT Mat EstimateAffine2DWithParams(Point2fVector from, Point2fVector to, Mat inliers, int method, double ransacReprojThreshold, size_t maxIters, double confidence, size_t refineIters);
#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CALIB_H
