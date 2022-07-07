#pragma once
#include <modules/probe/probe_type.h>
#include <memory/mman/mman_traits.h>

synapse_modules_probe
	synapse_modules_probe_initialize
		(synapse_memory_mman_traits*, synapse_memory_mman_traits*);

void
	synapse_modules_probe_cleanup
		(synapse_modules_probe);