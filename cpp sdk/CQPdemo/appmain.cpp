/*
* CoolQ Demo for VC++ 
* Api Version 9
* Written by Coxxs & Thanks for the help of orzFly
*/

#include "stdafx.h"
#include "appmain.h"
#include "pyMethodDef.h"

using namespace std;


#define CQAPPID "com.cqp.plugins.py375" 
#define CQAPPINFO CQAPIVERTEXT "," CQAPPID



int ac = -1; //AuthCode ���ÿ�Q�ķ���ʱ��Ҫ�õ�
bool enabled = false;
PyObject* pluginModule = NULL;
PyObject* cqpPluginModule = NULL;
PyObject* reloadModuleFn = NULL;

/*
const char* CQAPPID = NULL;   //�Զ������ļ�����ȡ(����ģʽ�Զ���ȡ��ʱ�ļ���)������� http://d.cqp.me/Pro/����/������Ϣ
const char* CQAPPINFO = NULL;
*/



string GetCurrentAppDirectory() {
	CHAR temp[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, temp);
	return temp;
}

/*
void generatePluginAppid(HMODULE dllModule) {
	
	CHAR dllPathBuf[MAX_PATH] = { 0 };
	GetModuleFileNameA(dllModule, dllPathBuf, MAX_PATH);

	// ���ɰ���
	string dllPath(dllPathBuf);
	size_t endPos = dllPath.rfind(".");
	size_t startPos = dllPath.rfind("\\", endPos -1);
	CQAPPID = (const char*)malloc(endPos - startPos + 1);
	memset((void*)CQAPPID, 0, endPos - startPos + 1);
	memcpy((void*)CQAPPID, dllPath.c_str() + startPos + 1, endPos - startPos-1);

	// ����appid
	const char* src = CQAPIVERTEXT ",";
	CQAPPINFO = (const char*)malloc(strlen(CQAPPID) + strlen(src) + 1);
	memset((void*)CQAPPINFO, 0, strlen(CQAPPID) + strlen(src) + 1);
	memcpy((void*)CQAPPINFO, src, strlen(src));
	memcpy((void*)(CQAPPINFO + strlen(src)), CQAPPID, strlen(CQAPPID));
}
*/



void initPython() {
	std::unique_lock<std::mutex> initLock(initMutex);

	if (isInitPlugin || Py_IsInitialized())
	{
		return;
	}
	
	
	// ��ʼ��
	Py_Initialize();

	if (!Py_IsInitialized()) {
		MessageBox(NULL, L"Python��ʼ��ʧ��", NULL, MB_OK);
		exit(0);
	}
	PyEval_InitThreads();

	_PY_GIL_START(true);

	Py_ssize_t tempSize;
	const char* err = "ignore";

	// ���û���
	// ������·��
	string appDir = GetCurrentAppDirectory();


	CHAR pluginsDirBuf[MAX_PATH] = { 0 };

	sprintf_s(pluginsDirBuf, "%s%s", appDir.c_str(), string("\\app\\").append(CQAPPID).c_str());
	string pluginDir = pluginsDirBuf;

	CHAR pyHomeDirBuf[MAX_PATH] = { 0 };
	sprintf_s(pyHomeDirBuf, "%s%s", pluginDir.c_str(), "\\python");

	_PY_GIL_DECREF(temp_$1, PyBytes_FromString(pyHomeDirBuf));
	_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
	wchar_t* pyHome = PyUnicode_AsWideCharString(temp_$2, &tempSize);

	Py_SetPythonHome(pyHome);
	

	// ���û���
	CHAR pathBuf[4096] = { 0 };

	sprintf_s(pathBuf, "%s%s%s%s%s%s%s%s%s%s",
		pluginDir.c_str(), ";",
		pluginDir.c_str(), "\\python\\DLLs;",
		pluginDir.c_str(), "\\python\\Lib;",
		pluginDir.c_str(), "\\python\\Lib\\site-packages;",
		pluginDir.c_str(), "\\python\\Lib\\Tools;");

	
	_PY_GIL_DECREF(temp_$3, PyBytes_FromString(pathBuf));
	_PY_GIL_DECREF(temp_$4, PyCodec_Decode(temp_$3, "gbk", err));

	wchar_t* pyPath = PyUnicode_AsWideCharString(temp_$4, &tempSize);
	PySys_SetPath(pyPath);

	// ���ó�����
	_PY_GIL_DECREF(temp_$5, PyBytes_FromString("__main__"));
	_PY_GIL_DECREF(temp_$6, PyCodec_Decode(temp_$5, "gbk", err));

	wchar_t* pyProgramName = PyUnicode_AsWideCharString(temp_$6, &tempSize);
	Py_SetProgramName(pyProgramName);

	_PY_GIL_DECREF(osModule, PyImport_ImportModule("os"));
	_PY_GIL_DECREF(chdirFn, PyObject_GetAttrString(osModule, "chdir"));

	if (PyCallable_Check(chdirFn) > 0)
	{
		_PY_GIL_DECREF(temp_$1, PyBytes_FromString(pluginDir.c_str()));
		_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
		auto pluginWorkDir = PyUnicode_AsUTF8(temp_$2);
		PyObject_CallFunction(chdirFn, "s", pluginWorkDir);
	}

	// ��ȡ����ģ�麯��
	_PY_GIL_DECREF(importlibModule, PyImport_ImportModule("importlib"));
	reloadModuleFn = PyObject_GetAttrString(importlibModule, "reload");

	if (PyCallable_Check(reloadModuleFn) <= 0)
	{
		_PY_GIL_STOP();
		MessageBox(NULL, L"�Ҳ���importlibģ��,����ģ���޷�����", NULL, MB_OK);
		exit(0);
	}

	// �����������
	pluginModule = PyImport_AddModule("CQP");

	// cqp.ac = -1
	PyObject_SetAttrString(pluginModule, "AC", PyLong_FromLong(ac));
	// cqp.enable = false
	PyObject_SetAttrString(pluginModule, "enable", Py_False);
	// cqp.EVENT_IGNORE = 0
	PyObject_SetAttrString(pluginModule, "EVENT_IGNORE", PyLong_FromLong(0));
	// cqp.EVENT_BLOCK = 1
	PyObject_SetAttrString(pluginModule, "EVENT_BLOCK", PyLong_FromLong(1));
	// cqp.REQUEST_ALLOW = 1
	PyObject_SetAttrString(pluginModule, "REQUEST_ALLOW", PyLong_FromLong(1));
	// cqp.REQUEST_DENY = 2
	PyObject_SetAttrString(pluginModule, "REQUEST_DENY", PyLong_FromLong(2));
	// cqp.REQUEST_GROUPADD = 1
	PyObject_SetAttrString(pluginModule, "REQUEST_GROUPADD", PyLong_FromLong(1));
	// cqp.REQUEST_GROUPINVITE = 2
	PyObject_SetAttrString(pluginModule, "REQUEST_GROUPINVITE", PyLong_FromLong(2));
	// cqp.CQLOG_DEBUG = 0
	PyObject_SetAttrString(pluginModule, "CQLOG_DEBUG", PyLong_FromLong(0));
	// cqp.CQLOG_INFO = 10
	PyObject_SetAttrString(pluginModule, "CQLOG_INFO", PyLong_FromLong(10));
	// cqp.CQLOG_INFOSUCCESS = 11
	PyObject_SetAttrString(pluginModule, "CQLOG_INFOSUCCESS", PyLong_FromLong(11));
	// cqp.CQLOG_INFORECV = 12
	PyObject_SetAttrString(pluginModule, "CQLOG_INFORECV", PyLong_FromLong(12));
	// cqp.CQLOG_INFOSEND = 12
	PyObject_SetAttrString(pluginModule, "CQLOG_INFOSEND", PyLong_FromLong(13));
	// cqp.CQLOG_WARNING = 20
	PyObject_SetAttrString(pluginModule, "CQLOG_WARNING", PyLong_FromLong(20));
	// cqp.CQLOG_ERROR = 30
	PyObject_SetAttrString(pluginModule, "CQLOG_ERROR", PyLong_FromLong(30));
	// cqp.CQLOG_FATAL = 40
	PyObject_SetAttrString(pluginModule, "CQLOG_FATAL", PyLong_FromLong(40));

	
	static PyMethodDef pluginMethods[] = {
		{ "sendPrivateMsg", (PyCFunction)pyfn_CQ_sendPrivateMsg, METH_VARARGS, NULL },
		{ "sendGroupMsg", (PyCFunction)pyfn_CQ_sendGroupMsg, METH_VARARGS, NULL },
		{ "sendDiscussMsg", (PyCFunction)pyfn_CQ_sendDiscussMsg, METH_VARARGS, NULL },
		{ "deleteMsg", (PyCFunction)pyfn_CQ_deleteMsg, METH_VARARGS, NULL },
		{ "sendLike", (PyCFunction)pyfn_CQ_sendLike, METH_VARARGS, NULL },
		{ "setGroupKick", (PyCFunction)pyfn_CQ_setGroupKick, METH_VARARGS, NULL },
		{ "setGroupBan", (PyCFunction)pyfn_CQ_setGroupBan, METH_VARARGS, NULL },
		{ "setGroupAdmin", (PyCFunction)pyfn_CQ_setGroupAdmin, METH_VARARGS, NULL },
		{ "setGroupWholeBan", (PyCFunction)pyfn_CQ_setGroupWholeBan, METH_VARARGS, NULL },
		{ "setGroupAnonymousBan", (PyCFunction)pyfn_CQ_setGroupAnonymousBan, METH_VARARGS, NULL },
		{ "setGroupAnonymous", (PyCFunction)pyfn_CQ_setGroupAnonymous, METH_VARARGS, NULL },
		{ "setGroupCard", (PyCFunction)pyfn_CQ_setGroupCard, METH_VARARGS, NULL },
		{ "setGroupLeave", (PyCFunction)pyfn_CQ_setGroupLeave, METH_VARARGS, NULL },
		{ "setGroupSpecialTitle", (PyCFunction)pyfn_CQ_setGroupSpecialTitle, METH_VARARGS, NULL },
		{ "setDiscussLeave", (PyCFunction)pyfn_CQ_setDiscussLeave, METH_VARARGS, NULL },
		{ "setFriendAddRequest", (PyCFunction)pyfn_CQ_setFriendAddRequest, METH_VARARGS, NULL },
		{ "setGroupAddRequestV2", (PyCFunction)pyfn_CQ_setGroupAddRequestV2, METH_VARARGS, NULL },
		{ "getGroupMemberInfoV2", (PyCFunction)pyfn_CQ_getGroupMemberInfoV2, METH_VARARGS, NULL },
		{ "getStrangerInfo", (PyCFunction)pyfn_CQ_getStrangerInfo, METH_VARARGS, NULL },
		{ "addLog", (PyCFunction)pyfn_CQ_addLog, METH_VARARGS, NULL },
		{ "getCsrfToken", (PyCFunction)pyfn_CQ_getCsrfToken, METH_VARARGS, NULL },
		{ "getLoginQQ", (PyCFunction)pyfn_CQ_getLoginQQ, METH_VARARGS, NULL },
		{ "getLoginNick", (PyCFunction)pyfn_CQ_getLoginNick, METH_VARARGS, NULL },
		{ "getAppDirectory", (PyCFunction)pyfn_CQ_getAppDirectory, METH_VARARGS, NULL },
		{ "setFatal", (PyCFunction)pyfn_CQ_setFatal, METH_VARARGS, NULL },
		{ "getRecord", (PyCFunction)pyfn_CQ_getRecord, METH_VARARGS, NULL },
	};
	PyModule_AddFunctions(pluginModule, pluginMethods);
	// ����main
	cqpPluginModule = PyImport_ImportModule("cqpplugin");

	isInitPlugin = true;

	_PY_GIL_DECREF(exceptInfo, PyErr_Occurred());

	if (exceptInfo > 0)
	{
		isInitPlugin = false;
		MessageBox(NULL, L"����python���ʧ��(�����쳣)", NULL, MB_OK);
	}
	// �ͷ�GIL
	_PY_GIL_STOP();

}


void finalizePython() {
	std::unique_lock<std::mutex> initLock(initMutex);

	// bug������ж��
	Py_Finalize();
	isInitPlugin = false;
}


/* 
* ����Ӧ�õ�ApiVer��Appid������󽫲������
*/

CQEVENT(const char*, AppInfo, 0)() {
	initPython();
	return CQAPPINFO;
}


/* 
* ����Ӧ��AuthCode����Q��ȡӦ����Ϣ��������ܸ�Ӧ�ã���������������������AuthCode��
* ��Ҫ�ڱ��������������κδ��룬���ⷢ���쳣���������ִ�г�ʼ����������Startup�¼���ִ�У�Type=1001����
*/
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);

	ac = AuthCode;

	_PY_GIL_DECREF(acValue, PyLong_FromLong(ac));
	PyObject_SetAttrString(pluginModule, "AC", acValue);
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "Initialize"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "i", ac));
	}
	_PY_GIL_STOP();
	return 0;
}


/*
* Type=1001 ��Q����
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q������ִ��һ�Σ���������ִ��Ӧ�ó�ʼ�����롣
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventStartup, 0)() {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventStartup"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, NULL, NULL));
	}

	_PY_GIL_STOP();
	return 0;
}

/*
* Type=1002 ��Q�˳�
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q�˳�ǰִ��һ�Σ���������ִ�в���رմ��롣
* ������������Ϻ󣬿�Q���ܿ�رգ��벻Ҫ��ͨ���̵߳ȷ�ʽִ���������롣
*/
CQEVENT(int32_t, __eventExit, 0)() {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventExit"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, NULL, NULL));
	}

	_PY_GIL_STOP();
	return 0;
}

/*
* Type=1003 Ӧ���ѱ�����
* ��Ӧ�ñ����ú󣬽��յ����¼���
* �����Q����ʱӦ���ѱ����ã�����_eventStartup(Type=1001,��Q����)�����ú󣬱�����Ҳ��������һ�Ρ�
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventEnable, 0)() {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	enabled = true;

	// ����ģ��
	_PY_GIL_DECREF(_args, PyTuple_New(1));
	PyTuple_SetItem(_args, 0, cqpPluginModule);
	cqpPluginModule = PyObject_CallObject(reloadModuleFn, _args);

	PyObject_SetAttrString(pluginModule, "enable", Py_True);
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventEnable"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, NULL, NULL));
					
	}
	_PY_GIL_STOP();
	return 0;
}


/*
* Type=1004 Ӧ�ý���ͣ��
* ��Ӧ�ñ�ͣ��ǰ�����յ����¼���
* �����Q����ʱӦ���ѱ�ͣ�ã��򱾺���*����*�����á�
* ���۱�Ӧ���Ƿ����ã���Q�ر�ǰ��������*����*�����á�
*/
CQEVENT(int32_t, __eventDisable, 0)() {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	
	enabled = false;
	PyObject_SetAttrString(pluginModule, "enable", Py_False);
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventDisable"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, NULL, NULL));
	}
	_PY_GIL_STOP();
	return 0;
}


/*
* Type=21 ˽����Ϣ
* subType �����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
*/
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t msgId, int64_t fromQQ, const char *msg, int32_t font) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventPrivateMsg"));
	if (PyCallable_Check(_fn) > 0)
	{
		const char* err = "ignore";

		_PY_GIL_DECREF(temp_$1, PyBytes_FromString(msg));
		_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
		auto _msg = PyUnicode_AsUTF8(temp_$2);

		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLsi", subType, msgId, fromQQ, _msg, font));
		
		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result;
}


/*
* Type=2 Ⱥ��Ϣ
*/
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventGroupMsg"));
	if (PyCallable_Check(_fn) > 0)
	{
		const char* err = "ignore";
		_PY_GIL_DECREF(temp_$1, PyBytes_FromString(fromAnonymous));
		_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
		auto _fromAnonymous = PyUnicode_AsUTF8(temp_$2);

		_PY_GIL_DECREF(temp_$3, PyBytes_FromString(msg));
		_PY_GIL_DECREF(temp_$4, PyCodec_Decode(temp_$3, "gbk", err));
		auto _msg = PyUnicode_AsUTF8(temp_$4);
					
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLLssi", subType, msgId, fromGroup, fromQQ, _fromAnonymous, _msg, font));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=4 ��������Ϣ
*/
CQEVENT(int32_t, __eventDiscussMsg, 32)(int32_t subType, int32_t msgId, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventDiscussMsg"));
	if (PyCallable_Check(_fn) > 0)
	{
		const char* err = "ignore";
		_PY_GIL_DECREF(temp_$3, PyBytes_FromString(msg));
		_PY_GIL_DECREF(temp_$4, PyCodec_Decode(temp_$3, "gbk", err));
		auto _msg = PyUnicode_AsUTF8(temp_$4);

		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLLsi", subType, msgId, fromDiscuss, fromQQ, _msg, font));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=101 Ⱥ�¼�-����Ա�䶯
* subType �����ͣ�1/��ȡ������Ա 2/�����ù���Ա
*/
CQEVENT(int32_t, __eventSystem_GroupAdmin, 24)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventSystem_GroupAdmin"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLL", subType, sendTime, fromGroup, beingOperateQQ));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=102 Ⱥ�¼�-Ⱥ��Ա����
* subType �����ͣ�1/ȺԱ�뿪 2/ȺԱ���� 3/�Լ�(����¼��)����
* fromQQ ������QQ(��subTypeΪ2��3ʱ����)
* beingOperateQQ ������QQ
*/
CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventSystem_GroupMemberDecrease"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLLL", subType, sendTime, fromGroup, fromQQ, beingOperateQQ));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=103 Ⱥ�¼�-Ⱥ��Ա����
* subType �����ͣ�1/����Ա��ͬ�� 2/����Ա����
* fromQQ ������QQ(������ԱQQ)
* beingOperateQQ ������QQ(����Ⱥ��QQ)
*/
CQEVENT(int32_t, __eventSystem_GroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventSystem_GroupMemberIncrease"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLLL", subType, sendTime, fromGroup, fromQQ, beingOperateQQ));
	
		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=201 �����¼�-���������
*/
CQEVENT(int32_t, __eventFriend_Add, 16)(int32_t subType, int32_t sendTime, int64_t fromQQ) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventFriend_Add"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiL", subType, sendTime, fromQQ));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=301 ����-�������
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventRequest_AddFriend"));
	if (PyCallable_Check(_fn) > 0)
	{
		const char* err = "ignore";
		_PY_GIL_DECREF(temp_$1, PyBytes_FromString(responseFlag));
		_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
		auto _responseFlag = PyUnicode_AsUTF8(temp_$2);

		_PY_GIL_DECREF(temp_$3, PyBytes_FromString(msg));
		_PY_GIL_DECREF(temp_$4, PyCodec_Decode(temp_$3, "gbk", err));
		auto _msg = PyUnicode_AsUTF8(temp_$4);

		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLss", subType, sendTime, fromQQ, _msg, _responseFlag));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=302 ����-Ⱥ���
* subType �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddGroup, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventRequest_AddGroup"));

	if (PyCallable_Check(_fn) > 0)
	{
		const char* err = "ignore";
		_PY_GIL_DECREF(temp_$1, PyBytes_FromString(responseFlag));
		_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
		auto _responseFlag = PyUnicode_AsUTF8(temp_$2);

		_PY_GIL_DECREF(temp_$3, PyBytes_FromString(msg));
		_PY_GIL_DECREF(temp_$4, PyCodec_Decode(temp_$3, "gbk", err));
		auto _msg = PyUnicode_AsUTF8(temp_$4);

		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLLss", subType, sendTime, fromGroup, fromQQ, _msg, _responseFlag));
		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=11 Ⱥ�ļ��ϴ��¼�
* file �ϴ��ļ���Ϣ
*/
CQEVENT(int32_t, __eventGroupUpload, 28)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char* file) {

	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "eventGroupUpload"));
	
	if (PyCallable_Check(_fn) > 0)
	{
		const char* err = "ignore";
		_PY_GIL_DECREF(temp_$1, PyBytes_FromString(file));
		_PY_GIL_DECREF(temp_$2, PyCodec_Decode(temp_$1, "gbk", err));
		auto _file = PyUnicode_AsUTF8(temp_$2);
	
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "iiLLs", subType, sendTime, fromGroup, fromQQ, _file));

		result = PyLong_AsLong(_result);
	}
	_PY_GIL_STOP();
	return result; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}



/*
* �˵������� .json �ļ������ò˵���Ŀ��������
* �����ʹ�ò˵������� .json ���˴�ɾ�����ò˵�
*/

int32_t menuClick(int index) {
	_PY_SDK_NOT_INIT(return 0;); _PY_GIL_START(true);
	int32_t result = EVENT_IGNORE;
	_PY_GIL_DECREF(_fn, PyObject_GetAttrString(cqpPluginModule, "menuClick"));
	if (PyCallable_Check(_fn) > 0)
	{
		_PY_GIL_DECREF(_result, PyObject_CallFunction(_fn, "i", index));
	}
	_PY_GIL_STOP();
	return result;
}

CQEVENT(int32_t, __menu1, 0)() {
	menuClick(1);
	return 0;
}

CQEVENT(int32_t, __menu2, 0)() {
	menuClick(2);
	return 0;
}
CQEVENT(int32_t, __menu3, 0)() {
	menuClick(3);
	return 0;
}

CQEVENT(int32_t, __menu4, 0)() {
	menuClick(4);
	return 0;
}
CQEVENT(int32_t, __menu5, 0)() {
	menuClick(5);
	return 0;
}

CQEVENT(int32_t, __menu6, 0)() {
	menuClick(6);
	return 0;
}
CQEVENT(int32_t, __menu7, 0)() {
	menuClick(7);
	return 0;
}

CQEVENT(int32_t, __menu8, 0)() {
	menuClick(8);
	return 0;
}
CQEVENT(int32_t, __menu9, 0)() {
	menuClick(9);
	return 0;
}

CQEVENT(int32_t, __menu10, 0)() {
	menuClick(10);
	return 0;
}