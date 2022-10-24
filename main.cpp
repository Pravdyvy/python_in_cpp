#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include <iostream>

int main(int argc, char* argv[]){
    const char* scriptdirname = "/home/oleksandrpravdyvyi/PythonEmbedding";
    Py_Initialize();

    PyObject *name, *load_module, *func, *callfunc, *args;
    PyObject *syspath = PySys_GetObject("path");
    PyObject *path = PyUnicode_FromString(scriptdirname);
    int result = PyList_Insert(syspath,0,path);
    load_module = PyImport_ImportModule("script");
    if (PyErr_Occurred()) PyErr_Print();
    printf("%p\n",load_module);
    func = PyObject_GetAttrString(load_module,(char*)"fun1");
    callfunc = PyObject_CallObject(func,NULL);
    double fun1_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module,(char*)"fun2");
    args = PyTuple_Pack(1, PyFloat_FromDouble(3.0));
    callfunc = PyObject_CallObject(func,args);
    double fun2_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module,(char*)"fun3");
    args = PyTuple_Pack(2, PyFloat_FromDouble(3.0), PyFloat_FromDouble(5.0));
    callfunc = PyObject_CallObject(func,args);
    double fun3_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module,(char*)"fun4");
    args = PyTuple_Pack(1, PyUnicode_FromString((char*)"gcc"));
    callfunc = PyObject_CallObject(func,args);
    std::string fun4_out = _PyUnicode_AsString(callfunc);

    Py_Finalize();

    std::cout << fun1_out << std::endl;
    std::cout << fun2_out << std::endl;
    std::cout << fun3_out << std::endl;
    std::cout << fun4_out << std::endl;
}