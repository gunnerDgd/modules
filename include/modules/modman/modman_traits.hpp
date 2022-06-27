#pragma once

#include <string>
#include <type_traits>

extern "C"
{
#include <modules/modman/modman.h>
}

namespace modules {
	template <typename ModmanType>
	class manager_traits
	{
	public:
		using manager_type = std::decay_t<ModmanType>;
		using module_type  = typename manager_type::module_type;
		
		using reference    = manager_type&;
		using pointer      = manager_type*;

	public:
		static module_type
			load(reference, std::string);
		static void
			unload(reference, module_type&);

		static void
			attach(reference, module_type&);
		static void
			detach(reference, module_type&);
		static void
			reload(reference, module_type&);

	};
}

template <typename ModmanType>
typename modules::manager_traits<ModmanType>::module_type
		 modules::manager_traits<ModmanType>::load(reference pModman, std::string pPath)
{
	return pModman.load(pPath);
}

template <typename ModmanType>
void
modules::manager_traits<ModmanType>::unload(reference pModman, module_type& pModule)
{
	pModman.unload(pModule);
}

template <typename ModmanType>
void
modules::manager_traits<ModmanType>::attach(reference pModman, module_type& pModule)
{
	pModman.attach(pModule);
}

template <typename ModmanType>
void
modules::manager_traits<ModmanType>::detach(reference pModman, module_type& pModule)
{
	pModman.detach(pModule);
}

template <typename ModmanType>
void
modules::manager_traits<ModmanType>::reload(reference pModman, module_type& pModule)
{
	pModman.reload(pModule);
}