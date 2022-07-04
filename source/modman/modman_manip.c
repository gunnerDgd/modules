#include <modules/modman/modman_manip.h>
#include <modules/modman/details/modules_modman_manip.h>

void
synapse_modules_modman_module_attach
	(synapse_modules_modman pModMan, synapse_modules_handle pModule, void* pParam)
{
	__synapse_modules_modman_module_attach
		(synapse_modules_opaque_reference(pModMan),
		 synapse_modules_opaque_reference(pModule));
}

void
synapse_modules_modman_module_detach
	(synapse_modules_modman pModMan, synapse_modules_handle pModule, void* pParam)
{
	__synapse_modules_modman_module_detach
		(synapse_modules_opaque_reference(pModMan),
		 synapse_modules_opaque_reference(pModule));
}

void
synapse_modules_modman_module_reload
	(synapse_modules_modman pModMan, synapse_modules_handle pModule, void* pParam)
{
	__synapse_modules_modman_module_reload
		(synapse_modules_opaque_reference(pModMan),
		 synapse_modules_opaque_reference(pModule));
}

synapse_modules_handle
synapse_modules_modman_module_retrieve
	(synapse_modules_modman pModman, const char* pName)
{
	synapse_modules_opaque_init
		(synapse_modules_handle, ptr_handle,
			__synapse_modules_modman_module_retrieve
				(synapse_modules_opaque_reference(pModman), pName));

	return ptr_handle;
}