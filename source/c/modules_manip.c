#include <modules/modules_manip.h>
#include <modules/probe/details/probe_manip.h>

int
	synapse_modules_attach
		(synapse_modules_probe pProbe, synapse_modules pModules)
{
	return
		__synapse_modules_probe_attach_module
			(synapse_modules_opaque_handle_reference
				(pProbe),
			 synapse_modules_opaque_handle_reference
				(pModules));
}

int
	synapse_modules_detach
		(synapse_modules_probe pProbe, synapse_modules pModules)
{
	return
		__synapse_modules_probe_detach_module
			(synapse_modules_opaque_handle_reference
				(pProbe),
			 synapse_modules_opaque_handle_reference
				(pModules));
}

int
	synapse_modules_reload
		(synapse_modules_probe pProbe, synapse_modules pModules)
{
	return
		__synapse_modules_probe_reload_module
			(synapse_modules_opaque_handle_reference
				(pProbe),
			 synapse_modules_opaque_handle_reference
				(pModules));
}

synapse_modules
	synapse_modules_retrieve
		(synapse_modules_probe pProbe, const char* pModuleName)
{
	synapse_modules_opaque_handle_init
		(synapse_modules, hnd_module,
			__synapse_modules_probe_retrieve_module
				(synapse_modules_opaque_handle_reference
					(pProbe), pModuleName));

	return
		hnd_module;
}