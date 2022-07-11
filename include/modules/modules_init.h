#pragma once
#include <synapse/memory/interface/memory_manager.h>

#include <modules/interface/modules.h>
#include <modules/probe/probe_type.h>

synapse_modules
	synapse_modules_initialize
		(synapse_modules_probe, const char*);

void
	synapse_modules_cleanup
		(synapse_modules_probe, synapse_modules);