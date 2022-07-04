#pragma once
#include <modules/traits/modman_interface.h>
#include <modules/modman/details/modules_modman_type.h>

const char*
__synapse_modules_modman_module_retrieve_name
	(__synapse_modules_modman_module*);

synapse_modules_component_manager
__synapse_modules_modman_module_retrieve_component_manager
	(__synapse_modules_modman_module*);