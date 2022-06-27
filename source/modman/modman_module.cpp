#include <modules/modman/modman_module.hpp>

modules::standard::module_handle::module_handle
	(synapse_modules_handle pModHnd) : __M_modhnd_native(pModHnd) {}

typename modules::standard::module_handle::string_type
		 modules::standard::module_handle::name()
{
	return
		string_type
			(synapse_modules_modman_module_retrieve_name(__M_modhnd_native));
}