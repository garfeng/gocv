#ifndef _OPENCV3_CUDAWARPING_H_
#define _OPENCV3_CUDAWARPING_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/cudawarping.hpp>

extern "C" {
#endif

#include "../core.h"
#include "cuda.h"

DLL_EXPORT void CudaResize(GpuMat src, GpuMat dst, Size dsize, double fx, double fy, int interp, Stream s);
DLL_EXPORT void CudaPyrDown(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void CudaPyrUp(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void CudaBuildWarpAffineMaps(GpuMat M, bool inverse, Size dsize, GpuMat xmap, GpuMat ymap, Stream s);
DLL_EXPORT void CudaBuildWarpPerspectiveMaps(GpuMat M, bool inverse, Size dsize, GpuMat xmap, GpuMat ymap, Stream s);
DLL_EXPORT void CudaRemap(GpuMat src, GpuMat dst, GpuMat xmap, GpuMat ymap, int interp, int borderMode, Scalar borderValue, Stream s);
DLL_EXPORT void CudaRotate(GpuMat src, GpuMat dst, Size dsize, double angle, double xShift, double yShift, int interp, Stream s);
DLL_EXPORT void CudaWarpAffine(GpuMat src, GpuMat dst, GpuMat M, Size dsize, int flags, int borderMode, Scalar borderValue, Stream s);
DLL_EXPORT void CudaWarpPerspective(GpuMat src, GpuMat dst, GpuMat M, Size dsize, int flags, int borderMode, Scalar borderValue, Stream s);
#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CUDAWARPING_H_
