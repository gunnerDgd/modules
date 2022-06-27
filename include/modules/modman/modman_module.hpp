#pragma once
extern "C"
{
#include <modules/modman/modman.h>
}

#include <string>

namespace modules::standard {
	class module_handle
	{
		friend class module_manager;
		module_handle(synapse_modules_handle);
	public:
		using native_handle_type
			= synapse_modules_handle;
		using string_type
			= std::string;
		
	public:
		string_type name();

	private:
		native_handle_type
			__M_modhnd_native;
	};
}