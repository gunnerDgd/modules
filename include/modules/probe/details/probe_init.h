#pragma once
#include <modules/probe/details/probe_type.h>

__synapse_modules_probe*
	__synapse_modules_probe_initialize
		(synapse_memory_mman_traits*, synapse_memory_mman_traits*);

void
	__synapse_modules_probe_cleanup
		(synapse_memory_mman_traits*, __synapse_modules_probe*);