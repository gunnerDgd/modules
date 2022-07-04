#include <modules/component/details/modules_component.h>
#include <stdlib.h>

__synapse_modules_component*
__synapse_modules_component_initialize
	(__synapse_modules_component_interface *pCompInterface,
	 va_list								pCompConstructArgs)
{
	__synapse_modules_component* ptr_component
		= malloc(sizeof(__synapse_modules_component));

	ptr_component->ptr_component_interface
		= pCompInterface;
	ptr_component->ptr_component
		= pCompInterface->ptr_interface_construct
				(pCompConstructArgs);

	return
		ptr_component;
}

void
__synapse_modules_component_cleanup
	(__synapse_modules_component* pComponent)
{
	pComponent->ptr_component_interface->ptr_interface_destruct
		(pComponent->ptr_component);
	free
		(pComponent);
}