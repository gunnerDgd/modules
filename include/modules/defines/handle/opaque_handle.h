#pragma once
#include <stdint.h>
#include <stdarg.h>

#define synapse_modules_opaque_handle_declare(pName)\
	typedef struct pName\
	{\
		void* opaque;\
	} pName;

#define synapse_modules_opaque_handle_reference(pObject)\
	(pObject.opaque)

#define synapse_modules_opaque_handle_init(pObject, pName, pValue)\
	pObject pName = { .opaque = pValue }

#define synapse_modules_opaque_handle_cast(pObject, pType)\
	((pType)(pObject.opaque))