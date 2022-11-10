#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"
#include "dnn.h"

#ifdef __cplusplus
typedef cv::AsyncArray* AsyncArray;
#else
typedef void* AsyncArray;
#endif

DLL_EXPORT AsyncArray AsyncArray_New();
DLL_EXPORT const char* AsyncArray_GetAsync(AsyncArray async_out,Mat out);
DLL_EXPORT void AsyncArray_Close(AsyncArray a);
DLL_EXPORT AsyncArray Net_forwardAsync(Net net, const char* outputName);


#ifdef __cplusplus
}
#endif
