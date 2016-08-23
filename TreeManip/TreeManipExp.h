#pragma once

#ifdef _TREE_MANIP_DLL_
#define TREE_MANIP_DLLEXPORT   __declspec(dllexport)
#else
#define TREE_MANIP_DLLEXPORT   __declspec(dllimport)
#endif