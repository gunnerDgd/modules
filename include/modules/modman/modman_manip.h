#pragma once
#include <modules/traits/modman_traits.h>

void
synapse_modules_modman_module_attach
	(synapse_modules_modman, synapse_modules_handle, void*);

void
synapse_modules_modman_module_detach
	(synapse_modules_modman, synapse_modules_handle, void*);

void
synapse_modules_modman_module_reload
	(synapse_modules_modman, synapse_modules_handle, void*);

void
synapse_modules_modman_module_retrieve
	(synapse_modules_modman, const char*);

char*
synapse_modules_modman_module_retrieve_name
	(synapse_modules_handle);