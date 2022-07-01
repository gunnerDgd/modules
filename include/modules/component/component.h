#pragma once
#include <modules/component/manager/component_manager_init.h>
#include <modules/component/manager/component_manager_manip.h>

#include <modules/component/component_type.h>
#include <modules/traits/modman_interface.h>

synapse_modules_component
synapse_modules_component_initialize
	(synapse_modules_handle, int, ...);

void
synapse_modules_component_cleanup
	(synapse_modules_component);