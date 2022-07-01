#pragma once
#include <modules/component/component_type.h>

void
synapse_modules_component_manager_push_component
	(synapse_modules_component_manager, synapse_modules_component);

void
synapse_modules_component_manager_pop_component
	(synapse_modules_component_manager, synapse_modules_component);