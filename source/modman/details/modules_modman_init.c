#include <modules/modman/details/modules_modman_init.h>
#include <stdlib.h>

__synapse_modules_modman*
__synapse_modules_modman_initialize
	(synapse_memory_mman_traits* pMman)
{
	__synapse_modules_modman* ptr_modman
		= malloc(sizeof(__synapse_modules_modman));

	ptr_modman->modman_loaded_module
		= synapse_structure_double_linked_initialize(pMman);
	ptr_modman->modman_mman
		= pMman;

	return ptr_modman;
}

void
__synapse_modules_modman_cleanup
	(__synapse_modules_modman* pMman)
{
	
}