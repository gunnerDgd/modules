#include <modules/component/details/modules_component.h>
#include <stdlib.h>

__synapse_modules_component*
__synapse_modules_component_initialize
	(__synapse_modules_modman_module* pModule, int pVaCount, va_list pVaList)
{
	__synapse_modules_component* ptr_component
		= malloc(sizeof(__synapse_modules_component));

	ptr_component->ptr_component_interface
		= &pModule->modman_module_component_interface;
	ptr_component->ptr_component
		= pModule->modman_module_component_interface.component_create
				(pVaList);
	
	return
		ptr_component;
}

void
__synapse_modules_component_cleanup
	(__synapse_modules_component* pComponent)
{
	pComponent->ptr_component_interface->component_delete
		(pComponent->ptr_component);
	free
		(pComponent);
}