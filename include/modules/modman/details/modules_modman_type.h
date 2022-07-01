#pragma once
#include <Windows.h>

#include <modules/traits/modman_component_interface.h>
#include <modules/traits/modman_interface.h>
#include <modules/component/component.h>

#include <memory/mman/mman_traits.h>
#include <memory/pooling/dynamic_pooling_traits.h>
#include <memory/pooling/static_pooling_traits.h>

#include <structure/list/double_linked.h>

#define __synapse_modules_modman_module_attached 0
#define __synapse_modules_modman_module_detached 1

typedef struct __synapse_modules_modman_module_thread
{
	HANDLE
		  hnd_module_thread;
	DWORD
		  hnd_module_thread_id;
	void
		(*hnd_module_thread_entry)(synapse_modules_handle);
} __synapse_modules_modman_module_thread;

typedef struct __synapse_modules_modman_module
{
	synapse_structure_double_linked_node
		modman_module_handle   ;
	synapse_modules_component_manager
		modman_module_component_manager;
	synapse_modules_component_interface
		modman_module_component_interface;
	__synapse_modules_modman_module_thread
		modman_module_thread   ;

	HMODULE
		hnd_module;
	synapse_modules_interface
		hnd_module_interface;
	
} __synapse_modules_modman_module;

typedef struct __synapse_modules_modman
{
	synapse_memory_mman_traits*
		modman_mman;
	synapse_structure_double_linked
		modman_loaded_module;
} __synapse_modules_modman;