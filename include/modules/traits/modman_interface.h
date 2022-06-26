#pragma once
#include <modules/traits/modman_traits.h>

typedef struct synapse_modules_interface
{
	char modules_name[255];
	
	void (*initialize)(struct synapse_moduels_interface*);
	void (*cleanup)   ();

	void
		(*attach)(synapse_modules_handle);
	void
		(*detach)(synapse_modules_handle);
	void
		(*reload)(synapse_modules_handle);
} synapse_modules_interface;