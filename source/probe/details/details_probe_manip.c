#include <modules/probe/details/probe_manip.h>
#include <modules/details/modules_init.h>

#include <string.h>

__synapse_modules_probe_modules*
	__synapse_modules_probe_load_module
		(__synapse_modules_probe* pProbe, const char* pModulePath)
{
	synapse_memory_mman_block
		hnd_mblock;
	__synapse_modules_probe_modules*
		ptr_modules_probe;

	int
		res_modules_initialize;
	__synapse_modules*
		ptr_modules
			= __synapse_modules_initialize
					(pProbe->prb_mman, pModulePath, &res_modules_initialize);

	if (!ptr_modules) return NULL;

	hnd_mblock
		= pProbe->prb_mman->allocate
				(pProbe->prb_mman->hnd_mman, NULL, sizeof(__synapse_modules_probe_modules));
	ptr_modules_probe
		= pProbe->prb_mman->block_pointer
				(hnd_mblock);

	ptr_modules_probe->prb_module
		= ptr_modules;
	ptr_modules_probe->prb_module_mblock
		= hnd_mblock;
	ptr_modules_probe->prb_module_handle
		= synapse_structure_double_linked_insert_back
				(pProbe->prb_handle, &ptr_modules_probe, sizeof(__synapse_modules_probe_modules*));

	return
		ptr_modules_probe;
}

void
	__synapse_modules_probe_unload_module
		(__synapse_modules_probe* pProbe, __synapse_modules_probe_modules* pModules)
{
	__synapse_modules_cleanup
		(pProbe->prb_mman, pModules->prb_module);
	synapse_structure_double_linked_erase_at
		(pProbe->prb_handle, pModules->prb_module_handle);

	pProbe->prb_mman->deallocate
		(pProbe->prb_mman->hnd_mman, pModules->prb_module_mblock);	
}

__synapse_modules_probe_modules*
	__synapse_modules_probe_retrieve_module
		(__synapse_modules_probe* pProbe, const char* pName)
{
	synapse_structure_double_linked_node
		ptr_seek
			= synapse_structure_double_linked_node_begin
					(pProbe->prb_handle);

	for ( ; ptr_seek.opaque
		  ; ptr_seek = synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_probe_modules*
			ptr_modules_probe
				= *(__synapse_modules_probe_modules**)
						synapse_structure_double_linked_node_data
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

	int
		res_reload
			= (pModules->prb_module->mod_traits.reload)
					? pModules->prb_module->mod_traits.reload(hnd_modules)
					: -1;

	return
		res_reload;
}