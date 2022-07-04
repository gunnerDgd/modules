#include <modules/modman/details/modules_modman_manip.h>
#include <process.h>

void
__synapse_modules_modman_module_entry
	(void* pVoidParam)
{
	__synapse_modules_modman_module* ptr_module
		= pVoidParam;

	synapse_modules_opaque_init
		(synapse_modules_handle, hnd_module, ptr_module);

	ptr_module->modman_module_thread.hnd_module_thread_entry
		(hnd_module);
}

void
__synapse_modules_modman_module_attach
	(__synapse_modules_modman* pModman, __synapse_modules_modman_module* pModule, void* pParam)
{
	synapse_modules_opaque_init
		(synapse_modules_handle, hnd_module, pModule);

	if (!pModule->hnd_module_interface.attach)
		return;

	pModule->hnd_module_interface.attach
		(hnd_module, pParam);
	pModule->modman_module_thread.hnd_module_thread
		= _beginthreadex
			(NULL, 0, &__synapse_modules_modman_module_entry, 
				pModule, 0, &pModule->modman_module_thread.hnd_module_thread_id);
}

void
__synapse_modules_modman_module_detach
	(__synapse_modules_modman* pModMan, __synapse_modules_modman_module* pModule, void* pParam)
{
	synapse_modules_opaque_init
		(synapse_modules_handle, hnd_module, pModule);
	
	if (!pModule->hnd_module_interface.detach)
		return;

	pModule->hnd_module_interface.detach
		(hnd_module, pParam);
	
	WaitForSingleObject
		(pModule->modman_module_thread.hnd_module_thread, INFINITE);
}

void
__synapse_modules_modman_module_reload
	(__synapse_modules_modman* pModMan, __synapse_modules_modman_module* pModule, void* pParam)
{
	synapse_modules_opaque_init
		(synapse_modules_handle, hnd_module, pModule);

	if(pModule->hnd_module_interface.reload)
		pModule->hnd_module_interface.reload
			(hnd_module, pParam);
}

__synapse_modules_modman_module*
__synapse_modules_modman_module_retrieve
	(__synapse_modules_modman* pModman, const char* pName)
{
	synapse_structure_double_linked_node ptr_seek
		= synapse_structure_double_linked_node_begin
				(pModman->modman_loaded_module);

	for( ; ptr_seek.opaque
		 ; ptr_seek = synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_modman_module* ptr_module
			= *(__synapse_modules_modman_module**)
					synapse_structure_double_linked_node_data
						(ptr_seek);

		int res_compare
			= strcmp
				(ptr_module->hnd_module_interface.modules_name, pName);
		if(res_compare == 0)
			return ptr_module;
	}

	return NULL;
}