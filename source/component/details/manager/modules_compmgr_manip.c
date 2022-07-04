#include <modules/component/details/manager/modules_compmgr_manip.h>

#include <stdlib.h>
#include <string.h>

__synapse_modules_component_interface*
__synapse_modules_component_manager_register_interface
	(__synapse_modules_component_manager* pCompMgr, 
	 synapse_modules_component_interface  pCompInterface,
	 const char							 *pCompInterfaceName,
	 void								 *pCompInterfaceType)
{
	__synapse_modules_component_interface*
		ptr_interface
			= malloc
				(sizeof(__synapse_modules_component_interface));

	ptr_interface->ptr_interface_construct
		= pCompInterface.construct;
	ptr_interface->ptr_interface_destruct
		= pCompInterface.destruct;
	ptr_interface->ptr_interface_duplicate
		= pCompInterface.duplicate;
	ptr_interface->ptr_component_interface_type
		= pCompInterfaceType;

	ptr_interface->hnd_component_interface =
		synapse_structure_double_linked_insert_back
			(pCompMgr->hnd_component_interface_slot,
				&ptr_interface, sizeof(__synapse_modules_component_interface*));
	strcpy
		(ptr_interface->ptr_component_interface_name,
				pCompInterfaceName);

	return
		ptr_interface;
}

void
__synapse_modules_component_manager_unregister_interface
	(__synapse_modules_component_manager   *pCompMgr, 
	 __synapse_modules_component_interface *pCompInterface)
{
	synapse_structure_double_linked_erase_node
		(pCompMgr->hnd_component_interface_slot,
			pCompInterface->hnd_component_interface);

	free
		(pCompInterface);
}

void
__synapse_modules_component_manager_register_component
	(__synapse_modules_component_manager *pCompMgr, 
	 __synapse_modules_component		 *pComponent)
{
	pComponent->hnd_component
		= synapse_structure_double_linked_insert_back
				(pCompMgr->hnd_component_slot, &pComponent, 
					sizeof(__synapse_modules_component*));
}

void
__synapse_modules_component_manager_unregister_component
	(__synapse_modules_component_manager *pCompMgr,
	 __synapse_modules_component		 *pComponent)
{
	synapse_structure_double_linked_erase_node
		(pCompMgr->hnd_component_slot, pComponent->hnd_component);
}

__synapse_modules_component_interface*
__synapse_modules_component_manager_retrieve_interface
	(__synapse_modules_component_manager *pCompMgr, 
	 const char							 *pCompInterfaceName)
{
	synapse_structure_double_linked_node
		ptr_seek
			= synapse_structure_double_linked_node_begin
					(pCompMgr->hnd_component_interface_slot);

	for( ; ptr_seek.opaque
		 ; ptr_seek
				= synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_component_interface*
			ptr_interface
				= *(__synapse_modules_component_interface**)
						synapse_structure_double_linked_node_data
							(ptr_seek);

		if(strcmp
				(ptr_interface->ptr_component_interface_name,
					pCompInterfaceName) == 0)
			return
				ptr_interface;
	}

	return NULL;
}

