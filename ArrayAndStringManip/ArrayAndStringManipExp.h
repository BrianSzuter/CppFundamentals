#pragma once

#ifdef _STRING_MANIP_DLL_
#define STRING_MANIP_DLLEXPORT   __declspec(dllexport)
#else
#define STRING_MANIP_DLLEXPORT   __declspec(dllimport)
#endif