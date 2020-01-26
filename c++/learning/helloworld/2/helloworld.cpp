#include <Python.h>

int Cfib(int n){
	if (n<2)
		return n;
	else
		return Cfib(n-1)+Cfib(n-2);
}

// returns a python object
static PyObject* fib(PyObject* self, PyObject* args){
	int n; //store incoming n value from python
	// if not for !
	if (!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	return Py_BuildBalue("i", Cfib(n))
}