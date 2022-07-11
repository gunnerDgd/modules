#pragma once
extern "C"
{
#include <modules/modules.h>
}

#include <filesystem>
#include <string>

namespace synapse::modules {
	void
		initialize();
	void
		cleanup   ();

	class modules
	{
	public:
		using path_type  = std::filesystem::path;
		using name_type  = std::string;
		using error_code = int;
		using native_handle_type
						 = synapse_modules;

	public:
		modules (path_type);
		modules (name_type);
		~modules();

	public:
		static error_code
				attach(modules&);
		static error_code
				detach(modules&);
		static error_code
				reload(modules&);

	private:
		native_handle_type
			__M_modules_handle;
	};
}