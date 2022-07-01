#pragma once
#include <modules/component/details/modules_component_type.h>

void
__synapse_modules_component_manager_push_component
	(__synapse_modules_component_manager*, __synapse_modules_component*);

void
__synapse_modules_component_manager_pop_component
	(__synapse_modules_component_manager*, __synapse_modules_component*);