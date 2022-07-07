#include <modules/probe/probe_init.h>
#include <modules/probe/details/probe_init.h>

synapse_modules_probe
	synapse_modules_probe_initialize
		(synapse_memory_mman_traits* pMman, synapse_memory_mman_traits* pMmanProbe)
{
	synapse_modules_opaque_handle_init
		(synapse_modules_probe, hnd_probe,
			__synapse_modules_probe_initialize
					(pMman, pMmanProbe));

	return
		hnd_probe;
}

void
	synapse_modules_probe_cleanup
		(synapse_memory_mman_traits* pMman, synapse_modules_probe pProbe)
{
	__synapse_modules_probe_cleanup
		(pMman,
			synapse_modules_opaque_handle_reference
				(pProbe));
}