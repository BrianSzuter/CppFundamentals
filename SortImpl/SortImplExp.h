#pragma once

#ifdef _SORT_IMPL_DLL_
#define SORT_IMPL_DLLEXPORT   __declspec(dllexport)
#else
#define SORT_IMPL_DLLEXPORT   __declspec(dllimport)
#endif