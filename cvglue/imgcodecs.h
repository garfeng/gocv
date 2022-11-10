#ifndef _OPENCV3_IMGCODECS_H_
#define _OPENCV3_IMGCODECS_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

DLL_EXPORT Mat Image_IMRead(const char* filename, int flags);
DLL_EXPORT bool Image_IMWrite(const char* filename, Mat img);
DLL_EXPORT bool Image_IMWrite_WithParams(const char* filename, Mat img, IntVector params);
DLL_EXPORT void Image_IMEncode(const char* fileExt, Mat img, void* vector);

DLL_EXPORT void Image_IMEncode_WithParams(const char* fileExt, Mat img, IntVector params, void* vector);
DLL_EXPORT Mat Image_IMDecode(ByteArray buf, int flags);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_IMGCODECS_H_
