#include <modules/modman/modman.hpp>

typename modules::standard::module_manager::module_type 
		 modules::standard::module_manager::load(string_type pPath)
{
	return module_type
				(synapse_modules_modman_module_initialize
					(__M_modman_handle, pPath.c_str()));
}

void modules::standard::module_manager::unload
	(module_type& pModule)
{
	synapse_modules_modman_module_cleanup
		(__M_modman_handle, pModule.__M_modhnd_native);
}

void modules::standard::module_manager::attach
	(module_type& pModule)
{
	synapse_modules_modman_module_attach
		(__M_modman_handle, pModule.__M_modhnd_native);
}

void modules::standard::module_manager::detach
	(module_type& pModule)
{
	synapse_modules_modman_module_detach
		(__M_modman_handle, pModule.__M_modhnd_native);
}

void modules::standard::module_manager::reload
	(module_type& pModule)
{
	synapse_modules_modman_module_reload
		(__M_modman_handle, pModule.__M_modhnd_native);
}