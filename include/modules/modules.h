#pragma once
#include <modules/defines/export/export.h>
#include <modules/interface/modules.h>

synapse_modules_dll
	synapse_modules
		synapse_load_modules
			(const char*);

synapse_modules_dll
	void
		synapse_unload_modules
			(synapse_modules);

synapse_modules_dll
	int
		synapse_attach_modules
			(synapse_modules);

synapse_modules_dll
	int
		synapse_detach_modules
			(synapse_modules);

synapse_modules_dll
	int
		synapse_reload_modules
			(synapse_modules);

synapse_modules_dll
	synapse_modules
		synapse_import_modules
			(const char*);