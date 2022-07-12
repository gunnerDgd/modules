#pragma once
#include <modules/details/modules_type.h>
#include <structure/list/double_linked.h>

typedef struct
	__synapse_modules_probe_modules
{
	synapse_memory_block
		prb_module_mblock;
	synapse_structure_double_linked_node
		prb_module_handle;

	__synapse_modules*
		prb_module;
} __synapse_modules_probe_modules;

typedef struct
	__synapse_modules_probe
{
	synapse_structure_double_linked
		prb_handle;
	synapse_memory_block
		prb_mblock;
	synapse_memory_manager*
		prb_mman;
	DWORD
		prb_thread_id;
} __synapse_modules_probe;