#pragma once
#include <modules/probe/details/probe_type.h>

__synapse_modules_probe_modules*
	__synapse_modules_probe_load_module
		(__synapse_modules_probe*, const char*);

void
	__synapse_modules_probe_unload_module
		(__synapse_modules_probe*, __synapse_modules_probe_modules*);

__synapse_modules_probe_modules*
	__synapse_modules_probe_retrieve_module
		(__synapse_modules_probe*, const char*);

int
	__synapse_modules_probe_attach_module
		(__synapse_modules_probe*, __synapse_modules_probe_modules*);

int
	__synapse_modules_probe_detach_module
		(__synapse_modules_probe*, __synapse_modules_probe_modules*);

int
	__synapse_modules_probe_reload_module
		(__synapse_modules_probe*, __synapse_modules_probe_modules*);