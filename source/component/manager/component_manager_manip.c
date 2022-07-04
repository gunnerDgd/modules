#include <modules/component/manager/component_manager_manip.h>
#include <modules/component/details/manager/modules_compmgr_manip.h>

synapse_modules_export
synapse_modules_component_interface_handle
synapse_modules_component_manager_register_interface
	(synapse_modules_component_manager   pCompMgr		   ,
	 synapse_modules_component_interface pCompInterface	   ,
	 const char							*pCompInterfaceName,
	 void								*pCompInterfaceType)
{
	synapse_modules_opaque_init
		(synapse_modules_component_interface_handle, hnd_interface,
			__synapse_modules_component_manager_register_interface
				(synapse_modules_opaque_reference(pCompMgr), 
					pCompInterface, pCompInterfaceName, pCompInterfaceType));

	return
		hnd_interface;
}

synapse_modules_export
void
synapse_modules_component_manager_unregister_interface
	(synapse_modules_component_manager			pCompMgr, 
	 synapse_modules_component_interface_handle pCompInterface)
{
	__synapse_modules_component_manager_unregister_interface
		(synapse_modules_opaque_reference(pCompMgr),
		 synapse_modules_opaque_reference(pCompInterface));
}

synapse_modules_export
void
synapse_modules_component_manager_register_component
	(synapse_modules_component_manager pCompMgr, 
	 synapse_modules_component_handle  pCompInterface)
{
	__synapse_modules_component_manager_register_component
		(synapse_modules_opaque_reference(pCompMgr),
		 synapse_modules_opaque_reference(pCompInterface));
}

synapse_modules_export
void
synapse_modules_component_manager_unregister_component
	(synapse_modules_component_manager pCompMgr, 
	 synapse_modules_component_handle  pCompInterface)
{
	__synapse_modules_component_manager_unregister_component
		(synapse_modules_opaque_reference(pCompMgr),
		 synapse_modules_opaque_reference(pCompInterface));
}

synapse_modules_export
synapse_modules_component_interface_handle
synapse_modules_component_manager_retrieve_interface
	(synapse_modules_component_manager pCompMgr, 
	 const char						  *pCompInterfaceName)
{
	synapse_modules_opaque_init
		(synapse_modules_component_interface_handle, hnd_interface,
			__synapse_modules_component_manager_retrieve_interface
				(synapse_modules_opaque_reference(pCompMgr),
				 pCompInterfaceName));

	return
		hnd_interface;
}