import traceback
import CQP
from core.v9_plus import *
from apscheduler.schedulers.background import BackgroundScheduler


# 详细参数表：https://apscheduler.readthedocs.io/en/latest/modules/triggers/cron.html#apscheduler.triggers.cron.CronTrigger

# second=*/5    *代表每秒，*/5代表每5秒
# minute=*/5    *代表每分钟，*/5代表每5分钟
# 以此推类

# 每天6点运行就是 sched.scheduled_job('cron', day="*", hour='6')

sched = BackgroundScheduler()


@sched.scheduled_job('cron', second='*/20')
def timer_task():
    if CQP.AC != -1:
        try:
            for item in CQP.getGroupList(CQP.AC):
                if CQP.sendGroupMsg(CQP.AC, item['群号'], item['名称']) > 0:
                    CQP.addLog(CQP.AC, CQP.CQLOG_INFOSEND, '定时任务机器人(发送成功)', '群号: {} 群名: {}'.format(item['群号'], item['名称']))
                else:
                    CQP.addLog(CQP.AC, CQP.CQLOG_FATAL, '定时任务机器人(发送失败)', '群号: {} 群名: {}'.format(item['群号'], item['名称']))
        except:
            CQP.addLog(CQP.AC, CQP.CQLOG_FATAL, '定时任务机器人(异常了)', str(traceback.format_exc()))


def Initialize(ac):
    pass

def eventStartup():
    sched.start()

def eventExit():
    sched.remove_all_jobs()
    sched.remove_executor()
    sched.shutdown()

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
    return CQP.EVENT_IGNORE

def eventGroupUpload(subType: int, sendTime: int, fromGroup: int, fromQQ: int, file: str) -> int:
    return CQP.EVENT_IGNORE

def menuClick(index):
    pass
