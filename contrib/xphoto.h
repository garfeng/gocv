#ifndef _OPENCV3_XPHOTO_H_
#define _OPENCV3_XPHOTO_H_


#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/xphoto/bm3d_image_denoising.hpp>
#include <opencv2/xphoto/white_balance.hpp>
#include <opencv2/xphoto/tonemap.hpp>
#include <opencv2/xphoto/inpainting.hpp>
#include <opencv2/xphoto/oilpainting.hpp>
extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::xphoto::GrayworldWB>* GrayworldWB;
typedef cv::Ptr<cv::xphoto::LearningBasedWB>* LearningBasedWB;
typedef cv::Ptr<cv::xphoto::SimpleWB>* SimpleWB;
typedef cv::Ptr<cv::xphoto::TonemapDurand>* TonemapDurand;
#else
typedef void* GrayworldWB;
typedef void* LearningBasedWB;
typedef void* SimpleWB;
typedef void* TonemapDurand;
#endif


// ----------------------- bm3d_image_denoising -----------------------

DLL_EXPORT void Xphoto_ApplyChannelGains(Mat src, Mat dst, float gainB, float gainG, float gainR) ;

DLL_EXPORT void Xphoto_Bm3dDenoising_Step(Mat src, Mat dststep1, Mat dststep2) ;
DLL_EXPORT void Xphoto_Bm3dDenoising_Step_WithParams(
    Mat src, Mat dststep1, Mat dststep2,
    float h, int templateWindowSize,
    int searchWindowSize, int blockMatchingStep1,
    int blockMatchingStep2, int groupSize,
    int slidingStep, float beta,
    int normType, int step,
    int transformType
) ;

DLL_EXPORT void Xphoto_Bm3dDenoising(Mat src, Mat dst) ;
DLL_EXPORT void Xphoto_Bm3dDenoising_WithParams(
    Mat src, Mat dst,
    float h, int templateWindowSize,
    int searchWindowSize, int blockMatchingStep1,
    int blockMatchingStep2, int groupSize,
    int slidingStep, float beta,
    int normType, int step,
    int transformType
) ;


// ----------------------- GrayworldWB -----------------------

DLL_EXPORT GrayworldWB GrayworldWB_Create();
DLL_EXPORT void GrayworldWB_Close(GrayworldWB b);
DLL_EXPORT void GrayworldWB_SetSaturationThreshold(GrayworldWB b, float saturationThreshold);
DLL_EXPORT float GrayworldWB_GetSaturationThreshold(GrayworldWB b);
DLL_EXPORT void GrayworldWB_BalanceWhite(GrayworldWB b, Mat src, Mat dst);

// ----------------------- LearningBasedWB -----------------------

DLL_EXPORT LearningBasedWB LearningBasedWB_Create();
DLL_EXPORT LearningBasedWB LearningBasedWB_CreateWithParams(const char* pathmodel);
DLL_EXPORT void LearningBasedWB_Close(LearningBasedWB b);
DLL_EXPORT void LearningBasedWB_ExtractSimpleFeatures(LearningBasedWB b, Mat src, Mat dst);
DLL_EXPORT int LearningBasedWB_GetHistBinNum(LearningBasedWB b) ;
DLL_EXPORT int LearningBasedWB_GetRangeMaxVal(LearningBasedWB b) ;
DLL_EXPORT float LearningBasedWB_GetSaturationThreshold(LearningBasedWB b) ;
DLL_EXPORT void LearningBasedWB_SetHistBinNum(LearningBasedWB b, int val);
DLL_EXPORT void LearningBasedWB_SetRangeMaxVal(LearningBasedWB b, int val);
DLL_EXPORT void LearningBasedWB_SetSaturationThreshold(LearningBasedWB b, float val);
DLL_EXPORT void LearningBasedWB_BalanceWhite(LearningBasedWB b, Mat src, Mat dst);

// ----------------------- SimpleWB -----------------------

DLL_EXPORT SimpleWB SimpleWB_Create();
DLL_EXPORT void SimpleWB_Close(SimpleWB b);
DLL_EXPORT float SimpleWB_GetInputMax(SimpleWB b);
DLL_EXPORT float SimpleWB_GetInputMin(SimpleWB b);
DLL_EXPORT float SimpleWB_GetOutputMax(SimpleWB b);
DLL_EXPORT float SimpleWB_GetOutputMin(SimpleWB b);
DLL_EXPORT float SimpleWB_GetP(SimpleWB b);
DLL_EXPORT void SimpleWB_SetInputMax(SimpleWB b, float val);
DLL_EXPORT void SimpleWB_SetInputMin(SimpleWB b, float val);
DLL_EXPORT void SimpleWB_SetOutputMax(SimpleWB b, float val);
DLL_EXPORT void SimpleWB_SetOutputMin(SimpleWB b, float val);
DLL_EXPORT void SimpleWB_SetP(SimpleWB b, float val);
DLL_EXPORT void SimpleWB_BalanceWhite(SimpleWB b, Mat src, Mat dst);


// -------------------- TonemapDurand --------------------

DLL_EXPORT TonemapDurand TonemapDurand_Create();
DLL_EXPORT TonemapDurand TonemapDurand_CreateWithParams(float gamma, float contrast, float saturation,
        float sigma_color, float sigma_space) ;
DLL_EXPORT void TonemapDurand_Close(TonemapDurand b);

DLL_EXPORT float TonemapDurand_GetContrast(TonemapDurand b);
DLL_EXPORT float TonemapDurand_GetSaturation(TonemapDurand b);
DLL_EXPORT float TonemapDurand_GetSigmaColor(TonemapDurand b);
DLL_EXPORT float TonemapDurand_GetSigmaSpace(TonemapDurand b);
DLL_EXPORT void TonemapDurand_SetContrast(TonemapDurand b, float contrast);
DLL_EXPORT void TonemapDurand_SetSaturation(TonemapDurand b, float saturation);
DLL_EXPORT void TonemapDurand_SetSigmaColor(TonemapDurand b, float sigma_color);
DLL_EXPORT void TonemapDurand_SetSigmaSpace(TonemapDurand b, float sigma_space);

DLL_EXPORT float TonemapDurand_GetGamma(TonemapDurand b);
DLL_EXPORT void TonemapDurand_Process(TonemapDurand b, Mat src, Mat dst);
DLL_EXPORT void TonemapDurand_SetGamma(TonemapDurand b, float gamma);


// ------------------------ Inpaint -----------------------

DLL_EXPORT void Inpaint(Mat src, Mat mask, Mat dst, int algorithmType);
DLL_EXPORT void OilPaintingWithParams(Mat src, Mat dst, int size, int dynRatio, int code);
DLL_EXPORT void OilPainting(Mat src, Mat dst, int size, int dynRatio);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_XPHOTO_H
