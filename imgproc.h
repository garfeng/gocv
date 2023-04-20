#ifndef _OPENCV3_IMGPROC_H_
#define _OPENCV3_IMGPROC_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#ifdef __cplusplus
typedef cv::Ptr<cv::CLAHE>* CLAHE;
#else
typedef void* CLAHE;
#endif

#include "core.h"

DLL_EXPORT double ArcLength(PointVector curve, bool is_closed);
DLL_EXPORT PointVector ApproxPolyDP(PointVector curve, double epsilon, bool closed);
DLL_EXPORT void CvtColor(Mat src, Mat dst, int code);
DLL_EXPORT void EqualizeHist(Mat src, Mat dst);
DLL_EXPORT void CalcHist(struct Mats mats, IntVector chans, Mat mask, Mat hist, IntVector sz, FloatVector rng, bool acc);
DLL_EXPORT void CalcBackProject(struct Mats mats, IntVector chans, Mat hist, Mat backProject, FloatVector rng, bool uniform);
DLL_EXPORT double CompareHist(Mat hist1, Mat hist2, int method);
DLL_EXPORT void ConvexHull(PointVector points, Mat hull, bool clockwise, bool returnPoints);
DLL_EXPORT void ConvexityDefects(PointVector points, Mat hull, Mat result);
DLL_EXPORT void BilateralFilter(Mat src, Mat dst, int d, double sc, double ss);
DLL_EXPORT void Blur(Mat src, Mat dst, Size ps);
DLL_EXPORT void BoxFilter(Mat src, Mat dst, int ddepth, Size ps);
DLL_EXPORT void SqBoxFilter(Mat src, Mat dst, int ddepth, Size ps);
DLL_EXPORT void Dilate(Mat src, Mat dst, Mat kernel);
DLL_EXPORT void DilateWithParams(Mat src, Mat dst, Mat kernel, Point anchor, int iterations, int borderType, Scalar borderValue);
DLL_EXPORT void DistanceTransform(Mat src, Mat dst, Mat labels, int distanceType, int maskSize, int labelType);
DLL_EXPORT void Erode(Mat src, Mat dst, Mat kernel);
DLL_EXPORT void ErodeWithParams(Mat src, Mat dst, Mat kernel, Point anchor, int iterations, int borderType);
DLL_EXPORT void MatchTemplate(Mat image, Mat templ, Mat result, int method, Mat mask);
DLL_EXPORT struct Moment Moments(Mat src, bool binaryImage);
DLL_EXPORT void PyrDown(Mat src, Mat dst, Size dstsize, int borderType);
DLL_EXPORT void PyrUp(Mat src, Mat dst, Size dstsize, int borderType);
DLL_EXPORT struct Rect BoundingRect(PointVector pts);
DLL_EXPORT void BoxPoints(RotatedRect rect, Mat boxPts);
DLL_EXPORT double ContourArea(PointVector pts);
DLL_EXPORT struct RotatedRect MinAreaRect(PointVector pts);
DLL_EXPORT struct RotatedRect FitEllipse(PointVector pts);
DLL_EXPORT void MinEnclosingCircle(PointVector pts, Point2f* center, float* radius);
DLL_EXPORT PointsVector FindContours(Mat src, Mat hierarchy, int mode, int method);
DLL_EXPORT double PointPolygonTest(PointVector pts, Point pt, bool measureDist);
DLL_EXPORT int ConnectedComponents(Mat src, Mat dst, int connectivity, int ltype, int ccltype);
DLL_EXPORT int ConnectedComponentsWithStats(Mat src, Mat labels, Mat stats, Mat centroids, int connectivity, int ltype, int ccltype);

DLL_EXPORT void GaussianBlur(Mat src, Mat dst, Size ps, double sX, double sY, int bt);
DLL_EXPORT Mat GetGaussianKernel(int ksize, double sigma, int ktype);
DLL_EXPORT void Laplacian(Mat src, Mat dst, int dDepth, int kSize, double scale, double delta, int borderType);
DLL_EXPORT void Scharr(Mat src, Mat dst, int dDepth, int dx, int dy, double scale, double delta,
            int borderType);
DLL_EXPORT Mat GetStructuringElement(int shape, Size ksize);
DLL_EXPORT Scalar MorphologyDefaultBorderValue();
DLL_EXPORT void MorphologyEx(Mat src, Mat dst, int op, Mat kernel);
DLL_EXPORT void MorphologyExWithParams(Mat src, Mat dst, int op, Mat kernel, Point pt, int iterations, int borderType);
DLL_EXPORT void MedianBlur(Mat src, Mat dst, int ksize);

DLL_EXPORT void Canny(Mat src, Mat edges, double t1, double t2);
DLL_EXPORT void CornerSubPix(Mat img, Mat corners, Size winSize, Size zeroZone, TermCriteria criteria);
DLL_EXPORT void GoodFeaturesToTrack(Mat img, Mat corners, int maxCorners, double quality, double minDist);
DLL_EXPORT void GrabCut(Mat img, Mat mask, Rect rect, Mat bgdModel, Mat fgdModel, int iterCount, int mode);
DLL_EXPORT void HoughCircles(Mat src, Mat circles, int method, double dp, double minDist);
DLL_EXPORT void HoughCirclesWithParams(Mat src, Mat circles, int method, double dp, double minDist,
                            double param1, double param2, int minRadius, int maxRadius);
DLL_EXPORT void HoughLines(Mat src, Mat lines, double rho, double theta, int threshold);
DLL_EXPORT void HoughLinesP(Mat src, Mat lines, double rho, double theta, int threshold);
DLL_EXPORT void HoughLinesPWithParams(Mat src, Mat lines, double rho, double theta, int threshold, double minLineLength, double maxLineGap);
DLL_EXPORT void HoughLinesPointSet(Mat points, Mat lines, int lines_max, int threshold,
                        double min_rho, double  max_rho, double rho_step,
                        double min_theta, double max_theta, double theta_step);
DLL_EXPORT void Integral(Mat src, Mat sum, Mat sqsum, Mat tilted);
DLL_EXPORT double Threshold(Mat src, Mat dst, double thresh, double maxvalue, int typ);
DLL_EXPORT void AdaptiveThreshold(Mat src, Mat dst, double maxValue, int adaptiveTyp, int typ, int blockSize,
                       double c);

DLL_EXPORT void ArrowedLine(Mat img, Point pt1, Point pt2, Scalar color, int thickness);
DLL_EXPORT void Circle(Mat img, Point center, int radius, Scalar color, int thickness);
DLL_EXPORT void CircleWithParams(Mat img, Point center, int radius, Scalar color, int thickness, int lineType, int shift);
DLL_EXPORT void Ellipse(Mat img, Point center, Point axes, double angle, double
             startAngle, double endAngle, Scalar color, int thickness);
DLL_EXPORT void EllipseWithParams(Mat img, Point center, Point axes, double angle, double
             startAngle, double endAngle, Scalar color, int thickness, int lineType, int shift);
DLL_EXPORT void Line(Mat img, Point pt1, Point pt2, Scalar color, int thickness);
DLL_EXPORT void Rectangle(Mat img, Rect rect, Scalar color, int thickness);
DLL_EXPORT void RectangleWithParams(Mat img, Rect rect, Scalar color, int thickness, int lineType, int shift);
DLL_EXPORT void FillPoly(Mat img, PointsVector points, Scalar color);
DLL_EXPORT void FillPolyWithParams(Mat img, PointsVector points, Scalar color, int lineType, int shift, Point offset);
DLL_EXPORT void Polylines(Mat img, PointsVector points, bool isClosed, Scalar color, int thickness);
DLL_EXPORT struct Size GetTextSize(const char* text, int fontFace, double fontScale, int thickness);
DLL_EXPORT struct Size GetTextSizeWithBaseline(const char* text, int fontFace, double fontScale, int thickness, int* baseline);
DLL_EXPORT void PutText(Mat img, const char* text, Point org, int fontFace, double fontScale,
             Scalar color, int thickness);
DLL_EXPORT void PutTextWithParams(Mat img, const char* text, Point org, int fontFace, double fontScale,
                         Scalar color, int thickness, int lineType, bool bottomLeftOrigin);
DLL_EXPORT void Resize(Mat src, Mat dst, Size sz, double fx, double fy, int interp);
DLL_EXPORT void GetRectSubPix(Mat src, Size patchSize, Point center, Mat dst);
DLL_EXPORT Mat GetRotationMatrix2D(Point center, double angle, double scale);
DLL_EXPORT void WarpAffine(Mat src, Mat dst, Mat rot_mat, Size dsize);
DLL_EXPORT void WarpAffineWithParams(Mat src, Mat dst, Mat rot_mat, Size dsize, int flags, int borderMode,
                          Scalar borderValue);
DLL_EXPORT void WarpPerspective(Mat src, Mat dst, Mat m, Size dsize);
DLL_EXPORT void WarpPerspectiveWithParams(Mat src, Mat dst, Mat rot_mat, Size dsize, int flags, int borderMode,
                               Scalar borderValue);
void Watershed(Mat image, Mat markers);
void ApplyColorMap(Mat src, Mat dst, int colormap);
void ApplyCustomColorMap(Mat src, Mat dst, Mat colormap);
Mat GetPerspectiveTransform(PointVector src, PointVector dst);
Mat GetPerspectiveTransform2f(Point2fVector src, Point2fVector dst);
Mat GetAffineTransform(PointVector src, PointVector dst);
Mat GetAffineTransform2f(Point2fVector src, Point2fVector dst);
Mat FindHomography(Mat src, Mat dst, int method, double ransacReprojThreshold, Mat mask, const int maxIters, const double confidence) ;
void DrawContours(Mat src, PointsVector contours, int contourIdx, Scalar color, int thickness);
void DrawContoursWithParams(Mat src, PointsVector contours, int contourIdx, Scalar color, int thickness, int lineType, Mat hierarchy, int maxLevel, Point offset);
void Sobel(Mat src, Mat dst, int ddepth, int dx, int dy, int ksize, double scale, double delta, int borderType);
void SpatialGradient(Mat src, Mat dx, Mat dy, int ksize, int borderType);
void Remap(Mat src, Mat dst, Mat map1, Mat map2, int interpolation, int borderMode, Scalar borderValue);
void Filter2D(Mat src, Mat dst, int ddepth, Mat kernel, Point anchor, double delta, int borderType);
void SepFilter2D(Mat src, Mat dst, int ddepth, Mat kernelX, Mat kernelY, Point anchor, double delta, int borderType);
void LogPolar(Mat src, Mat dst, Point center, double m, int flags);
void FitLine(PointVector pts, Mat line, int distType, double param, double reps, double aeps);
void LinearPolar(Mat src, Mat dst, Point center, double maxRadius, int flags);
double MatchShapes(PointVector contour1, PointVector contour2, int method, double parameter);
bool ClipLine(Size imgSize, Point pt1, Point pt2);
CLAHE CLAHE_Create();
CLAHE CLAHE_CreateWithParams(double clipLimit, Size tileGridSize);
void CLAHE_Close(CLAHE c);
void CLAHE_Apply(CLAHE c, Mat src, Mat dst);
void InvertAffineTransform(Mat src, Mat dst);
Point2f PhaseCorrelate(Mat src1, Mat src2, Mat window, double* response);
void Mat_Accumulate(Mat src, Mat dst);
void Mat_AccumulateWithMask(Mat src, Mat dst, Mat mask);
void Mat_AccumulateSquare(Mat src, Mat dst);
void Mat_AccumulateSquareWithMask(Mat src, Mat dst, Mat mask);
void Mat_AccumulateProduct(Mat src1, Mat src2, Mat dst);
void Mat_AccumulateProductWithMask(Mat src1, Mat src2, Mat dst, Mat mask);
void Mat_AccumulatedWeighted(Mat src, Mat dst, double alpha);
void Mat_AccumulatedWeightedWithMask(Mat src, Mat dst, double alpha, Mat mask);
#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_IMGPROC_H_
