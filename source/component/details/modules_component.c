#include <modules/component/details/modules_component.h>
#include <stdlib.h>

__synapse_modules_component*
__synapse_modules_component_initialize
	(__synapse_modules_component_manager   *pCompMgr	  , 
	 __synapse_modules_component_interface *pCompInterface,
	 va_list								pCompConstructArgs)
{
	__synapse_modules_component* ptr_component
		= malloc(sizeof(__synapse_modules_component));

	ptr_component->ptr_component_interface
		= pCompInterface;
	ptr_component->ptr_component
		= pCompInterface->ptr_interface_construct
				(pCompConstructArgs);
	ptr_component->hnd_component
		= synapse_structure_double_linked_insert_back
				(pCompMgr->hnd_component_slot, &ptr_component, 
						sizeof(__synapse_modules_component));

	return
		ptr_component;
}

void
__synapse_modules_component_cleanup
	(__synapse_modules_component_manager* pCompMgr, 
	 __synapse_modules_component		* pComponent)
{
	pComponent->ptr_component_interface->ptr_interface_destruct
		(pComponent->ptr_component);
	synapse_structure_double_linked_erase_node
		(pCompMgr->hnd_component_slot, pComponent->hnd_component);
}