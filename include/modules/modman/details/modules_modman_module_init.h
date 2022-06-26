#pragma once
#include <modules/traits/modman_interface.h>
#include <modules/modman/details/modules_modman_type.h>

__synapse_modules_modman_module*
__synapse_modules_modman_module_initialize
	(__synapse_modules_modman*, const char*);

void
__synapse_modules_modman_module_cleanup
	(__synapse_modules_modman*, __synapse_modules_modman_module*);