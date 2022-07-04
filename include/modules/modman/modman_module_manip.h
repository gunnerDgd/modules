#pragma once
#include <modules/traits/modman_traits.h>
#include <modules/component/component_type.h>

const char*
synapse_modules_modman_module_retrieve_name
	(synapse_modules_handle);

synapse_modules_component_manager
synapse_modules_modman_module_retrieve_component_manager
	(synapse_modules_handle);