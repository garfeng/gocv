#ifndef _OPENCV3_CORE_H_
#define _OPENCV3_CORE_H_


#include <stdint.h>
#include <stdbool.h>
#include "mvsc.h"

// Wrapper for std::vector<string>
typedef struct CStrings {
    const char** strs;
    int length;
} CStrings;

typedef struct ByteArray {
    char* data;
    int length;
} ByteArray;

// Wrapper for std::vector<int>
typedef struct IntVector {
    int* val;
    int length;
} IntVector;

// Wrapper for std::vector<float>
typedef struct FloatVector {
    float* val;
    int length;
} FloatVector;

#ifdef __cplusplus
#include <opencv2/opencv.hpp>

extern "C" {

#endif

typedef struct RawData {
    int width;
    int height;
    struct ByteArray data;
} RawData;

// Wrapper for an individual cv::Point2f
typedef struct Point2f {
    float x;
    float y;
} Point2f;

typedef struct Point3f {
    float x;
    float y;
    float z;
} Point3f;

// Wrapper for an individual cv::cvPoint
typedef struct Point {
    int x;
    int y;
} Point;

// Wrapper for the vector of Point structs aka std::vector<Point>
typedef struct Points {
    Point* points;
    int length;
} Points;

// Wrapper for the vector of Point2f structs aka std::vector<Point2f>
typedef struct Points2f {
    Point2f* points;
    int length;
} Points2f;

typedef struct Points3f {
    Point3f *points;
    int length;
} Points3f;

// Contour is alias for Points
typedef Points Contour;


// Contour2f is alias for Points2f
typedef Points2f Contour2f;

typedef struct Contours2f {
    Contour2f *contours;
    int length;
} Contours2f;

// Contour3f is alias for Points3f
typedef Points3f Contour3f;

// Wrapper for the vector of Points3f vectors aka std::vector< std::vector<Point3f> >
typedef struct Contours3f {
    Contour3f *contours;
    int length;
} Contours3f;


// Wrapper for the vector of Points vectors aka std::vector< std::vector<Point> >
typedef struct Contours {
    Contour* contours;
    int length;
} Contours;

// Wrapper for an individual cv::cvRect
typedef struct Rect {
    int x;
    int y;
    int width;
    int height;
} Rect;

// Wrapper for the vector of Rect struct aka std::vector<Rect>
typedef struct Rects {
    Rect* rects;
    int length;
} Rects;

// Wrapper for an individual cv::cvSize
typedef struct Size {
    int width;
    int height;
} Size;

// Wrapper for an individual cv::RotatedRect
typedef struct RotatedRect {
    Points pts;
    Rect boundingRect;
    Point center;
    Size size;
    double angle;
} RotatedRect;

// Wrapper for an individual cv::cvScalar
typedef struct Scalar {
    double val1;
    double val2;
    double val3;
    double val4;
} Scalar;

// Wrapper for a individual cv::KeyPoint
typedef struct KeyPoint {
    double x;
    double y;
    double size;
    double angle;
    double response;
    int octave;
    int classID;
} KeyPoint;

// Wrapper for the vector of KeyPoint struct aka std::vector<KeyPoint>
typedef struct KeyPoints {
    KeyPoint* keypoints;
    int length;
} KeyPoints;

// Wrapper for SimpleBlobDetectorParams aka SimpleBlobDetector::Params
typedef struct SimpleBlobDetectorParams {
    unsigned char   blobColor;
    bool    filterByArea;
    bool    filterByCircularity;
    bool    filterByColor;
    bool    filterByConvexity;
    bool    filterByInertia;
    float   maxArea;
    float   maxCircularity;
    float   maxConvexity;
    float   maxInertiaRatio;
    float   maxThreshold;
    float   minArea;
    float   minCircularity;
    float   minConvexity;
    float   minDistBetweenBlobs;
    float   minInertiaRatio;
    size_t  minRepeatability;
    float   minThreshold;
    float   thresholdStep;
} SimpleBlobDetectorParams;

// Wrapper for an individual cv::DMatch
typedef struct DMatch {
    int queryIdx;
    int trainIdx;
    int imgIdx;
    float distance;
} DMatch;

// Wrapper for the vector of DMatch struct aka std::vector<DMatch>
typedef struct DMatches {
    DMatch* dmatches;
    int length;
} DMatches;

// Wrapper for the vector vector of DMatch struct aka std::vector<std::vector<DMatch>>
typedef struct MultiDMatches {
    DMatches* dmatches;
    int length;
} MultiDMatches;

// Wrapper for an individual cv::Moment
typedef struct Moment {
    double m00;
    double m10;
    double m01;
    double m20;
    double m11;
    double m02;
    double m30;
    double m21;
    double m12;
    double m03;

    double mu20;
    double mu11;
    double mu02;
    double mu30;
    double mu21;
    double mu12;
    double mu03;

    double nu20;
    double nu11;
    double nu02;
    double nu30;
    double nu21;
    double nu12;
    double nu03;
} Moment;

#ifdef __cplusplus
typedef cv::Mat* Mat;
typedef cv::TermCriteria* TermCriteria;
typedef cv::RNG* RNG;
typedef std::vector< cv::Point >* PointVector;
typedef std::vector< std::vector< cv::Point > >* PointsVector;
typedef std::vector< cv::Point2f >* Point2fVector;
typedef std::vector< std::vector< cv::Point2f> >* Points2fVector;
typedef std::vector< cv::Point3f >* Point3fVector;
typedef std::vector< std::vector< cv::Point3f > >* Points3fVector;
#else
typedef void* Mat;
typedef void* TermCriteria;
typedef void* RNG;
typedef void* PointVector;
typedef void* PointsVector;
typedef void* Point2fVector;
typedef void* Points2fVector;
typedef void* Point3fVector;
typedef void* Points3fVector;
#endif

// Wrapper for the vector of Mat aka std::vector<Mat>
typedef struct Mats {
    Mat* mats;
    int length;
} Mats;

DLL_EXPORT Mat Mats_get(struct Mats mats, int i);
DLL_EXPORT struct DMatches MultiDMatches_get(struct MultiDMatches mds, int index);

DLL_EXPORT struct ByteArray toByteArray(const char* buf, int len);
DLL_EXPORT void ByteArray_Release(struct ByteArray buf);

DLL_EXPORT void Contours_Close(struct Contours cs);
DLL_EXPORT void KeyPoints_Close(struct KeyPoints ks);
DLL_EXPORT void Rects_Close(struct Rects rs);
DLL_EXPORT void Mats_Close(struct Mats mats);
DLL_EXPORT void Point_Close(struct Point p);
DLL_EXPORT void Points_Close(struct Points ps);
DLL_EXPORT void DMatches_Close(struct DMatches ds);
DLL_EXPORT void MultiDMatches_Close(struct MultiDMatches mds);

DLL_EXPORT Mat Mat_New();
DLL_EXPORT Mat Mat_NewWithSize(int rows, int cols, int type);
DLL_EXPORT Mat Mat_NewWithSizes(struct IntVector sizes, int type);
DLL_EXPORT Mat Mat_NewWithSizesFromScalar(IntVector sizes, int type, Scalar ar);
DLL_EXPORT Mat Mat_NewWithSizesFromBytes(IntVector sizes, int type, struct ByteArray buf);
DLL_EXPORT Mat Mat_NewFromScalar(const Scalar ar, int type);
DLL_EXPORT Mat Mat_NewWithSizeFromScalar(const Scalar ar, int rows, int cols, int type);
DLL_EXPORT Mat Mat_NewFromBytes(int rows, int cols, int type, struct ByteArray buf);
DLL_EXPORT Mat Mat_FromPtr(Mat m, int rows, int cols, int type, int prows, int pcols);
DLL_EXPORT void Mat_Close(Mat m);
DLL_EXPORT int Mat_Empty(Mat m);
DLL_EXPORT bool Mat_IsContinuous(Mat m);
DLL_EXPORT Mat Mat_Clone(Mat m);
DLL_EXPORT void Mat_CopyTo(Mat m, Mat dst);
DLL_EXPORT int Mat_Total(Mat m);
DLL_EXPORT void Mat_Size(Mat m, IntVector* res);
DLL_EXPORT void Mat_CopyToWithMask(Mat m, Mat dst, Mat mask);
DLL_EXPORT void Mat_ConvertTo(Mat m, Mat dst, int type);
DLL_EXPORT void Mat_ConvertToWithParams(Mat m, Mat dst, int type, float alpha, float beta);
DLL_EXPORT struct ByteArray Mat_ToBytes(Mat m);
DLL_EXPORT struct ByteArray Mat_DataPtr(Mat m);
DLL_EXPORT Mat Mat_Region(Mat m, Rect r);
DLL_EXPORT Mat Mat_Reshape(Mat m, int cn, int rows);
DLL_EXPORT void Mat_PatchNaNs(Mat m);
DLL_EXPORT Mat Mat_ConvertFp16(Mat m);
DLL_EXPORT Scalar Mat_Mean(Mat m);
DLL_EXPORT Scalar Mat_MeanWithMask(Mat m, Mat mask);
DLL_EXPORT Mat Mat_Sqrt(Mat m);
DLL_EXPORT int Mat_Rows(Mat m);
DLL_EXPORT int Mat_Cols(Mat m);
DLL_EXPORT int Mat_Channels(Mat m);
DLL_EXPORT int Mat_Type(Mat m);
DLL_EXPORT int Mat_Step(Mat m);
DLL_EXPORT int Mat_ElemSize(Mat m);
DLL_EXPORT Mat Eye(int rows, int cols, int type);
DLL_EXPORT Mat Zeros(int rows, int cols, int type);
DLL_EXPORT Mat Ones(int rows, int cols, int type);

DLL_EXPORT uint8_t Mat_GetUChar(Mat m, int row, int col);
DLL_EXPORT uint8_t Mat_GetUChar3(Mat m, int x, int y, int z);
DLL_EXPORT int8_t Mat_GetSChar(Mat m, int row, int col);
DLL_EXPORT int8_t Mat_GetSChar3(Mat m, int x, int y, int z);
DLL_EXPORT int16_t Mat_GetShort(Mat m, int row, int col);
DLL_EXPORT int16_t Mat_GetShort3(Mat m, int x, int y, int z);
DLL_EXPORT int32_t Mat_GetInt(Mat m, int row, int col);
DLL_EXPORT int32_t Mat_GetInt3(Mat m, int x, int y, int z);
DLL_EXPORT float Mat_GetFloat(Mat m, int row, int col);
DLL_EXPORT float Mat_GetFloat3(Mat m, int x, int y, int z);
DLL_EXPORT double Mat_GetDouble(Mat m, int row, int col);
DLL_EXPORT double Mat_GetDouble3(Mat m, int x, int y, int z);

DLL_EXPORT void Mat_SetTo(Mat m, Scalar value);
DLL_EXPORT void Mat_SetUChar(Mat m, int row, int col, uint8_t val);
DLL_EXPORT void Mat_SetUChar3(Mat m, int x, int y, int z, uint8_t val);
DLL_EXPORT void Mat_SetSChar(Mat m, int row, int col, int8_t val);
DLL_EXPORT void Mat_SetSChar3(Mat m, int x, int y, int z, int8_t val);
DLL_EXPORT void Mat_SetShort(Mat m, int row, int col, int16_t val);
DLL_EXPORT void Mat_SetShort3(Mat m, int x, int y, int z, int16_t val);
DLL_EXPORT void Mat_SetInt(Mat m, int row, int col, int32_t val);
DLL_EXPORT void Mat_SetInt3(Mat m, int x, int y, int z, int32_t val);
DLL_EXPORT void Mat_SetFloat(Mat m, int row, int col, float val);
DLL_EXPORT void Mat_SetFloat3(Mat m, int x, int y, int z, float val);
DLL_EXPORT void Mat_SetDouble(Mat m, int row, int col, double val);
DLL_EXPORT void Mat_SetDouble3(Mat m, int x, int y, int z, double val);

DLL_EXPORT void Mat_AddUChar(Mat m, uint8_t val);
DLL_EXPORT void Mat_SubtractUChar(Mat m, uint8_t val);
DLL_EXPORT void Mat_MultiplyUChar(Mat m, uint8_t val);
DLL_EXPORT void Mat_DivideUChar(Mat m, uint8_t val);
DLL_EXPORT void Mat_AddFloat(Mat m, float val);
DLL_EXPORT void Mat_SubtractFloat(Mat m, float val);
DLL_EXPORT void Mat_MultiplyFloat(Mat m, float val);
DLL_EXPORT void Mat_DivideFloat(Mat m, float val);
DLL_EXPORT Mat Mat_MultiplyMatrix(Mat x, Mat y);

DLL_EXPORT Mat Mat_T(Mat x);

DLL_EXPORT void LUT(Mat src, Mat lut, Mat dst);

DLL_EXPORT void Mat_AbsDiff(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_Add(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_AddWeighted(Mat src1, double alpha, Mat src2, double beta, double gamma, Mat dst);
DLL_EXPORT void Mat_BitwiseAnd(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_BitwiseAndWithMask(Mat src1, Mat src2, Mat dst, Mat mask);
DLL_EXPORT void Mat_BitwiseNot(Mat src1, Mat dst);
DLL_EXPORT void Mat_BitwiseNotWithMask(Mat src1, Mat dst, Mat mask);
DLL_EXPORT void Mat_BitwiseOr(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_BitwiseOrWithMask(Mat src1, Mat src2, Mat dst, Mat mask);
DLL_EXPORT void Mat_BitwiseXor(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_BitwiseXorWithMask(Mat src1, Mat src2, Mat dst, Mat mask);
DLL_EXPORT void Mat_Compare(Mat src1, Mat src2, Mat dst, int ct);
DLL_EXPORT void Mat_BatchDistance(Mat src1, Mat src2, Mat dist, int dtype, Mat nidx, int normType, int K, Mat mask, int update, bool crosscheck);
DLL_EXPORT int Mat_BorderInterpolate(int p, int len, int borderType);
DLL_EXPORT void Mat_CalcCovarMatrix(Mat samples, Mat covar, Mat mean, int flags, int ctype);
DLL_EXPORT void Mat_CartToPolar(Mat x, Mat y, Mat magnitude, Mat angle, bool angleInDegrees);
DLL_EXPORT bool Mat_CheckRange(Mat m);
DLL_EXPORT void Mat_CompleteSymm(Mat m, bool lowerToUpper);
DLL_EXPORT void Mat_ConvertScaleAbs(Mat src, Mat dst, double alpha, double beta);
DLL_EXPORT void Mat_CopyMakeBorder(Mat src, Mat dst, int top, int bottom, int left, int right, int borderType,
                         Scalar value);
DLL_EXPORT int Mat_CountNonZero(Mat src);
DLL_EXPORT void Mat_DCT(Mat src, Mat dst, int flags);
DLL_EXPORT double Mat_Determinant(Mat m);
DLL_EXPORT void Mat_DFT(Mat m, Mat dst, int flags);
DLL_EXPORT void Mat_Divide(Mat src1, Mat src2, Mat dst);
DLL_EXPORT bool Mat_Eigen(Mat src, Mat eigenvalues, Mat eigenvectors);
DLL_EXPORT void Mat_EigenNonSymmetric(Mat src, Mat eigenvalues, Mat eigenvectors);
DLL_EXPORT void Mat_Exp(Mat src, Mat dst);
DLL_EXPORT void Mat_ExtractChannel(Mat src, Mat dst, int coi);
DLL_EXPORT void Mat_FindNonZero(Mat src, Mat idx);
DLL_EXPORT void Mat_Flip(Mat src, Mat dst, int flipCode);
DLL_EXPORT void Mat_Gemm(Mat src1, Mat src2, double alpha, Mat src3, double beta, Mat dst, int flags);
DLL_EXPORT int Mat_GetOptimalDFTSize(int vecsize);
DLL_EXPORT void Mat_Hconcat(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_Vconcat(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Rotate(Mat src, Mat dst, int rotationCode);
DLL_EXPORT void Mat_Idct(Mat src, Mat dst, int flags);
DLL_EXPORT void Mat_Idft(Mat src, Mat dst, int flags, int nonzeroRows);
DLL_EXPORT void Mat_InRange(Mat src, Mat lowerb, Mat upperb, Mat dst);
DLL_EXPORT void Mat_InRangeWithScalar(Mat src, const Scalar lowerb, const Scalar upperb, Mat dst);
DLL_EXPORT void Mat_InsertChannel(Mat src, Mat dst, int coi);
DLL_EXPORT double Mat_Invert(Mat src, Mat dst, int flags);
DLL_EXPORT double KMeans(Mat data, int k, Mat bestLabels, TermCriteria criteria, int attempts, int flags, Mat centers);
DLL_EXPORT double KMeansPoints(PointVector pts, int k, Mat bestLabels, TermCriteria criteria, int attempts, int flags, Mat centers);
DLL_EXPORT void Mat_Log(Mat src, Mat dst);
DLL_EXPORT void Mat_Magnitude(Mat x, Mat y, Mat magnitude);
DLL_EXPORT void Mat_Max(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_MeanStdDev(Mat src, Mat dstMean, Mat dstStdDev);
DLL_EXPORT void Mat_Merge(struct Mats mats, Mat dst);
DLL_EXPORT void Mat_Min(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_MinMaxIdx(Mat m, double* minVal, double* maxVal, int* minIdx, int* maxIdx);
DLL_EXPORT void Mat_MinMaxLoc(Mat m, double* minVal, double* maxVal, Point* minLoc, Point* maxLoc);
DLL_EXPORT void Mat_MixChannels(struct Mats src, struct Mats dst, struct IntVector fromTo);
DLL_EXPORT void Mat_MulSpectrums(Mat a, Mat b, Mat c, int flags);
DLL_EXPORT void Mat_Multiply(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_MultiplyWithParams(Mat src1, Mat src2, Mat dst, double scale, int dtype);
DLL_EXPORT void Mat_Subtract(Mat src1, Mat src2, Mat dst);
DLL_EXPORT void Mat_Normalize(Mat src, Mat dst, double alpha, double beta, int typ);
DLL_EXPORT double Norm(Mat src1, int normType);
DLL_EXPORT double NormWithMats(Mat src1, Mat src2, int normType);
DLL_EXPORT void Mat_PerspectiveTransform(Mat src, Mat dst, Mat tm);
DLL_EXPORT bool Mat_Solve(Mat src1, Mat src2, Mat dst, int flags);
DLL_EXPORT int Mat_SolveCubic(Mat coeffs, Mat roots);
DLL_EXPORT double Mat_SolvePoly(Mat coeffs, Mat roots, int maxIters);
DLL_EXPORT void Mat_Reduce(Mat src, Mat dst, int dim, int rType, int dType);
DLL_EXPORT void Mat_Repeat(Mat src, int nY, int nX, Mat dst);
DLL_EXPORT void Mat_ScaleAdd(Mat src1, double alpha, Mat src2, Mat dst);
DLL_EXPORT void Mat_SetIdentity(Mat src, double scalar);
DLL_EXPORT void Mat_Sort(Mat src, Mat dst, int flags);
DLL_EXPORT void Mat_SortIdx(Mat src, Mat dst, int flags);
DLL_EXPORT void Mat_Split(Mat src, struct Mats* mats);
DLL_EXPORT void Mat_Subtract(Mat src1, Mat src2, Mat dst);
DLL_EXPORT Scalar Mat_Trace(Mat src);
DLL_EXPORT void Mat_Transform(Mat src, Mat dst, Mat tm);
DLL_EXPORT void Mat_Transpose(Mat src, Mat dst);
DLL_EXPORT void Mat_PolarToCart(Mat magnitude, Mat degree, Mat x, Mat y, bool angleInDegrees);
DLL_EXPORT void Mat_Pow(Mat src, double power, Mat dst);
DLL_EXPORT void Mat_Phase(Mat x, Mat y, Mat angle, bool angleInDegrees);
DLL_EXPORT Scalar Mat_Sum(Mat src1);

DLL_EXPORT TermCriteria TermCriteria_New(int typ, int maxCount, double epsilon);

DLL_EXPORT int64_t GetCVTickCount();
DLL_EXPORT double GetTickFrequency();

DLL_EXPORT Mat Mat_rowRange(Mat m,int startrow,int endrow);
DLL_EXPORT Mat Mat_colRange(Mat m,int startrow,int endrow);

DLL_EXPORT PointVector PointVector_New();
DLL_EXPORT PointVector PointVector_NewFromPoints(Contour points);
DLL_EXPORT PointVector PointVector_NewFromMat(Mat mat);
DLL_EXPORT Point PointVector_At(PointVector pv, int idx);
DLL_EXPORT void PointVector_Append(PointVector pv, Point p);
DLL_EXPORT int PointVector_Size(PointVector pv);
DLL_EXPORT void PointVector_Close(PointVector pv);

DLL_EXPORT PointsVector PointsVector_New();
DLL_EXPORT PointsVector PointsVector_NewFromPoints(Contours points);
DLL_EXPORT PointVector PointsVector_At(PointsVector psv, int idx);
DLL_EXPORT void PointsVector_Append(PointsVector psv, PointVector pv);
DLL_EXPORT int PointsVector_Size(PointsVector psv);
DLL_EXPORT void PointsVector_Close(PointsVector psv);

DLL_EXPORT Point2fVector Point2fVector_New();
DLL_EXPORT void Point2fVector_Close(Point2fVector pfv);
DLL_EXPORT Point2fVector Point2fVector_NewFromPoints(Contour2f pts);
DLL_EXPORT Point2fVector Point2fVector_NewFromMat(Mat mat);
DLL_EXPORT Point2f Point2fVector_At(Point2fVector pfv, int idx);
DLL_EXPORT int Point2fVector_Size(Point2fVector pfv);

DLL_EXPORT void IntVector_Close(struct IntVector ivec);

DLL_EXPORT void CStrings_Close(struct CStrings cstrs);

DLL_EXPORT RNG TheRNG();

DLL_EXPORT void SetRNGSeed(int seed);

DLL_EXPORT void RNG_Fill(RNG rng, Mat mat, int distType, double a, double b, bool saturateRange);

DLL_EXPORT double RNG_Gaussian(RNG rng, double sigma);

DLL_EXPORT unsigned int RNG_Next(RNG rng);

DLL_EXPORT void RandN(Mat mat, Scalar mean, Scalar stddev);

DLL_EXPORT void RandShuffle(Mat mat);

DLL_EXPORT void RandShuffleWithParams(Mat mat, double iterFactor, RNG rng);

DLL_EXPORT void RandU(Mat mat, Scalar low, Scalar high);

DLL_EXPORT void copyPointVectorToPoint2fVector(PointVector src, Point2fVector dest);

DLL_EXPORT void StdByteVectorInitialize(void* data);
DLL_EXPORT void StdByteVectorFree(void *data);
DLL_EXPORT size_t StdByteVectorLen(void *data);
DLL_EXPORT uint8_t* StdByteVectorData(void *data);
DLL_EXPORT Points2fVector Points2fVector_New();
DLL_EXPORT Points2fVector Points2fVector_NewFromPoints(Contours2f points);
DLL_EXPORT int Points2fVector_Size(Points2fVector ps);
DLL_EXPORT Point2fVector Points2fVector_At(Points2fVector ps, int idx);
DLL_EXPORT void Points2fVector_Append(Points2fVector psv, Point2fVector pv);
DLL_EXPORT void Points2fVector_Close(Points2fVector ps);

DLL_EXPORT Point3fVector Point3fVector_New();
DLL_EXPORT Point3fVector Point3fVector_NewFromPoints(Contour3f points);
DLL_EXPORT Point3fVector Point3fVector_NewFromMat(Mat mat);
DLL_EXPORT void Point3fVector_Append(Point3fVector pfv, Point3f point);
DLL_EXPORT Point3f Point3fVector_At(Point3fVector pfv, int idx);
DLL_EXPORT int Point3fVector_Size(Point3fVector pfv);
DLL_EXPORT void Point3fVector_Close(Point3fVector pv);
DLL_EXPORT Points3fVector Points3fVector_New();
DLL_EXPORT Points3fVector Points3fVector_NewFromPoints(Contours3f points);
DLL_EXPORT int Points3fVector_Size(Points3fVector ps);
DLL_EXPORT Point3fVector Points3fVector_At(Points3fVector ps, int idx);
DLL_EXPORT void Points3fVector_Append(Points3fVector psv, Point3fVector pv);
DLL_EXPORT void Points3fVector_Close(Points3fVector ps);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CORE_H_
