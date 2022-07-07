#pragma once
#include <modules/defines/handle/opaque_handle.h>

synapse_modules_opaque_handle_declare
	(synapse_modules)

typedef struct 
	synapse_modules_metadata
{
	const char*
		modules_name;
	size_t
		modules_name_length;
	uint16_t
		modules_version[4];
} synapse_modules_metadata;

typedef struct
	synapse_modules_traits
{
	int
		(*attach)(synapse_modules);
	int
		(*detach)(synapse_modules);
	int
		(*reload)(synapse_modules);
} synapse_modules_traits;