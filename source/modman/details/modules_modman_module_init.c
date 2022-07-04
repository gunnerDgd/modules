#include <modules/modman/details/modules_modman_module_init.h>

__synapse_modules_modman_module*
__synapse_modules_modman_module_initialize
	(__synapse_modules_modman* pModman, const char* pModPath)
{
	__synapse_modules_modman_module* ptr_modhnd
		= malloc(sizeof(__synapse_modules_modman_module));

	ptr_modhnd->hnd_module
		= LoadLibraryA(pModPath);
	ptr_modhnd->modman_module_thread.hnd_module_thread_entry
		= GetProcAddress(ptr_modhnd->hnd_module, "synapse_module_entry");
	ptr_modhnd->hnd_module_interface.initialize
		= GetProcAddress(ptr_modhnd->hnd_module, "synapse_module_initialize");
	ptr_modhnd->hnd_module_interface.cleanup
		= GetProcAddress(ptr_modhnd->hnd_module, "synapse_module_cleanup");

	ptr_modhnd->modman_module_handle
		= synapse_structure_double_linked_insert_back
			(pModman->modman_loaded_module, &pModman, sizeof(void*));
	ptr_modhnd->modman_module_component_manager
		= synapse_modules_component_manager_initialize
			(pModman->modman_mman);

	ptr_modhnd->hnd_module_interface.initialize
		(&ptr_modhnd->hnd_module_interface);

	return
		ptr_modhnd;
}

void
__synapse_modules_modman_module_cleanup
	(__synapse_modules_modman* pModman, __synapse_modules_modman_module* pModule)
{
	pModule->hnd_module_interface
		.cleanup();
	
	FreeLibrary
		(pModule->hnd_module);
	free
		(pModule);
}