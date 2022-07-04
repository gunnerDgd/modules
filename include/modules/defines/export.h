#pragma once

#ifdef synapse_modules_export_mode
#define synapse_modules_export _declspec(dllexport)
#else
#define synapse_modules_export _declspec(dllimport)
#endif