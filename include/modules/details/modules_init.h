#pragma once
#include <modules/details/modules_type.h>

__synapse_modules*
	__synapse_modules_initialize
		(synapse_memory_mman_traits*, const char*, int*);

void
	__synapse_modules_cleanup
		(synapse_memory_mman_traits*, __synapse_modules*);