#include <modules/modules.h>
#include <synapse/__internal/modules/init.h>

#include <synapse/memory/interface/memory_manager.h>
#include <synapse/memory/standard_heap.h>

#include <modules/probe/probe_init.h>
#include <modules/probe/details/probe_manip.h>

#include <modules/modules_init.h>
#include <modules/modules_manip.h>

static synapse_memory_manager
			*__synapse_modules_mman;
static synapse_modules_probe
			__synapse_modules_probe_handle;

synapse_modules_dll
	void
		synapse_modules_initialize_system
			()
{
	if(!__synapse_modules_mman)
		__synapse_modules_mman
			= synapse_initialize_standard_heap();

	if(!synapse_modules_opaque_handle_reference
			(__synapse_modules_probe_handle))
				__synapse_modules_probe_handle
						= synapse_modules_probe_initialize
								(__synapse_modules_mman);
}

synapse_modules_dll
	void
		synapse_modules_cleanup_system
			()
{
	if(synapse_modules_opaque_handle_reference
			(__synapse_modules_probe_handle))
				synapse_modules_probe_cleanup
					(__synapse_modules_probe_handle);
	
	if(__synapse_modules_mman)
		synapse_cleanup_standard_heap
			(__synapse_modules_mman);

	synapse_modules_opaque_handle_reference
		(__synapse_modules_probe_handle) = NULL;
	
	__synapse_modules_mman = NULL;
}


synapse_modules_dll
	synapse_modules
		synapse_load_modules
			(const char* pModulePath)
{
	return
		synapse_modules_initialize
			(__synapse_modules_probe_handle, pModulePath);
}

synapse_modules_dll
	void
		synapse_unload_modules
			(synapse_modules pModule)
{
	synapse_modules_cleanup
		(__synapse_modules_probe_handle, pModule);
}

synapse_modules_dll
	int
		synapse_attach_modules
			(synapse_modules pModule)
{
	if(!synapse_modules_opaque_handle_reference
			(pModule))
				return -1;

	return
		synapse_modules_attach
			(__synapse_modules_probe_handle, pModule);
}

synapse_modules_dll
	int
		synapse_detach_modules
			(synapse_modules pModule)
{
	if(!synapse_modules_opaque_handle_reference
			(pModule))
				return -1;

	return
		synapse_modules_detach
			(__synapse_modules_probe_handle, pModule);
}

synapse_modules_dll
	int
		synapse_reload_modules
			(synapse_modules pModule)
{
	if(!synapse_modules_opaque_handle_reference
			(pModule))
				return -1;

	return
		synapse_modules_reload
			(__synapse_modules_probe_handle, pModule);
}

synapse_modules_dll
	synapse_modules
		synapse_import_modules
			(const char* pModuleName)
{
	return
		synapse_modules_retrieve
			(__synapse_modules_probe_handle, pModuleName);
}