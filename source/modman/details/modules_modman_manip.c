#include <modules/modman/details/modules_modman_manip.h>

void
__synapse_modules_modman_module_attach
	(__synapse_modules_modman* pModman, __synapse_modules_modman_module* pModule)
{
	pModule->hnd_module_interface.attach
		(pModule->modman_module_handle);
}

void
__synapse_modules_modman_module_detach
	(__synapse_modules_modman* pModMan, __synapse_modules_modman_module* pModule)
{
	pModule->hnd_module_interface.detach
		(pModule->modman_module_handle);
}

void
__synapse_modules_modman_module_reload
	(__synapse_modules_modman* pModMan, __synapse_modules_modman_module* pModule)
{
	if(pModule->hnd_module_interface.reload)
		pModule->hnd_module_interface.reload
			(pModule->modman_module_handle);
	else {
		pModule->hnd_module_interface.detach
			(pModule->modman_module_handle);
		pModule->hnd_module_interface.attach
			(pModule->modman_module_handle);
	}
}

void
__synapse_modules_modman_module_retrieve
	(__synapse_modules_modman*, const char*);

char*
__synapse_modules_modman_module_retrieve_name
	(__synapse_modules_modman_module* pModule)
{
	return
		pModule->hnd_module_interface.modules_name;
}