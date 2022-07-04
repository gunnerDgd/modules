#pragma once
#include <modules/component/manager/component_manager_init.h>
#include <modules/component/manager/component_manager_manip.h>

#include <modules/component/component_type.h>
#include <modules/traits/modman_interface.h>

synapse_modules_export
synapse_modules_component_handle
synapse_modules_component_initialize
	(synapse_modules_component_interface_handle, int, ...);

synapse_modules_export
synapse_modules_component_handle
synapse_modules_component_initialize_from_vargs
	(synapse_modules_component_interface_handle, va_list);

synapse_modules_export
void
synapse_modules_component_cleanup
	(synapse_modules_component_handle);

synapse_modules_export
void*
synapse_modules_component_retrieve_object
	(synapse_modules_component_handle);

synapse_modules_export
void*
synapse_modules_component_retrieve_type
	(synapse_modules_component_handle);