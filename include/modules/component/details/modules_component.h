#pragma once
#include <modules/component/details/modules_component_type.h>

__synapse_modules_component*
__synapse_modules_component_initialize
	(__synapse_modules_modman_module*, int, va_list);

void
__synapse_modules_component_cleanup
	(__synapse_modules_component*);