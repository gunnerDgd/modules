#pragma once
#include <modules/details/modules_type.h>

__synapse_modules*
	__synapse_modules_initialize
		(synapse_memory_manager*, const char*, int*);

void
	__synapse_modules_cleanup
		(synapse_memory_manager*, __synapse_modules*);