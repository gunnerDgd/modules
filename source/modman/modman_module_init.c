#include <modules/modman/modman_module_init.h>
#include <modules/modman/details/modules_modman_module_init.h>

synapse_modules_handle
synapse_modules_modman_module_initialize
	(synapse_modules_modman pModMan, const char* pModule)
{
	synapse_modules_opaque_init
		(synapse_modules_handle,
		 ptr_modhnd,
		 __synapse_modules_modman_module_initialize
			(synapse_modules_opaque_reference(pModMan), pModule));

	return
		ptr_modhnd;
}

void
synapse_modules_modman_module_cleanup
	(synapse_modules_modman pModMan, synapse_modules_handle pModule)
{
	__synapse_modules_modman_module_cleanup
		(synapse_modules_opaque_reference(pModMan),
		 synapse_modules_opaque_reference(pModule));
}