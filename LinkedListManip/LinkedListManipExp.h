#pragma once

#ifdef _LINKED_LIST_MANIP_DLL_
#define LINKED_LIST_MANIP_DLLEXPORT   __declspec(dllexport)
#else
#define LINKED_LIST_MANIP_DLLEXPORT   __declspec(dllimport)
#endif