#ifndef _OPENCV3_DNN_H_
#define _OPENCV3_DNN_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::dnn::Net* Net;
typedef cv::Ptr<cv::dnn::Layer>* Layer;
#else
typedef void* Net;
typedef void* Layer;
#endif

DLL_EXPORT Net Net_ReadNet(const char* model, const char* config);
DLL_EXPORT Net Net_ReadNetBytes(const char* framework, struct ByteArray model, struct ByteArray config);
DLL_EXPORT Net Net_ReadNetFromCaffe(const char* prototxt, const char* caffeModel);
DLL_EXPORT Net Net_ReadNetFromCaffeBytes(struct ByteArray prototxt, struct ByteArray caffeModel);
DLL_EXPORT Net Net_ReadNetFromTensorflow(const char* model);
DLL_EXPORT Net Net_ReadNetFromTensorflowBytes(struct ByteArray model);
DLL_EXPORT Net Net_ReadNetFromTorch(const char* model);
DLL_EXPORT Net Net_ReadNetFromONNX(const char* model);
DLL_EXPORT Net Net_ReadNetFromONNXBytes(struct ByteArray model);
DLL_EXPORT Mat Net_BlobFromImage(Mat image, double scalefactor, Size size, Scalar mean, bool swapRB,
                      bool crop);
DLL_EXPORT void Net_BlobFromImages(struct Mats images, Mat blob,  double scalefactor, Size size, 
                        Scalar mean, bool swapRB, bool crop, int ddepth);
DLL_EXPORT void Net_ImagesFromBlob(Mat blob_, struct Mats* images_);
DLL_EXPORT void Net_Close(Net net);
DLL_EXPORT bool Net_Empty(Net net);
DLL_EXPORT void Net_SetInput(Net net, Mat blob, const char* name);
DLL_EXPORT Mat Net_Forward(Net net, const char* outputName);
DLL_EXPORT void Net_ForwardLayers(Net net, struct Mats* outputBlobs, struct CStrings outBlobNames);
DLL_EXPORT void Net_SetPreferableBackend(Net net, int backend);
DLL_EXPORT void Net_SetPreferableTarget(Net net, int target);
DLL_EXPORT int64_t Net_GetPerfProfile(Net net);
DLL_EXPORT void Net_GetUnconnectedOutLayers(Net net, IntVector* res);
DLL_EXPORT void Net_GetLayerNames(Net net, CStrings* names);

DLL_EXPORT Mat Net_GetBlobChannel(Mat blob, int imgidx, int chnidx);
DLL_EXPORT Scalar Net_GetBlobSize(Mat blob);

DLL_EXPORT Layer Net_GetLayer(Net net, int layerid);
DLL_EXPORT void Layer_Close(Layer layer);
DLL_EXPORT int Layer_InputNameToIndex(Layer layer, const char* name);
DLL_EXPORT int Layer_OutputNameToIndex(Layer layer, const char* name);
DLL_EXPORT const char* Layer_GetName(Layer layer);
DLL_EXPORT const char* Layer_GetType(Layer layer);

DLL_EXPORT void NMSBoxes(struct Rects bboxes, FloatVector scores, float score_threshold, float nms_threshold, IntVector* indices);
DLL_EXPORT void NMSBoxesWithParams(struct Rects bboxes, FloatVector scores, const float score_threshold, const float nms_threshold, IntVector* indices, const float eta, const int top_k);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_DNN_H_
