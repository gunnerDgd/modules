#pragma once
#ifdef synapse_modules_export
#define synapse_modules_dll _declspec(dllexport)
#else
#define synapse_modules_dll _declspec(dllimport)
#endif