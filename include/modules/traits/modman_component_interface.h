#pragma once
#include <stdint.h>
#include <stdarg.h>

typedef struct synapse_modules_component_interface
{
	void*
		(*component_create)   (va_list);
	void
		(*component_delete)   (void*);
	void*
		(*component_duplicate)(void*, va_list);
} synapse_modules_component_interface;