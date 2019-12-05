
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
    return CQP.EVENT_IGNORE

def eventGroupMsg(subType: int, msgId: int, fromGroup: int, fromQQ: int, fromAnonymous: str, msg: str, font: int) -> int:
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
    return CQP.EVENT_BLOCK

def eventGroupUpload(subType: int, sendTime: int, fromGroup: int, fromQQ: int, file: str) -> int:
    return CQP.EVENT_IGNORE

def menuClick(index):
    pass
