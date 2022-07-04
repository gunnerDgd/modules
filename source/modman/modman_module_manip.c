#include <modules/modman/modman_module_manip.h>
#include <modules/modman/details/modules_modman_module_manip.h>

synapse_modules_export
const char*
synapse_modules_modman_module_retrieve_name
	(synapse_modules_handle pHandle)
{
	return
		__synapse_modules_modman_module_retrieve_name
			(synapse_modules_opaque_reference(pHandle));
}

synapse_modules_export
synapse_modules_component_manager
synapse_modules_modman_module_retrieve_component_manager
	(synapse_modules_handle pHandle)
{
	return
		__synapse_modules_modman_module_retrieve_component_manager
			(synapse_modules_opaque_reference(pHandle));
}