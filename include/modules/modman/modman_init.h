#pragma once
#include <modules/traits/modman_traits.h>
#include <memory/mman/mman_traits.h>

synapse_modules_modman
synapse_modules_modman_initialize
	(synapse_memory_mman_traits*);

void
synapse_modules_modman_cleanup
	(synapse_modules_modman);