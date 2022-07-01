#include <modules/component/manager/component_manager_manip.h>
#include <modules/component/details/manager/modules_compmgr_manip.h>

void
synapse_modules_component_manager_push_component
	(synapse_modules_component_manager pCompMgr, synapse_modules_component pModule)
{
	__synapse_modules_component_manager_push_component
		(synapse_modules_opaque_reference(pCompMgr),
		 synapse_modules_opaque_reference(pModule));
}

void
synapse_modules_component_manager_pop_component
	(synapse_modules_component_manager pCompMgr, synapse_modules_component pModule)
{
	__synapse_modules_component_manager_pop_component
		(synapse_modules_opaque_reference(pCompMgr),
		 synapse_modules_opaque_reference(pModule));
}