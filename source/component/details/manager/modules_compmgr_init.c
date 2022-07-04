#include <modules/component/details/manager/modules_compmgr_init.h>
#include <modules/component/details/modules_component.h>

#include <stdlib.h>

__synapse_modules_component_manager*
__synapse_modules_component_manager_initialize
	(synapse_memory_mman_traits* pMman)
{
	__synapse_modules_component_manager* ptr_compmgr
		= malloc(sizeof(__synapse_modules_component_manager));

	ptr_compmgr->hnd_component_slot
		= synapse_structure_double_linked_initialize
				(pMman);
	ptr_compmgr->hnd_component_interface_slot
		= synapse_structure_double_linked_initialize
				(pMman);

	return ptr_compmgr;
}

void
__synapse_modules_component_manager_cleanup
	(__synapse_modules_component_manager* pComponent)
{
	__synapse_modules_component_manager_slot_node 
		ptr_seek
			= synapse_structure_double_linked_node_begin
					(pComponent->hnd_component_slot);
	__synapse_modules_component_manager_slot_node 
		ptr_interface_seek
			= synapse_structure_double_linked_node_begin
					(pComponent->hnd_component_interface_slot);

	for( ; ptr_seek.opaque 
		 ; synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_component* ptr_hnd
			= *(__synapse_modules_component**)
					synapse_structure_double_linked_node_data
						(ptr_seek);

		__synapse_modules_component_cleanup
			(pComponent, ptr_hnd);
	}

	for( ; ptr_interface_seek.opaque
		 ; synapse_structure_double_linked_node_next(ptr_interface_seek))
	{
		__synapse_modules_component_interface* ptr_hnd
			= *(__synapse_modules_component_interface**)
					synapse_structure_double_linked_node_data
						(ptr_interface_seek);
		
		__synapse_modules_component_manager_unregister_interface
			(pComponent, ptr_hnd);
	}

	free
		(pComponent);
}