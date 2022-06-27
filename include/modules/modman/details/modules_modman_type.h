#pragma once
#include <Windows.h>
#include <modules/traits/modman_interface.h>

#include <memory/mman/mman_traits.h>
#include <memory/pooling/dynamic_pooling_traits.h>
#include <memory/pooling/static_pooling_traits.h>

#include <execution/traits/sched/sched_queue_traits.h>
#include <execution/traits/sched/sched_traits.h>

#include <structure/list/double_linked.h>

#define __synapse_modules_modman_module_attached 0
#define __synapse_modules_modman_module_detached 1

typedef struct __synapse_modules_modman_module
{
	synapse_structure_double_linked_node
		modman_table_node;
	synapse_modules_handle
		modman_module_handle;

	HMODULE
		hnd_module;
	synapse_modules_interface
		hnd_module_interface;

	HANDLE
		  hnd_module_thread;
	DWORD
		  hnd_module_thread_id;
	void
		(*ptr_module_entry)(synapse_modules_handle);
	
} __synapse_modules_modman_module;

typedef struct __synapse_modules_modman
{
	synapse_memory_mman_traits*
		modman_mman;
	synapse_structure_double_linked
		modman_loaded_module;
} __synapse_modules_modman;