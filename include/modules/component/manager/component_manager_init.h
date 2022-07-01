#pragma once
#include <memory/mman/mman_traits.h>
#include <modules/component/component_type.h>

synapse_modules_component_manager
synapse_modules_component_manager_initialize
	(synapse_memory_mman_traits*);

void
synapse_modules_component_manager_cleanup
	(synapse_modules_component_manager);