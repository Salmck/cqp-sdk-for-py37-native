
import CQP
from core.v9_plus import *

'''
插件说明：
    core.v9_plus.py 
        CQP.xxx 函数：发消息, 获取群列表, 好友列表等
        cq_xxx  函数：emoji表情, 音乐链接, 网页链接，分享名片, at群友等

    core.utils.py 
        其他杂项函数, 获取消息中at的QQ号，文件, 图片，语音等链接
'''

'''
CQP.AC = -1             Initialize事件认证码, 插件会自动更新,不需要额外处理
CQP.enable = False      eventEnable事件被调用则自动设置为True, eventDisable事件被调用则自动设置为False, 不需要额外处理
'''

def Initialize(ac):
    '''认证码改变事件, 不需要处理ac, 请用CQP.AC获取认证码, 必须判断 > -1才可用'''
    pass

def eventStartup():
    '''酷Q启动事件'''
    pass

def eventExit():
    '''酷Q退出事件'''

def eventEnable():
    '''插件启用事件(此时CQP.enable = True)'''
    pass

def eventDisable():
    '''插件禁用事件(此时CQP.enable = False)(消息事件不回调,但是代码还是后台运行的)'''

def eventPrivateMsg(subType: int, msgId: int, fromQQ: int, msg: str, font: int) -> int:
    '''
    * Type=21 私聊消息
    * subType 子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
    '''
    return CQP.EVENT_IGNORE

def eventGroupMsg(subType: int, msgId: int, fromGroup: int, fromQQ: int, fromAnonymous: str, msg: str, font: int) -> int:
    '''
    * Type=2 群消息
    '''
    return CQP.EVENT_IGNORE

def eventDiscussMsg(subType: int, msgId: int, fromDiscuss: int, fromQQ: int, msg: str, font: int) -> int:
    '''
    * Type=4 讨论组消息
    '''
    return CQP.EVENT_IGNORE

def eventSystem_GroupAdmin(subType: int, sendTime: int, fromGroup: int, beingOperateQQ: int) -> int:
    '''
    * Type=101 群事件-管理员变动
    * subType 子类型，1/被取消管理员 2/被设置管理员
    '''
    return CQP.EVENT_IGNORE

def eventSystem_GroupMemberDecrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
    '''
    * Type=102 群事件-群成员减少
    * subType 子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
    * fromQQ 操作者QQ(仅subType为2、3时存在)
    * beingOperateQQ 被操作QQ
    '''
    return CQP.EVENT_IGNORE

def eventSystem_GroupMemberIncrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
    '''
    * Type=103 群事件-群成员增加
    * subType 子类型，1/管理员已同意 2/管理员邀请
    * fromQQ 操作者QQ(即管理员QQ)
    * beingOperateQQ 被操作QQ(即加群的QQ)
    '''
    return CQP.EVENT_IGNORE

def eventFriend_Add(subType: int, sendTime: int, fromQQ: int) -> int:
    '''
    * Type=201 好友事件-好友已添加
    '''
    return CQP.EVENT_IGNORE

def eventRequest_AddFriend(subType: int, sendTime: int, fromQQ: int, msg: int, responseFlag: str) -> int:
    '''
    * Type=301 请求-好友添加
    * msg 附言
    * responseFlag 反馈标识(处理请求用)
    '''
    return CQP.EVENT_IGNORE

def eventRequest_AddGroup(subType: int, sendTime: int, fromGroup: int, fromQQ: int, msg: str, responseFlag: str) -> int:
    '''
    * Type=302 请求-群添加
    * subType 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
    * msg 附言
    * responseFlag 反馈标识(处理请求用)
    '''
    return CQP.EVENT_BLOCK

def eventGroupUpload(subType: int, sendTime: int, fromGroup: int, fromQQ: int, file: str) -> int:
    '''
    * Type=11 群文件上传事件
    * file 上传文件信息 (使用get_group_upload_file获取文件信息, get_group_upload_file函数在core.utils.py里面)
    '''
    return CQP.EVENT_IGNORE

def menuClick(index):
    pass
