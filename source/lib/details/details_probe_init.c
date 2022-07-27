#include <modules/probe/details/probe_init.h>
#include <modules/probe/details/probe_manip.h>

#include <modules/details/modules_init.h>

__synapse_modules_probe*
	__synapse_modules_probe_initialize
		(synapse_memory_manager* pMman)
{
	__synapse_modules_probe*
		ptr_probe
			= synapse_system_allocate
					(sizeof(__synapse_modules_probe));

	ptr_probe->prb_mman
		= pMman;
	ptr_probe->prb_handle
		= synapse_initialize_double_linked
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
	synapse_double_linked_node
		ptr_seek
			= synapse_double_linked_node_begin
					(pProbe->prb_handle);

	if (pProbe->prb_thread_id != GetCurrentThreadId())
		return;

	for ( ; ptr_seek.opaque
		  ; ptr_seek = synapse_double_linked_node_next(ptr_seek))
	{
		__synapse_modules_probe_modules*
			ptr_module
				= *(__synapse_modules_probe_modules**)
						synapse_double_linked_node_data
							(ptr_seek);
		
		__synapse_modules_probe_unload_module
			(pProbe, ptr_module);
	}

	synapse_cleanup_double_linked
		(pProbe->prb_handle);
	synapse_system_deallocate
		(pProbe);
}