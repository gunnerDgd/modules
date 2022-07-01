#include <modules/component/details/manager/modules_compmgr_manip.h>

void
__synapse_modules_component_manager_push_component
	(__synapse_modules_component_manager* pCompMgr, __synapse_modules_component* pComp)
{
	pComp->hnd_component = 
		pComp->hnd_component
			= synapse_structure_double_linked_insert_back
					(pCompMgr->hnd_component_slot, &pComp, sizeof(void*));
}

void
__synapse_modules_component_manager_pop_component
	(__synapse_modules_component_manager* pCompMgr, __synapse_modules_component* pComp)
{
	synapse_structure_double_linked_erase_node
		(pCompMgr->hnd_component_slot, pComp->hnd_component);

	free
		(pComp);
}