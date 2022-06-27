#pragma once
#include <modules/modman/details/modules_modman_type.h>

void
__synapse_modules_modman_module_attach
	(__synapse_modules_modman*, __synapse_modules_modman_module*);

void
__synapse_modules_modman_module_detach
	(__synapse_modules_modman*, __synapse_modules_modman_module*);

void
__synapse_modules_modman_module_reload
	(__synapse_modules_modman*, __synapse_modules_modman_module*);

char*
__synapse_modules_modman_module_retrieve_name
	(__synapse_modules_modman_module*);