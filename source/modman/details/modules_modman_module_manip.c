#include <modules/modman/details/modules_modman_module_manip.h>

const char*
__synapse_modules_modman_module_retrieve_name
	(__synapse_modules_modman_module* pModule)
{
	return
		pModule->hnd_module_interface.modules_name;
}

synapse_modules_component_manager
__synapse_modules_modman_module_retrieve_component_manager
	(__synapse_modules_modman_module* pModule)
{
	return
		pModule->modman_module_component_manager;
}