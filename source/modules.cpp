#include <modules/modules.hpp>
#include <modules/exception.hpp>

synapse::modules::modules::modules
	(path_type pModulePath)
		: __M_modules_handle
				(synapse_load_modules(pModulePath.generic_string().c_str()))
{
	if(!synapse_modules_opaque_handle_reference
			(__M_modules_handle))
				throw exception::invalid_module {};
}

synapse::modules::modules::modules
	(name_type pModuleName)
		: __M_modules_handle
				(synapse_import_modules(pModuleName.c_str()))
{
	if(!synapse_modules_opaque_handle_reference
			(__M_modules_handle))
				throw exception::module_not_loaded {};
}

synapse::modules::modules::~modules()
{
	synapse_unload_modules
		(__M_modules_handle);
}

synapse::modules::modules::error_code
	synapse::modules::modules::attach(modules& pModule)
{
	return
		synapse_attach_modules
			(pModule.__M_modules_handle);
}

synapse::modules::modules::error_code
	synapse::modules::modules::detach(modules& pModule)
{
	return
		synapse_detach_modules
			(pModule.__M_modules_handle);
}

synapse::modules::modules::error_code
	synapse::modules::modules::reload(modules& pModule)
{
	return
		synapse_reload_modules
			(pModule.__M_modules_handle);
}