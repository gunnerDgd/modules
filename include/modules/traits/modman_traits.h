#pragma once
#include <modules/defines/opaque/opaque.h>

synapse_modules_opaque_declare
	(synapse_modules_modman)

synapse_modules_opaque_declare
	(synapse_modules_handle)

typedef struct synapse_modules_modman_traits
{
	synapse_modules_modman
		hnd_modman;

	synapse_modules_handle
		(*load_module)	(synapse_modules_modman, const char*);
	void
		(*unload_module)(synapse_modules_modman, synapse_modules_handle);

	void
		(*attach_module)  (synapse_modules_modman, synapse_modules_handle);
	void
		(*detach_module)  (synapse_modules_modman, synapse_modules_handle);
	void
		(*reload_module)  (synapse_modules_modman, synapse_modules_handle);
	
	char*
		(*module_name)    (synapse_modules_handle);
} synapse_modules_modman_traits;