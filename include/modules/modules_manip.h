#pragma once
#include <synapse/modules/interface/modules.h>
#include <modules/probe/probe_type.h>

int
	synapse_modules_attach
		(synapse_modules_probe, synapse_modules);

int
	synapse_modules_detach
		(synapse_modules_probe, synapse_modules);

int
	synapse_modules_reload
		(synapse_modules_probe, synapse_modules);

synapse_modules
	synapse_modules_retrieve
		(synapse_modules_probe, const char*);