/*
 * Python object definition of the libbde encryption methods
 *
 * Copyright (C) 2011-2024, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pybde_encryption_methods.h"
#include "pybde_libbde.h"
#include "pybde_python.h"
#include "pybde_unused.h"

PyTypeObject pybde_encryption_methods_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pybde.encryption_methods",
	/* tp_basicsize */
	sizeof( pybde_encryption_methods_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pybde_encryption_methods_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pybde encryption methods object (wraps LIBBDE_ENCRYPTION_METHODS)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pybde_encryption_methods_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Initializes the type object
 * Returns 1 if successful or -1 on error
 */
int pybde_encryption_methods_init_type(
     PyTypeObject *type_object )
{
	PyObject *value_object = NULL;

	if( type_object == NULL )
	{
		return( -1 );
	}
	type_object->tp_dict = PyDict_New();

	if( type_object->tp_dict == NULL )
	{
		return( -1 );
	}
#if PY_MAJOR_VERSION >= 3
	value_object = PyLong_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_128_CBC_DIFFUSER );
#else
	value_object = PyInt_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_128_CBC_DIFFUSER );
#endif
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "AES_128_CBC_DIFFUSER",
	     value_object ) != 0 )
	{
		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	value_object = PyLong_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_256_CBC_DIFFUSER );
#else
	value_object = PyInt_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_256_CBC_DIFFUSER );
#endif
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "AES_256_CBC_DIFFUSER",
	     value_object ) != 0 )
	{
		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	value_object = PyLong_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_128_CBC );
#else
	value_object = PyInt_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_128_CBC );
#endif
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "AES_128_CBC",
	     value_object ) != 0 )
	{
		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	value_object = PyLong_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_256_CBC );
#else
	value_object = PyInt_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_256_CBC );
#endif
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "AES_256_CBC",
	     value_object ) != 0 )
	{
		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	value_object = PyLong_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_128_XTS );
#else
	value_object = PyInt_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_128_XTS );
#endif
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "AES_128_XTS",
	     value_object ) != 0 )
	{
		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	value_object = PyLong_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_256_XTS );
#else
	value_object = PyInt_FromLong(
	                LIBBDE_ENCRYPTION_METHOD_AES_256_XTS );
#endif
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "AES_256_XTS",
	     value_object ) != 0 )
	{
		goto on_error;
	}
	return( 1 );

on_error:
	if( type_object->tp_dict != NULL )
	{
		Py_DecRef(
		 type_object->tp_dict );

		type_object->tp_dict = NULL;
	}
	return( -1 );
}

/* Creates a new encryption methods object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pybde_encryption_methods_new(
           void )
{
	pybde_encryption_methods_t *definitions_object = NULL;
	static char *function                          = "pybde_encryption_methods_new";

	definitions_object = PyObject_New(
	                      struct pybde_encryption_methods,
	                      &pybde_encryption_methods_type_object );

	if( definitions_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create definitions object.",
		 function );

		goto on_error;
	}
	if( pybde_encryption_methods_init(
	     definitions_object ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize definitions object.",
		 function );

		goto on_error;
	}
	return( (PyObject *) definitions_object );

on_error:
	if( definitions_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) definitions_object );
	}
	return( NULL );
}

/* Initializes an encryption methods object
 * Returns 0 if successful or -1 on error
 */
int pybde_encryption_methods_init(
     pybde_encryption_methods_t *definitions_object )
{
	static char *function = "pybde_encryption_methods_init";

	if( definitions_object == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid definitions object.",
		 function );

		return( -1 );
	}
	return( 0 );
}

/* Frees an encryption methods object
 */
void pybde_encryption_methods_free(
      pybde_encryption_methods_t *definitions_object )
{
	struct _typeobject *ob_type = NULL;
	static char *function       = "pybde_encryption_methods_free";

	if( definitions_object == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid definitions object.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           definitions_object );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	ob_type->tp_free(
	 (PyObject*) definitions_object );
}

