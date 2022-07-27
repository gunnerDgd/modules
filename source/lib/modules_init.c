#include <modules/probe/details/probe_manip.h>
#include <modules/modules_init.h>

synapse_modules
	synapse_modules_initialize
		(synapse_modules_probe pProbe, const char* pModulePath)
{
	synapse_modules_opaque_handle_init
		(synapse_modules, hnd_modules,
			__synapse_modules_probe_load_module
				(synapse_modules_opaque_handle_reference
					(pProbe), pModulePath));

	return
		hnd_modules;
}

void
	synapse_modules_cleanup
		(synapse_modules_probe pProbe, synapse_modules pModule)
{
	__synapse_modules_probe_unload_module
		(synapse_modules_opaque_handle_reference(pProbe),
		 synapse_modules_opaque_handle_reference(pModule));
}