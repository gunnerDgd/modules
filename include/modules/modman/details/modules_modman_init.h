#pragma once
#include <modules/modman/details/modules_modman_type.h>
#include <memory/mman/mman_traits.h>

__synapse_modules_modman*
__synapse_modules_modman_initialize
	(synapse_memory_mman_traits*);

void
__synapse_modules_modman_cleanup
	(__synapse_modules_modman*);