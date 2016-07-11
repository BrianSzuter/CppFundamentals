#pragma once

#ifdef _CODING_INTERVIEW_CH11_
#define SORT_IMPL_DLLEXPORT   __declspec(dllexport)
#else
#define SORT_IMPL_DLLEXPORT   __declspec(dllimport)
#endif