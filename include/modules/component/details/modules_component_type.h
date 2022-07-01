#pragma once
#include <modules/traits/modman_component_interface.h>
#include <modules/modman/details/modules_modman_type.h>

#include <structure/list/double_linked.h>
#include <memory/mman/mman_traits.h>

typedef synapse_structure_double_linked
			__synapse_modules_component_manager_slot;

typedef synapse_structure_double_linked_node
			__synapse_modules_component_manager_slot_node;

typedef struct __synapse_modules_component
{
	synapse_modules_component_interface*
		ptr_component_interface;
	void*  
		ptr_component;
	__synapse_modules_component_manager_slot_node
		hnd_component;
} __synapse_modules_component;



typedef struct __synapse_modules_component_manager
{
	__synapse_modules_component_manager_slot
		hnd_component_slot;
} __synapse_modules_component_manager;

