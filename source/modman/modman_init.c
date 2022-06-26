#include <modules/modman/modman_init.h>
#include <modules/modman/details/modules_modman_init.h>

synapse_modules_modman
synapse_modules_modman_initialize
	(synapse_memory_mman_traits* pMman)
{
	synapse_modules_opaque_init
		(synapse_modules_modman,
		 ptr_modman,
		 __synapse_modules_modman_initialize(pMman));

	return
		ptr_modman;
}

void
synapse_modules_modman_cleanup
	(synapse_modules_modman pModMan)
{
	__synapse_modules_modman_cleanup
		(synapse_modules_opaque_reference(pModMan));
}