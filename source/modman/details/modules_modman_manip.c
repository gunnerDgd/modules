#include <modules/modman/details/modules_modman_manip.h>
#include <process.h>

void
__synapse_modules_modman_module_entry
	(void* pVoidParam)
{
	__synapse_modules_modman_module* ptr_module
		= pVoidParam;

	ptr_module->modman_module_thread.hnd_module_thread_entry
		(ptr_module->modman_module_handle);
}

void
__synapse_modules_modman_module_attach
	(__synapse_modules_modman* pModman, __synapse_modules_modman_module* pModule, void* pParam)
{
	pModule->hnd_module_interface.attach
		(pModule->modman_module_handle, pParam);
	pModule->modman_module_thread.hnd_module_thread
		= _beginthreadex
			(NULL, 0, &__synapse_modules_modman_module_entry, 
				pModule, 0, &pModule->modman_module_thread.hnd_module_thread_id);
}

void
__synapse_modules_modman_module_detach
	(__synapse_modules_modman* pModMan, __synapse_modules_modman_module* pModule, void* pParam)
{
	pModule->hnd_module_interface.detach
		(pModule->modman_module_handle, pParam);
	
	WaitForSingleObject
		(pModule->modman_module_thread.hnd_module_thread, INFINITE);
}

void
__synapse_modules_modman_module_reload
	(__synapse_modules_modman* pModMan, __synapse_modules_modman_module* pModule, void* pParam)
{
	if(pModule->hnd_module_interface.reload)
		pModule->hnd_module_interface.reload
			(pModule->modman_module_handle, pParam);
	else {
		pModule->hnd_module_interface.detach
			(pModule->modman_module_handle, pParam);
		pModule->hnd_module_interface.attach
			(pModule->modman_module_handle, pParam);
	}
}

void*
__synapse_modules_modman_module_retrieve_procedure
	(__synapse_modules_modman_module* pModule, const char* pProcName)
{
	return
		GetProcAddress(pModule->hnd_module, pProcName);
}

char*
__synapse_modules_modman_module_retrieve_name
	(__synapse_modules_modman_module* pModule)
{
	return
		pModule->hnd_module_interface.modules_name;
}