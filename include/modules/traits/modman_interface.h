#pragma once
#include <modules/traits/modman_traits.h>

#define synapse_modules_export _declspec(dllexport)

typedef struct synapse_modules_interface
{
	char modules_name[255];
	
	void (*initialize)(struct synapse_moduels_interface*);
	void (*cleanup)   ();

	void
		(*attach)(synapse_modules_handle, void*);
	void
		(*detach)(synapse_modules_handle, void*);
	void
		(*reload)(synapse_modules_handle, void*);
} synapse_modules_interface;