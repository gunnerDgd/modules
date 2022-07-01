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

void*
synapse_modules_modman_module_retrieve_procedure
	(synapse_modules_handle pModule, const char* pProcName)
{
	return
		__synapse_modules_modman_module_retrieve_procedure
			(synapse_modules_opaque_reference(pModule), pProcName);
}

char*
synapse_modules_modman_module_retrieve_name
	(synapse_modules_handle pModule)
{
	return
		__synapse_modules_modman_module_retrieve_name
			(synapse_modules_opaque_reference(pModule));
}