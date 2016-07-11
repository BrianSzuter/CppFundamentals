#pragma once

#ifdef _CODING_INTERVIEW_CH1_
#define STRING_MANIP_DLLEXPORT   __declspec(dllexport)
#else
#define STRING_MANIP_DLLEXPORT   __declspec(dllimport)
#endif