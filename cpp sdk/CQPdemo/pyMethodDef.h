#ifndef CQPPLUGIN_PY_METHOD
#define CQPPLUGIN_PY_METHOD

#include "stdafx.h"

PyObject* pyfn_CQ_sendPrivateMsg(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_sendGroupMsg(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_sendDiscussMsg(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_deleteMsg(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_sendLike(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupKick(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupBan(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupAdmin(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupWholeBan(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupAnonymousBan(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupAnonymous(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupCard(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupLeave(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupSpecialTitle(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setDiscussLeave(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setFriendAddRequest(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setGroupAddRequestV2(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getGroupMemberInfoV2(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getStrangerInfo(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_addLog(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getCookies(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getCsrfToken(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getLoginQQ(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getLoginNick(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getAppDirectory(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_setFatal(PyObject* self, PyObject* args);
PyObject* pyfn_CQ_getRecord(PyObject* self, PyObject* args);


#endif // !1