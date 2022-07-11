#pragma once
#include <modules/interface/modules.h>
#include <synapse/memory/interface/memory_manager.h>

#include <Windows.h>

typedef struct
	__synapse_modules
{
	synapse_memory_block
		mod_mblock;

	synapse_modules_metadata
		mod_metadata;
	synapse_modules_traits
		mod_traits;
	
	HMODULE
		mod_handle;
	int
		(*mod_initialize)
			(synapse_modules_metadata*, synapse_modules_traits*);
	void
		(*mod_cleanup)();
} __synapse_modules;