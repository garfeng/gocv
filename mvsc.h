# ifndef MVSC_H
#define MVSC_H 1

#ifdef _MSC_VER 

#define DLL_EXPORT _declspec(dllexport) 

#else

#define DLL_EXPORT

#endif


#endif //MVSC_H