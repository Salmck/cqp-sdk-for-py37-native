// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include "stdint.h"
#include "string"

#include "appmain.h"
#include "cqp.h"

#include <Python.h>
#include <Windows.h>
#include <vector>
#include <mutex>



extern std::mutex initMutex;
extern bool isInitPlugin;


class PyEnv
{
public:
	PyEnv() {

	};
	~PyEnv() {
		// ½â³ýÒýÓÃ
		for (size_t i = 0; i < pyRefVarArray.size(); i++) {
			Py_XDECREF(pyRefVarArray.at(i));
		};
		pyRefVarArray.clear();
	};

	PyObject* AddDecRef(PyObject* item) {
		if (item > 0)
		{
			pyRefVarArray.push_back(item);
		}
		return item;
	}

private:
	std::vector<PyObject*> pyRefVarArray;
	PyGILState_STATE gil;
	PyThreadState* oldThreadState = NULL;
	bool _acquireGIL = false;

};


#define _PY_GIL_START(_requireGIL) bool requireGIL = _requireGIL; PyGILState_STATE gil;  if(requireGIL) {  gil = PyGILState_Ensure(); } PyEnv *_py_env = new PyEnv();
#define _PY_GIL_STOP()  delete _py_env; if(requireGIL) {   PyGILState_Release(gil); if(PyGILState_Check() > 0) { PyEval_SaveThread(); }}

#define _PY_GIL_DECREF(var, exp) PyObject* var = _py_env->AddDecRef(exp); 

#define _PY_ENV_VAR_NO_DECREF(var, exp) auto var = exp;

#define _PY_SDK_NOT_INIT(exp) std::unique_lock<std::mutex> initLock(initMutex); auto init = isInitPlugin; initLock.unlock(); if(init == false) {exp};


