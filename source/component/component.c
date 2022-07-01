#include <modules/component/component.h>
#include <modules/component/details/modules_component.h>

synapse_modules_component
synapse_modules_component_initialize
	(synapse_modules_handle pModule, int pVaCount, ...)
{
	va_list ptr_init_args;
	va_start
		(ptr_init_args, pVaCount);

	synapse_modules_opaque_init
		(synapse_modules_component, ptr_component,
			__synapse_modules_component_initialize
				(synapse_modules_opaque_reference(pModule), pVaCount, ptr_init_args));

	return ptr_component;
}

void
synapse_modules_component_cleanup
	(synapse_modules_component pComponent)
{
	__synapse_modules_component_cleanup
		(synapse_modules_opaque_reference(pComponent));
}