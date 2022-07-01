#include <modules/component/details/manager/modules_compmgr_init.h>
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

	for( ; ptr_seek.opaque 
		 ; synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_component* ptr_hnd
			= *(__synapse_modules_component**)
					synapse_structure_double_linked_node_data
						(ptr_seek);

		__synapse_modules_component_manager_pop_component
			(pComponent, ptr_hnd);
	}

	free
		(pComponent);
}