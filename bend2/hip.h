// HIP shim: the CUDA driver and NVRTC names the runtime uses, on
// HIP/ROCm. Included where a CUDA build reads cuda.h and nvrtc.h.

#include <hip/hip_runtime_api.h>
#include <hip/hiprtc.h>

typedef hipDevice_t    CUdevice;
typedef hipModule_t    CUmodule;
typedef hipFunction_t  CUfunction;
typedef hipError_t     CUresult;
typedef hipCtx_t       CUcontext;
typedef hipDeviceptr_t CUdeviceptr;
typedef hiprtcProgram  nvrtcProgram;

#define CUDA_SUCCESS  hipSuccess
#define NVRTC_SUCCESS HIPRTC_SUCCESS

#define cuInit                    hipInit
#define cuDeviceGet               hipDeviceGet
#define cuDeviceGetAttribute      hipDeviceGetAttribute
#define CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS \
  hipDeviceAttributeConcurrentManagedAccess
#define CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE hipDeviceAttributeL2CacheSize
#define cuDevicePrimaryCtxRetain(c, d)  hipSetDevice(d)
#define cuDevicePrimaryCtxRelease(d)    ((void)0)
#define cuCtxSetCurrent(c)              hipSuccess
#define cuGetErrorName(r, n)  (*(n) = hipGetErrorName(r), hipSuccess)
#define cuMemAllocManaged(p, b, f) hipMallocManaged((void**)(p), b, f)
#define CU_MEM_ATTACH_GLOBAL      hipMemAttachGlobal
#define cuMemAdvise               hipMemAdvise
#define CU_MEM_ADVISE_SET_PREFERRED_LOCATION \
  hipMemAdviseSetPreferredLocation
#define cuModuleLoadData          hipModuleLoadData
#define cuModuleGetFunction       hipModuleGetFunction
#define cuLaunchKernel            hipModuleLaunchKernel
#define cuCtxSynchronize          hipDeviceSynchronize
#define cuDeviceTotalMem          hipDeviceTotalMem
#define cuMemsetD8                hipMemsetD8
#define cuMemAlloc(p, n)          hipMalloc((void**)(p), n)
#define cuMemFree                 hipFree
#define cuMemcpyDtoH              hipMemcpyDtoH

#define nvrtcCreateProgram        hiprtcCreateProgram
#define nvrtcCompileProgram(p, n, o) \
  hiprtcCompileProgram(p, n, (const char* const*)(o))
#define nvrtcGetProgramLogSize    hiprtcGetProgramLogSize
#define nvrtcGetProgramLog        hiprtcGetProgramLog
#define nvrtcDestroyProgram       hiprtcDestroyProgram
#define nvrtcGetCUBINSize         hiprtcGetCodeSize
#define nvrtcGetCUBIN             hiprtcGetCode
