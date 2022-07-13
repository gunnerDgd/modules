#include <modules/probe/details/probe_init.h>
#include <modules/details/modules_init.h>

__synapse_modules_probe*
	__synapse_modules_probe_initialize
		(synapse_memory_manager* pMman)
{
	synapse_memory_block
		hnd_mblock
			= pMman->allocate
				(pMman->hnd_mman, NULL, sizeof(__synapse_modules_probe));

	__synapse_modules_probe*
		ptr_probe
			= pMman->block_pointer
					(hnd_mblock);

	ptr_probe->prb_mman
		= pMman;
	ptr_probe->prb_mblock
		= hnd_mblock;

	ptr_probe->prb_handle
		= synapse_structure_double_linked_initialize
				(pMman);
	ptr_probe->prb_thread_id
		= GetCurrentThreadId();

	return
		ptr_probe;
}

void
	__synapse_modules_probe_cleanup
		(__synapse_modules_probe* pProbe)
{
	synapse_structure_double_linked_node
		ptr_seek
			= synapse_structure_double_linked_node_begin
					(pProbe->prb_handle);

	if (pProbe->prb_thread_id != GetCurrentThreadId())
		return;

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
	}

	synapse_structure_double_linked_cleanup
		(pProbe->prb_handle);
	pProbe->prb_mman->deallocate
		(pProbe->prb_mman->hnd_mman, pProbe->prb_mblock);
}