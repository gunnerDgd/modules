#pragma once
#include <modules/probe/details/probe_type.h>

__synapse_modules_probe*
	__synapse_modules_probe_initialize
		(synapse_memory_manager*);

void
	__synapse_modules_probe_cleanup
		(__synapse_modules_probe*);