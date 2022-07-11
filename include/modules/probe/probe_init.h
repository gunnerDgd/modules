#pragma once
#include <synapse/memory/interface/memory_manager.h>
#include <modules/probe/probe_type.h>

synapse_modules_probe
	synapse_modules_probe_initialize
		(synapse_memory_manager*);

void
	synapse_modules_probe_cleanup
		(synapse_modules_probe);