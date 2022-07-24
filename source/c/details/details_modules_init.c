#include <modules/details/modules_init.h>
#include <synapse/memory/memory.h>

__synapse_modules*
	__synapse_modules_initialize
		(synapse_memory_manager* pMman, 
			const char* pModulePath, int* pErrorCode)
{
	HMODULE
		hnd_module = LoadLibraryA(pModulePath);
	__synapse_modules*
		ptr_module;
	int
		res_module_initialize;

	if (!hnd_module) return NULL;
	ptr_module
		= synapse_system_allocate
				(sizeof(__synapse_modules));

	ptr_module->mod_handle
		= hnd_module;
	ptr_module->mod_initialize
		= GetProcAddress(hnd_module, "synapse_modules_initialize");
	ptr_module->mod_cleanup
		= GetProcAddress(hnd_module, "synapse_modules_cleanup");

	if (!(ptr_module->mod_initialize && ptr_module->mod_cleanup))
		goto __init_failed;

	res_module_initialize
		= ptr_module->mod_initialize
				(&ptr_module->mod_metadata, &ptr_module->mod_traits);

	if (res_module_initialize) {
		*pErrorCode
			= res_module_initialize;
		goto __init_failed;
	}
	else
		goto __init_success;

__init_failed:
	FreeLibrary
		(hnd_module);
	synapse_system_deallocate
		(ptr_module);

	return NULL;
__init_success:
	return ptr_module;
}

void
	__synapse_modules_cleanup
		(synapse_memory_manager* pMman, __synapse_modules* pModules)
{
	pModules->mod_cleanup();

	FreeLibrary
		(pModules->mod_handle);
	synapse_system_deallocate
		(pModules);
}