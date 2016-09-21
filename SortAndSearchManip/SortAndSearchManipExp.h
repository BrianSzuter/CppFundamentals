#pragma once

#ifdef _SORT_AND_SEARCH_MANIP_DLL_
#define SORT_AND_SEARCH_MANIP_DLLEXPORT   __declspec(dllexport)
#else
#define SORT_AND_SEARCH_MANIP_DLLEXPORT   __declspec(dllimport)
#endif