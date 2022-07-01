#pragma once
#include <modules/component/details/modules_component_type.h>
#include <modules/component/details/manager/modules_compmgr_manip.h>

__synapse_modules_component_manager*
__synapse_modules_component_manager_initialize
	(synapse_memory_mman_traits*);

void
__synapse_modules_component_manager_cleanup
	(__synapse_modules_component_manager*);