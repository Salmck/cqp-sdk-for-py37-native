
import CQP
from core.v9_plus import *

import os

from apscheduler.schedulers.background import BackgroundScheduler

sched = BackgroundScheduler()


# 详细参数表：https://apscheduler.readthedocs.io/en/latest/modules/triggers/cron.html#apscheduler.triggers.cron.CronTrigger

# second=*/5    *代表每秒，*/5代表每5秒
# minute=*/5    *代表每分钟，*/5代表每5分钟
# 以此推类

# 每天6点运行就是 sched.scheduled_job('cron', day="*", hour='6')

import time
@sched.scheduled_job('cron', second='*/5')
def timer_task():
    if CQP.enable and CQP.AC != -1:
        CQP.sendPrivateMsg(CQP.AC, 190796068, str(time.time()))

# 防止重复初始化
if not os.environ.get('CQP_INIT', ''):
    os.environ['CQP_INIT'] = 'True'

    try:
        def write_event_text(name, *args, **kwargs):
            with open("./event.txt", 'ab') as f:
                content = '{}--{}--{}\n'.format(name, str(args), str(kwargs)).encode()
                f.write(content)

        def Initialize(ac):
            write_event_text('Initialize', ac=ac)

        def eventStartup():
            write_event_text('eventStartup')
            sched.start()

        def eventExit():
            write_event_text('eventExit')
            sched.remove_all_jobs()
            sched.remove_executor()

        def eventEnable():
            write_event_text('eventEnable')

        def eventDisable():
            write_event_text('eventDisable')

        def eventPrivateMsg(subType: int, msgId: int, fromQQ: int, msg: str, font: int) -> int:
            write_event_text('eventPrivateMsg', subType=subType, msgId=msgId, fromQQ=fromQQ, msg=msg, font=font)
            # CQP.sendPrivateMsg(CQP.AC, fromQQ, '我是一个无情的复读机:' + msg)
            return CQP.EVENT_IGNORE

        def eventGroupMsg(subType: int, msgId: int, fromGroup: int, fromQQ: int, fromAnonymous: str, msg: str, font: int) -> int:
            write_event_text('eventGroupMsg', subType=subType, msgId=msgId, fromGroup=fromGroup, fromQQ=fromQQ, fromAnonymous=fromAnonymous, msg=msg, font=font)
            # CQP.sendPrivateMsg(CQP.AC, fromQQ, '我是一个无情的复读机:' + msg)
            # get_group_anonymous_info(fromAnonymous)
            
            return CQP.EVENT_IGNORE

        def eventDiscussMsg(subType: int, msgId: int, fromDiscuss: int, fromQQ: int, msg: str, font: int) -> int:
            write_event_text('eventDiscussMsg', subType=subType, msgId=msgId, fromDiscuss=fromDiscuss, fromQQ=fromQQ, msg=msg, font=font)
            # CQP.sendDiscussMsg(CQP.AC, fromDiscuss, '讨论组消息:' + msg)
            return CQP.EVENT_IGNORE

        def eventSystem_GroupAdmin(subType: int, sendTime: int, fromGroup: int, beingOperateQQ: int) -> int:
            write_event_text('eventSystem_GroupAdmin', subType=subType, sendTime=sendTime, fromGroup=fromGroup, beingOperateQQ=beingOperateQQ)
            return CQP.EVENT_IGNORE

        def eventSystem_GroupMemberDecrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
            write_event_text('eventSystem_GroupMemberDecrease', subType=subType, sendTime=sendTime, fromGroup=fromGroup, fromQQ=fromQQ, beingOperateQ=beingOperateQ)
            return CQP.EVENT_IGNORE

        def eventSystem_GroupMemberIncrease(subType: int, sendTime: int, fromGroup: int, fromQQ: int, beingOperateQQ: int) -> int:
            write_event_text('eventSystem_GroupMemberIncrease', subType=subType, sendTime=sendTime, fromGroup=fromGroup, fromQQ=fromQQ, beingOperateQQ=beingOperateQQ)
            return CQP.EVENT_IGNORE

        def eventFriend_Add(subType: int, sendTime: int, fromQQ: int) -> int:
            write_event_text('eventFriend_Add', subType=subType, sendTime=sendTime, fromQQ=fromQQ)
            return CQP.EVENT_IGNORE

        def eventRequest_AddFriend(subType: int, sendTime: int, fromQQ: int, msg: int, responseFlag: str) -> int:
            write_event_text('eventRequest_AddFriend', subType=subType, sendTime=sendTime, fromQQ=fromQQ, msg=msg, responseFlag=responseFlag)
            # CQP.setFriendAddRequest(CQP.AC, responseFlag, CQP.REQUEST_ALLOW, "")
            return CQP.EVENT_IGNORE

        def eventRequest_AddGroup(subType: int, sendTime: int, fromGroup: int, fromQQ: int, msg: str, responseFlag: str) -> int:
            write_event_text('eventRequest_AddGroup', subType=subType, sendTime=sendTime, fromGroup=fromGroup, fromQQ=fromQQ, msg=msg, responseFlag=responseFlag)
            """
            if subType == CQP.REQUEST_GROUPADD:
                CQP.setGroupAddRequestV2(CQP.AC, responseFlag, subType, CQP.REQUEST_ALLOW, "新人加群")
                return CQP.EVENT_BLOCK
            elif subType == CQP.REQUEST_GROUPINVITE:
                pass
            else:
                pass
            CQP.setGroupAddRequestV2(CQP.AC, responseFlag, subType, CQP.REQUEST_DENY, "群加满了")
            """
            return CQP.EVENT_IGNORE

        def eventGroupUpload(subType: int, sendTime: int, fromGroup: int, fromQQ: int, file: str) -> int:
            write_event_text('eventGroupUpload', subType=subType, sendTime=sendTime, fromGroup=fromGroup, fromQQ=fromQQ, file=file)
            # msgbox(get_group_upload_file(file))
            return CQP.EVENT_IGNORE

        def menuClick(index):
            write_event_text('index', index=index)

    except:
        show_exception()
