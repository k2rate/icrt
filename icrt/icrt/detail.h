#pragma once

#define ICRT_INLINE inline

#ifdef _MSC_VER
#define ICRT_FORCEINLINE __forceinline
#else
#define ICRT_FORCEINLINE inline
#endif