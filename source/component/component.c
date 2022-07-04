#include <modules/component/component.h>
#include <modules/component/details/modules_component.h>

#include <modules/modman/details/modules_modman_type.h>

synapse_modules_component_handle
synapse_modules_component_initialize
	(synapse_modules_handle					    pHandle, 
	 synapse_modules_component_interface_handle pInterface,
	 int										pArgCount, ...)
{
	va_list ptr_vargs;
	va_start
		(ptr_vargs, pArgCount);

	return
		synapse_modules_component_initialize_from_vargs
			(pHandle, pInterface, ptr_vargs);
}

synapse_modules_component_handle
synapse_modules_component_initialize_from_vargs
	(synapse_modules_handle						pHandle, 
	 synapse_modules_component_interface_handle pInterface, 
	 va_list									pInterfaceArgument)
{
	__synapse_modules_modman_module* ptr_module
		= synapse_modules_opaque_reference
				(pHandle);

	synapse_modules_opaque_init
		(synapse_modules_component_handle, hnd_component,
			__synapse_modules_component_initialize
				(synapse_modules_opaque_reference
					(ptr_module->modman_module_component_manager),
				 synapse_modules_opaque_reference
					(pInterface), pInterfaceArgument));

	return
		hnd_component;
}

void
synapse_modules_component_cleanup
	(synapse_modules_handle pHandle, synapse_modules_component_handle pComponent)
{
	__synapse_modules_component_cleanup
		(synapse_modules_opaque_reference(pHandle),
		 synapse_modules_opaque_reference(pComponent));
}

void*
synapse_modules_component_retrieve_object
	(synapse_modules_component_handle pHandle)
{
	return
		synapse_modules_opaque_cast
			(pHandle, __synapse_modules_component*)
				->ptr_component;
}