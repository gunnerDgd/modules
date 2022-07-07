#include <modules/probe/details/probe_init.h>
#include <modules/details/modules_init.h>

__synapse_modules_probe*
	__synapse_modules_probe_initialize
		(synapse_memory_mman_traits* pMman, 
		 synapse_memory_mman_traits* pMmanProbe)
{
	synapse_memory_mman_block
		hnd_mblock
			= pMman->allocate
				(pMman->hnd_mman, NULL, sizeof(__synapse_modules_probe));

	__synapse_modules_probe*
		ptr_probe
			= pMman->block_pointer
					(hnd_mblock);

	ptr_probe->prb_mman
		= pMmanProbe;
	ptr_probe->prb_mblock
		= hnd_mblock;

	ptr_probe->prb_handle
		= synapse_structure_double_linked_initialize
				(pMmanProbe);

	return
		ptr_probe;
}

void
	__synapse_modules_probe_cleanup
		(synapse_memory_mman_traits* pMman, __synapse_modules_probe* pProbe)
{
	synapse_structure_double_linked_node
		ptr_seek
			= synapse_structure_double_linked_node_begin
					(pProbe->prb_handle);

	for ( ; ptr_seek.opaque
		  ; ptr_seek = synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_probe_modules*
			ptr_module
				= *(__synapse_modules_probe_modules**)
						synapse_structure_double_linked_node_data
							(ptr_seek);

		__synapse_modules_cleanup
			(pProbe->prb_mman, ptr_module->prb_module);
		synapse_structure_double_linked_erase_at
			(pProbe->prb_handle, ptr_module->prb_module_handle);

		pProbe->prb_mman->deallocate
			(pProbe->prb_mman->hnd_mman, ptr_module->prb_module_mblock);
	}

	pMman->deallocate
		(pMman->hnd_mman, pProbe->prb_mblock);
}