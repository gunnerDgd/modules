#pragma once
#include <modules/component/manager/component_manager_init.h>
#include <modules/component/details/manager/modules_compmgr_init.h>

synapse_modules_export
synapse_modules_component_manager
synapse_modules_component_manager_initialize
	(synapse_memory_mman_traits* pMman)
{
	synapse_modules_opaque_init
		(synapse_modules_component_manager, ptr_compmgr,
			__synapse_modules_component_manager_initialize
				(pMman));

	return ptr_compmgr;
}

synapse_modules_export
void
synapse_modules_component_manager_cleanup
	(synapse_modules_component_manager pCompMgr)
{
	__synapse_modules_component_manager_cleanup
		(synapse_modules_opaque_reference(pCompMgr));
}