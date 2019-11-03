
#include "stdafx.h"
#include "pyMethodDef.h"


// CQAPI(int32_t) CQ_sendPrivateMsg(int32_t AuthCode, int64_t QQID, const char *msg);
PyObject* pyfn_CQ_sendPrivateMsg(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);

	PyObject* result = Py_None;

	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t QQID = PyLong_AsLongLong(temp_$2);
			
			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$4, PyCodec_Encode(temp_$3, "gbk", err));

			const char* msg = PyBytes_AsString(temp_$4);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_sendPrivateMsg(AuthCode, QQID, msg);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_sendGroupMsg(int32_t AuthCode, int64_t groupid, const char *msg);
PyObject* pyfn_CQ_sendGroupMsg(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;);
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;

	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$4, PyCodec_Encode(temp_$3, "gbk", err));

			const char* msg = PyBytes_AsString(temp_$4);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_sendGroupMsg(AuthCode, groupid, msg);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_sendDiscussMsg(int32_t AuthCode, int64_t discussid, const char *msg);
PyObject* pyfn_CQ_sendDiscussMsg(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;

	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t discussid = PyLong_AsLongLong(temp_$2);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$4, PyCodec_Encode(temp_$3, "gbk", err));

			const char* msg = PyBytes_AsString(temp_$4);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_sendDiscussMsg(AuthCode, discussid, msg);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_deleteMsg(int32_t AuthCode, int64_t msgid);
PyObject* pyfn_CQ_deleteMsg(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;

	try
	{
		if (PyTuple_Size(args) == 2)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t msgid = PyLong_AsLongLong(temp_$2);


			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_deleteMsg(AuthCode, msgid);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_sendLike(int32_t AuthCode, int64_t QQID);
PyObject* pyfn_CQ_sendLike(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;

	try
	{
		if (PyTuple_Size(args) == 2)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t QQID = PyLong_AsLongLong(temp_$2);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_sendLike(AuthCode, QQID);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupKick(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);
PyObject* pyfn_CQ_setGroupKick(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;);
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			int64_t QQID = PyLong_AsLongLong(temp_$3);
			CQBOOL rejectaddrequest = PyLong_AsLong(temp_$4);
			

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupKick(AuthCode, groupid, QQID, rejectaddrequest);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupBan(int32_t AuthCode, int64_t groupid, int64_t QQID, int64_t duration);
PyObject* pyfn_CQ_setGroupBan(PyObject* self, PyObject* args){
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			int64_t QQID = PyLong_AsLongLong(temp_$3);
			int64_t duration = PyLong_AsLongLong(temp_$4);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupBan(AuthCode, groupid, QQID, duration);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupAdmin(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL setadmin);
PyObject* pyfn_CQ_setGroupAdmin(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			int64_t QQID = PyLong_AsLongLong(temp_$3);
			CQBOOL setadmin = PyLong_AsLong(temp_$4);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupAdmin(AuthCode, groupid, QQID, setadmin);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupWholeBan(int32_t AuthCode, int64_t groupid, CQBOOL enableban);
PyObject* pyfn_CQ_setGroupWholeBan(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			CQBOOL enableban = PyLong_AsLong(temp_$3);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupWholeBan(AuthCode, groupid, enableban);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupAnonymousBan(int32_t AuthCode, int64_t groupid, const char *anomymous, int64_t duration);
PyObject* pyfn_CQ_setGroupAnonymousBan(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;);
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$5, PyCodec_Encode(temp_$3, "gbk", err));
			const char *anomymous = PyBytes_AsString(temp_$5);

			int64_t duration = PyLong_AsLongLong(temp_$4);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupAnonymousBan(AuthCode, groupid, anomymous, duration);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupAnonymous(int32_t AuthCode, int64_t groupid, CQBOOL enableanomymous);
PyObject* pyfn_CQ_setGroupAnonymous(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			CQBOOL enableanomymous = PyLong_AsLong(temp_$3);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupAnonymous(AuthCode, groupid, enableanomymous);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupCard(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newcard);
PyObject* pyfn_CQ_setGroupCard(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			int64_t QQID = PyLong_AsLongLong(temp_$3);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$5, PyCodec_Encode(temp_$4, "gbk", err));
			const char* newcard = PyBytes_AsString(temp_$5);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupCard(AuthCode, groupid, QQID, newcard);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupLeave(int32_t AuthCode, int64_t groupid, CQBOOL isdismiss);
PyObject* pyfn_CQ_setGroupLeave(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;);
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			CQBOOL isdismiss = PyLong_AsLong(temp_$3);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupLeave(AuthCode, groupid, isdismiss);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupSpecialTitle(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newspecialtitle, int64_t duration);
PyObject* pyfn_CQ_setGroupSpecialTitle(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 5)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));
			_PY_ENV_VAR_NO_DECREF(temp_$5, PyTuple_GetItem(args, 4));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			int64_t QQID = PyLong_AsLongLong(temp_$3);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$6, PyCodec_Encode(temp_$4, "gbk", err));
			const char* newspecialtitle = PyBytes_AsString(temp_$6);

			int64_t duration = PyLong_AsLongLong(temp_$5);
				
			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupSpecialTitle(AuthCode, groupid, QQID, newspecialtitle, duration);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setDiscussLeave(int32_t AuthCode, int64_t discussid);
PyObject* pyfn_CQ_setDiscussLeave(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 2)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
	
			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t discussid = PyLong_AsLongLong(temp_$2);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setDiscussLeave(AuthCode, discussid);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setFriendAddRequest(int32_t AuthCode, const char *responseflag, int32_t responseoperation, const char *remark);
PyObject* pyfn_CQ_setFriendAddRequest(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$5, PyCodec_Encode(temp_$2, "gbk", err));
			const char* responseflag = PyBytes_AsString(temp_$5);

			int32_t responseoperation = PyLong_AsLong(temp_$3);

			_PY_GIL_DECREF(temp_$6, PyCodec_Encode(temp_$4, "gbk", err));
			const char* remark = PyBytes_AsString(temp_$6);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setFriendAddRequest(AuthCode, responseflag, responseoperation, remark);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setGroupAddRequestV2(int32_t AuthCode, const char *responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);
PyObject* pyfn_CQ_setGroupAddRequestV2(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 5)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));
			_PY_ENV_VAR_NO_DECREF(temp_$5, PyTuple_GetItem(args, 4));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$6, PyCodec_Encode(temp_$2, "gbk", err));
			const char* responseflag = PyBytes_AsString(temp_$6);

			int32_t requesttype = PyLong_AsLong(temp_$3);
			int32_t responseoperation = PyLong_AsLong(temp_$4);

			_PY_GIL_DECREF(temp_$7, PyCodec_Encode(temp_$5, "gbk", err));
			const char* reason = PyBytes_AsString(temp_$7);


			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setGroupAddRequestV2(AuthCode, responseflag, requesttype, responseoperation, reason);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(const char *) CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache);
PyObject* pyfn_CQ_getGroupMemberInfoV2(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t groupid = PyLong_AsLongLong(temp_$2);
			int64_t QQID = PyLong_AsLongLong(temp_$3);
			CQBOOL nocache = PyLong_AsLong(temp_$4);


			const char* _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getGroupMemberInfoV2(AuthCode, groupid, QQID, nocache);
			Py_END_ALLOW_THREADS

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$5, PyBytes_FromString(_result));
			_PY_GIL_DECREF(temp_$6, PyCodec_Decode(temp_$5, "gbk", err));
			result = temp_$6;
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(const char *) CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQBOOL nocache);
PyObject* pyfn_CQ_getStrangerInfo(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));


			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int64_t QQID = PyLong_AsLongLong(temp_$2);
			CQBOOL nocache = PyLong_AsLong(temp_$3);


			const char* _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getStrangerInfo(AuthCode, QQID, nocache);
			Py_END_ALLOW_THREADS

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$4, PyBytes_FromString(_result));
			_PY_GIL_DECREF(temp_$5, PyCodec_Decode(temp_$4, "gbk", err));
			result = temp_$5;
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_addLog(int32_t AuthCode, int32_t priority, const char* category, const char* content);
PyObject* pyfn_CQ_addLog(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;);
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 4)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));
			_PY_ENV_VAR_NO_DECREF(temp_$4, PyTuple_GetItem(args, 3));

			int32_t AuthCode = PyLong_AsLong(temp_$1);
			int32_t priority = PyLong_AsLong(temp_$2);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$5, PyCodec_Encode(temp_$3, "gbk", err));
			const char* category = PyBytes_AsString(temp_$5);

			_PY_GIL_DECREF(temp_$6, PyCodec_Encode(temp_$4, "gbk", err));
			const char* content = PyBytes_AsString(temp_$6);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_addLog(AuthCode, priority, category, content);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(const char *) CQ_getCookies(int32_t AuthCode);
PyObject* pyfn_CQ_getCookies(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 1)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* _result = NULL;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getCookies(AuthCode);
			Py_END_ALLOW_THREADS

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$2, PyBytes_FromString(_result));
			_PY_GIL_DECREF(temp_$3, PyCodec_Decode(temp_$2, "gbk", err));
			result = temp_$3;
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_getCsrfToken(int32_t AuthCode);
PyObject* pyfn_CQ_getCsrfToken(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 1)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getCsrfToken(AuthCode);
			Py_END_ALLOW_THREADS
			result = PyLong_FromLong(_result);

		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int64_t) CQ_getLoginQQ(int32_t AuthCode);
PyObject* pyfn_CQ_getLoginQQ(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 1)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			int64_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getLoginQQ(AuthCode);
			Py_END_ALLOW_THREADS

			result = PyLong_FromLongLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(const char *) CQ_getLoginNick(int32_t AuthCode);
PyObject* pyfn_CQ_getLoginNick(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 1)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getLoginNick(AuthCode);
			Py_END_ALLOW_THREADS

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$2, PyBytes_FromString(_result));
			_PY_GIL_DECREF(temp_$3, PyCodec_Decode(temp_$2, "gbk", err));
			result = temp_$3;
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(const char *) CQ_getAppDirectory(int32_t AuthCode);
PyObject* pyfn_CQ_getAppDirectory(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;

	try
	{
		if (PyTuple_Size(args) == 1)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getAppDirectory(AuthCode);
			Py_END_ALLOW_THREADS

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$2, PyBytes_FromString(_result));
			_PY_GIL_DECREF(temp_$3, PyCodec_Decode(temp_$2, "gbk", err));
			result = temp_$3;
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(int32_t) CQ_setFatal(int32_t AuthCode, const char *errorinfo);
PyObject* pyfn_CQ_setFatal(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 2)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$3, PyCodec_Encode(temp_$2, "gbk", err));
			const char* errorinfo = PyBytes_AsString(temp_$3);


			int32_t _result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_setFatal(AuthCode, errorinfo);
			Py_END_ALLOW_THREADS

			result = PyLong_FromLong(_result);
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}
// CQAPI(const char*) CQ_getRecord(int32_t AuthCode, const char* file, const char* outformat);
PyObject* pyfn_CQ_getRecord(PyObject* self, PyObject* args) {
	_PY_SDK_NOT_INIT(return NULL;); 
	
	_PY_GIL_START(false);
	PyObject* result = Py_None;
	
	try
	{
		if (PyTuple_Size(args) == 3)
		{
			_PY_ENV_VAR_NO_DECREF(temp_$1, PyTuple_GetItem(args, 0));
			_PY_ENV_VAR_NO_DECREF(temp_$2, PyTuple_GetItem(args, 1));
			_PY_ENV_VAR_NO_DECREF(temp_$3, PyTuple_GetItem(args, 2));

			int32_t AuthCode = PyLong_AsLong(temp_$1);

			const char* err = "ignore";
			_PY_GIL_DECREF(temp_$4, PyCodec_Encode(temp_$2, "gbk", err));
			const char* file = PyBytes_AsString(temp_$4);
			_PY_GIL_DECREF(temp_$5, PyCodec_Encode(temp_$3, "gbk", err));
			const char* outformat = PyBytes_AsString(temp_$5);

			const char *_result;
			Py_BEGIN_ALLOW_THREADS
				_result = CQ_getRecord(AuthCode, file, outformat);
			Py_END_ALLOW_THREADS

			_PY_GIL_DECREF(temp_$6, PyBytes_FromString(_result));
			_PY_GIL_DECREF(temp_$7, PyCodec_Decode(temp_$6, "gbk", err));
			result = temp_$7;
		}
	}
	catch (const std::exception&)
	{

	}
	_PY_GIL_STOP();
	return result;
}

