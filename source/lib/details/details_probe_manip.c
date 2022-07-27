#include <modules/probe/details/probe_manip.h>
#include <modules/details/modules_init.h>

#include <synapse/memory/memory.h>

#include <string.h>

__synapse_modules_probe_modules*
	__synapse_modules_probe_load_module
		(__synapse_modules_probe* pProbe, const char* pModulePath)
{
	__synapse_modules_probe_modules*
		ptr_modules_probe;
	int
		res_modules_initialize;
	__synapse_modules*
		ptr_modules;

	ptr_modules
		= __synapse_modules_initialize
				(pProbe->prb_mman, pModulePath, &res_modules_initialize);

	if (!ptr_modules) return NULL;

	ptr_modules_probe
		= synapse_system_allocate
				(sizeof(__synapse_modules_probe_modules));

	ptr_modules_probe->prb_module_thread_id
		= GetCurrentThreadId();
	ptr_modules_probe->prb_module
		= ptr_modules;
	ptr_modules_probe->prb_module_handle
		= synapse_double_linked_insert_back
				(pProbe->prb_handle, &ptr_modules_probe, sizeof(__synapse_modules_probe_modules*));

	return
		ptr_modules_probe;
}

void
	__synapse_modules_probe_unload_module
		(__synapse_modules_probe* pProbe, __synapse_modules_probe_modules* pModules)
{
	DWORD 
		id_current_thread
			= GetCurrentThreadId();

	if (id_current_thread != pProbe->prb_thread_id
			&& id_current_thread != pModules->prb_module_thread_id)
				return;

	__synapse_modules_cleanup
		(pProbe->prb_mman, pModules->prb_module);
	synapse_double_linked_erase_at
		(pProbe->prb_handle, pModules->prb_module_handle);
	synapse_system_deallocate
		(pModules);
}

__synapse_modules_probe_modules*
	__synapse_modules_probe_retrieve_module
		(__synapse_modules_probe* pProbe, const char* pName)
{
	synapse_double_linked_node
		ptr_seek
			= synapse_double_linked_node_begin
					(pProbe->prb_handle);

	if (pProbe->prb_thread_id != GetCurrentThreadId())
		return NULL;

	for ( ; ptr_seek.opaque
		  ; ptr_seek = synapse_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_probe_modules*
			ptr_modules_probe
				= *(__synapse_modules_probe_modules**)
						synapse_double_linked_node_data
							(ptr_seek);

		if(strcmp
				(ptr_modules_probe->prb_module->mod_metadata.modules_name,
					pName) == 0)
			return
				ptr_modules_probe;
	}

	return NULL;
}

int
	__synapse_modules_probe_attach_module
		(__synapse_modules_probe* pProbe, __synapse_modules_probe_modules* pModules)
{
	synapse_modules_opaque_handle_init
		(synapse_modules, hnd_modules, pModules);
	
	if (pProbe->prb_thread_id != GetCurrentThreadId())
		return -1;

	int
		res_attach
			= (pModules->prb_module->mod_traits.attach)
					? pModules->prb_module->mod_traits.attach(hnd_modules)
					: -1;

	return
		res_attach;
}

int
	__synapse_modules_probe_detach_module
		(__synapse_modules_probe* pProbe, __synapse_modules_probe_modules* pModules)
{
	synapse_modules_opaque_handle_init
		(synapse_modules, hnd_modules, pModules);

	if (pProbe->prb_thread_id != GetCurrentThreadId())
		return -1;

	int
		res_detach
			= (pModules->prb_module->mod_traits.detach)
					? pModules->prb_module->mod_traits.detach(hnd_modules)
					: -1;

	return
		res_detach;
}

int
	__synapse_modules_probe_reload_module
		(__synapse_modules_probe* pProbe, __synapse_modules_probe_modules* pModules)
{
	synapse_modules_opaque_handle_init
		(synapse_modules, hnd_modules, pModules);

	if (pProbe->prb_thread_id != GetCurrentThreadId())
		return -1;

	int
		res_reload
			= (pModules->prb_module->mod_traits.reload)
					? pModules->prb_module->mod_traits.reload(hnd_modules)
					: -1;

	return
		res_reload;
}