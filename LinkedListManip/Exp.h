#pragma once

#ifdef _CODING_INTERVIEW_CH2_
#define LINKED_LIST_MANIP_DLLEXPORT   __declspec(dllexport)
#else
#define LINKED_LIST_MANIP_DLLEXPORT   __declspec(dllimport)
#endif