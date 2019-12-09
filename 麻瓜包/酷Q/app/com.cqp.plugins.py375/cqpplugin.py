
import os
import traceback

import CQP
from core.v9_plus import *


try:
    import plugins
except:
    show_exception()


def dispatch(fn_name, *arg, **kwargs):
    for module_name in dir(plugins):
        module = getattr(plugins, module_name)
        fn = getattr(module, fn_name, False)
        if fn:
            try:
                if fn(*arg, **kwargs) == CQP.EVENT_BLOCK:
                    return CQP.EVENT_BLOCK
            except:
                if CQP.AC != -1:
                    CQP.addLog(CQP.AC, CQP.CQLOG_FATAL, 'CQP PY插件(异常)', str(traceback.format_exc()))
    return CQP.EVENT_IGNORE


if os.environ.get('cqp-plugins', False):
    pass
else:
    os.environ.get('cqp-plugins', True)


    def Initialize(ac):
        dispatch('Initialize', ac)

    def eventStartup():
        dispatch('eventStartup')

    def eventExit():
        dispatch('eventExit')

    def eventEnable():
        dispatch('eventEnable')

    def eventDisable():
        dispatch('eventDisable')

    def eventPrivateMsg(subType: int, msgId: int, fromQQ: int, msg: str, font: int) -> int:
        return dispatch('eventPrivateMsg', subType, msgId, fromQQ, msg, font)

    def eventGroupMsg(subType: int, msgId: int, fromGroup: int, fromQQ: int, fromAnonymous: str, msg: str, font: int) -> int:
        return dispatch('eventGroupMsg', subType, msgId, fromGroup, fromQQ, fromAnonymous, msg, font)

    def eventDiscussMsg(subType: int, msgId: int, fromDiscuss: int, fromQQ: int, msg: str, font: int) -> int:
        return dispatch('eventDiscussMsg', subType, msgId, fromDiscuss, fromQQ, msg, font)

    def eventSystem_GroupAdmin(subType: int, sendTime: int, fromGroup: int, beingOperateQQ: int) -> int:
        return dispatch('eventSystem_GroupAdmin', subType, sendTime, fromGroup, beingOperateQQ)

    def eventSystem_GroupMemberDecrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
        return dispatch('eventSystem_GroupMemberDecrease', subType, sendTime, fromGroup, fromQQ, beingOperateQQ)

    def eventSystem_GroupMemberIncrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
        return dispatch('eventSystem_GroupMemberIncrease', subType, sendTime, fromGroup, fromQQ, beingOperateQQ)

    def eventFriend_Add(subType: int, sendTime: int, fromQQ: int) -> int:
        return dispatch('eventFriend_Add', subType, sendTime, fromQQ)

    def eventRequest_AddFriend(subType: int, sendTime: int, fromQQ: int, msg: int, responseFlag: str) -> int:
        return dispatch('eventRequest_AddFriend', subType, sendTime, fromQQ, msg, responseFlag)

    def eventRequest_AddGroup(subType: int, sendTime: int, fromGroup: int, fromQQ: int, msg: str, responseFlag: str) -> int:
        return dispatch('eventRequest_AddGroup', subType, sendTime, fromGroup, fromQQ, msg, responseFlag)

    def eventGroupUpload(subType: int, sendTime: int, fromGroup: int, fromQQ: int, file: str) -> int:
        return dispatch('eventGroupUpload', subType, sendTime, fromGroup, fromQQ, file)

    def menuClick(index):
        return dispatch('menuClick', index)
