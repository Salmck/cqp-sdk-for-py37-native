
import CQP
from core.v9_plus import *


def Initialize(ac):
    pass

def eventStartup():
    pass

def eventExit():
    pass

def eventEnable():
    pass

def eventDisable():
    pass

def eventPrivateMsg(subType: int, msgId: int, fromQQ: int, msg: str, font: int) -> int:
    CQP.sendPrivateMsg(CQP.AC, fromQQ, msg)
    return CQP.EVENT_BLOCK

def eventGroupMsg(subType: int, msgId: int, fromGroup: int, fromQQ: int, fromAnonymous: str, msg: str, font: int) -> int:
    """
    CQP.sendGroupMsg(CQP.AC, fromGroup, '{} {}'.format(cq_at(fromQQ), msg))
    """
    return CQP.EVENT_IGNORE

def eventDiscussMsg(subType: int, msgId: int, fromDiscuss: int, fromQQ: int, msg: str, font: int) -> int:
    return CQP.EVENT_IGNORE

def eventSystem_GroupAdmin(subType: int, sendTime: int, fromGroup: int, beingOperateQQ: int) -> int:
    return CQP.EVENT_IGNORE

def eventSystem_GroupMemberDecrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
    return CQP.EVENT_IGNORE

def eventSystem_GroupMemberIncrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
    return CQP.EVENT_IGNORE

def eventFriend_Add(subType: int, sendTime: int, fromQQ: int) -> int:
    return CQP.EVENT_IGNORE

def eventRequest_AddFriend(subType: int, sendTime: int, fromQQ: int, msg: int, responseFlag: str) -> int:
    return CQP.EVENT_IGNORE

def eventRequest_AddGroup(subType: int, sendTime: int, fromGroup: int, fromQQ: int, msg: str, responseFlag: str) -> int:
    if subType == CQP.REQUEST_GROUPADD:
        CQP.setGroupAddRequestV2(CQP.AC, responseFlag, subType, CQP.REQUEST_ALLOW, "新人加群")
        CQP.sendGroupMsg(CQP.AC, fromGroup, '{} {}'.format(cq_at(fromQQ), '欢迎新人'))
        return CQP.EVENT_BLOCK # 已处理，防止下个插件处理
    elif subType == CQP.REQUEST_GROUPINVITE:
        pass
    else:
        pass
    CQP.setGroupAddRequestV2(CQP.AC, responseFlag, subType, CQP.REQUEST_DENY, "群加满了")
    return CQP.EVENT_BLOCK # 已处理，防止下个插件处理

def eventGroupUpload(subType: int, sendTime: int, fromGroup: int, fromQQ: int, file: str) -> int:
    CQP.sendGroupMsg(CQP.AC, fromGroup, '发现目标: {} 上传文件'.format(cq_at(fromQQ)))
    return CQP.EVENT_IGNORE

def menuClick(index):
    pass
