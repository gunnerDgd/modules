#pragma once
#include <modules/traits/modman_component_interface.h>
#include <structure/list/double_linked.h>

typedef synapse_structure_double_linked
			__synapse_modules_component_manager_slot;

typedef synapse_structure_double_linked_node
			__synapse_modules_component_manager_slot_node;

typedef synapse_structure_double_linked
			__synapse_modules_component_manager_interface_slot;

typedef synapse_structure_double_linked_node
			__synapse_modules_component_manager_interface_node;


typedef struct __synapse_modules_component_interface
{
	__synapse_modules_component_manager_interface_node
		hnd_component_interface;
	void*
		ptr_component_interface_type;
	const char
		ptr_component_interface_name[255];
	
	void*
		(*ptr_interface_construct)(va_list);
	void
		(*ptr_interface_destruct) (void*);
	void*
		(*ptr_interface_duplicate)(void*);
} __synapse_modules_component_interface;

typedef struct __synapse_modules_component
{
	__synapse_modules_component_interface*
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
	__synapse_modules_component_manager_interface_slot
		hnd_component_interface_slot;
} __synapse_modules_component_manager;

