#pragma once
#include <modules/traits/modman_traits.h>

synapse_modules_handle
synapse_modules_modman_module_initialize
	(synapse_modules_modman, const char*);

void
synapse_modules_modman_module_cleanup
	(synapse_modules_modman, synapse_modules_handle);