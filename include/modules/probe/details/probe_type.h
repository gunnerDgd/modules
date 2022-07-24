#pragma once
#include <modules/details/modules_type.h>
#include <synapse/structure/list/double_linked.h>

typedef struct
	__synapse_modules_probe_modules
{
	synapse_double_linked_node
		prb_module_handle;
	__synapse_modules*
		prb_module;
	DWORD
		prb_module_thread_id;
} __synapse_modules_probe_modules;

typedef struct
	__synapse_modules_probe
{
	synapse_double_linked
		prb_handle;
	synapse_memory_manager*
		prb_mman;
	DWORD
		prb_thread_id;
} __synapse_modules_probe;