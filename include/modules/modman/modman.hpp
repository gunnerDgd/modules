#pragma once
#include <modules/modman/modman_module.hpp>

namespace modules::standard {
	class module_manager
	{
	public:
		using native_handle_type
			= synapse_modules_modman;
		using module_type
			= module_handle;
		using string_type
			= std::string;
	public:
		
	public:
		module_type load  (string_type);
		void		unload(module_type&);

		void		attach(module_type&);
		void		detach(module_type&);
		void		reload(module_type&);

	private:
		native_handle_type
			__M_modman_handle;
	};
}