#pragma once
#include <stdint.h>
#include <stdarg.h>

typedef struct synapse_modules_component_interface
{
	void*
		(*construct)(va_list);
	void
		(*destruct) (void*);
	void*
		(*duplicate)(void*);
} synapse_modules_component_interface;