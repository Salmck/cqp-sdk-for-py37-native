import ctypes
import struct
import base64
from html import escape, unescape

import CQP
from core.utils import *


CQDll = ctypes.WinDLL('CQP.dll')


'''
#表情_惊讶			"0"
#表情_撇嘴			"1"
#表情_色			"2"
#表情_发呆			"3"
#表情_得意			"4"
#表情_流泪			"5"
#表情_害羞			"6"
#表情_闭嘴			"7"
#表情_睡			"8"
#表情_大哭			"9"
#表情_尴尬			"10"
#表情_发怒			"11"
#表情_调皮			"12"
#表情_呲牙			"13"
#表情_微笑			"14"
#表情_难过			"15"
#表情_酷			"16"
#表情_抓狂			"18"
#表情_吐			"19"
#表情_偷笑			"20"
#表情_可爱			"21"
#表情_白眼			"22"
#表情_傲慢			"23"
#表情_饥饿			"24"
#表情_困			"25"
#表情_惊恐			"26"
#表情_流汗			"27"
#表情_憨笑			"28"
#表情_大兵			"29"
#表情_奋斗			"30"
#表情_咒骂			"31"
#表情_疑问			"32"
#表情_晕			"34"
#表情_折磨			"35"
#表情_衰			"36"
#表情_骷髅			"37"
#表情_敲打			"38"
#表情_再见			"39"
#表情_发抖			"41"
#表情_爱情			"42"
#表情_跳跳			"43"
#表情_猪头			"46"
#表情_拥抱			"49"
#表情_蛋糕			"53"
#表情_闪电			"54"
#表情_炸弹			"55"
#表情_刀			"56"
#表情_足球			"57"
#表情_便便			"59"
#表情_咖啡			"60"
#表情_饭			"61"
#表情_玫瑰			"63"
#表情_凋谢			"64"
#表情_爱心			"66"
#表情_心碎			"67"
#表情_礼物			"69"
#表情_太阳			"74"
#表情_月亮			"75"
#表情_强			"76"
#表情_弱			"77"
#表情_握手			"78"
#表情_胜利			"79"
#表情_飞吻			"85"
#表情_怄火			"86"
#表情_西瓜			"89"
#表情_冷汗			"96"
#表情_擦汗			"97"
#表情_抠鼻			"98"
#表情_鼓掌			"99"
#表情_糗大了		"100"
#表情_坏笑			"101"
#表情_左哼哼		"102"
#表情_右哼哼		"103"
#表情_哈欠			"104"
#表情_鄙视			"105"
#表情_委屈			"106"
#表情_快哭了		"107"
#表情_阴险			"108"
#表情_亲亲			"109"
#表情_吓			"110"
#表情_可怜			"111"
#表情_菜刀			"112"
#表情_啤酒			"113"
#表情_篮球			"114"
#表情_乒乓			"115"
#表情_示爱			"116"
#表情_瓢虫			"117"
#表情_抱拳			"118"
#表情_勾引			"119"
#表情_拳头			"120"
#表情_差劲			"121"
#表情_爱你			"122"
#表情_不			"123"
#表情_好			"124"
#表情_转圈			"125"
#表情_磕头			"126"
#表情_回头			"127"
#表情_跳绳			"128"
#表情_挥手			"129"
#表情_激动			"130"
#表情_街舞			"131"
#表情_献吻			"132"
#表情_左太极		"133"
#表情_右太极		"134"
#表情_双喜			"136"
#表情_鞭炮			"137"
#表情_灯笼			"138"
#表情_发财			"139"
#表情_K歌			"140"
#表情_购物			"141"
#表情_邮件			"142"
#表情_帅			"143"
#表情_喝彩			"144"
#表情_祈祷			"145"
#表情_爆筋			"146"
#表情_棒棒糖		 "147"
#表情_喝奶			"148"
#表情_下面			"149"
#表情_香蕉			"150"
#表情_飞机			"151"
#表情_开车			"152"
#表情_高铁左车头	 "153"
#表情_车厢			"154"
#表情_高铁右车头	 "155"
#表情_多云			"156"
#表情_下雨			"157"
#表情_钞票			"158"
#表情_熊猫			"159"
#表情_灯泡			"160"
#表情_风车			"161"
#表情_闹钟			"162"
#表情_打伞			"163"
#表情_彩球			"164"
#表情_钻戒			"165"
#表情_沙发			"166"
#表情_纸巾			"167"
#表情_药			"168"
#表情_手枪			"169"
#表情_青蛙			"170"
'''

def cq_face(faceId):
    ''' #表情_* 开头常量 '''
    return '[CQ:face,id={}]'.format(faceId)

def cq_emoji(emoji):
    ''' emoji的unicode编号 '''
    return '[CQ:emoji,id={}]'.format(emoji)

def cq_at(QQID, space=False):
    ''' 
    @某人(at)
        QQID: -1 为全体
    '''
    return '[CQ:at,qq={}]{}'.format(QQID if QQID != -1 else 'all' if space else '')

def cq_shake():
    ''' 窗口抖动(shake) - 仅支持好友 '''
    return '[CQ:shake]'

def cq_anonymous(ignore=True):
    ''' 匿名发消息(anonymous) - 仅支持群 '''
    return '[CQ:anonymous,qq={}]'.format('ignore=true' if ignore else '')

def cq_music(musicId, webType='qq', style=''):
    '''
    发送音乐(music)
        musicId     音乐的歌曲数字ID
        webType     目前支持 qq/QQ音乐 163/网易云音乐 xiami/虾米音乐，默认为qq
        style       指定分享样式
    '''
    return '[CQ:music,id={}			type={},style={}]'.format(musicId, escape(webType), style)

def cq_contact(QQID, type='qq'):
    '''
    发送名片分享(contact)
        QQID        类型为qq，则为帐号；类型为group，则为群号
        type        目前支持 qq/好友分享 group/群分享
    '''
    return '[CQ:contact,type={},id={}]'.format(type, QQID)

def cq_share(shareUrl, title='', content='', imggeUrl=''):
    '''
    发送链接分享(share)
        shareUrl   分享链接
        title       分享的标题，建议12字以内
        content     分享的简介，建议30字以内
        imggeUrl   分享的图片链接，留空则为默认图片
    '''
    return '[CQ:share,url={},title={},content={},image={}]'.format(shareUrl, title, content, imggeUrl)

def cq_location(x, y, addressName, address, zoom=15):
    '''
    发送位置分享(location)
        x               经度
        y               纬度
        addressName     地点名称，建议12字以内
        address         地址，建议20字以内
        zoom            放大倍数 默认为 15
    '''
    return '[[CQ:location,lat={},lon={},zoom={},title={},content={}]'.format(y, x, zoom, escape(addressName), escape(address))

def cq_music2(shareUrl, musicUrl, title='', content='', imageUrl=''):
    '''
    发送音乐自定义分享(music)
        shareUrl    点击分享后进入的音乐页面（如歌曲介绍页）
        musicUrl    音乐的音频链接（如mp3链接）
        title       音乐的标题，建议12字以内
        content     音乐的简介，建议30字以内
        imageUrl    音乐的封面图片链接，留空则为默认图片
    '''
    return '[CQ:music,type=custom,url={},audio={},title={},content={},image={}]'.format(shareUrl, musicUrl, title, content, imageUrl)

def cq_image(imagePath):
    '''
    发送图片(image)
        imagePath   将图片放在 data\image 下，并填写相对路径。如 data\image\1.jpg 则填写 1.jpg
    '''
    return '[CQ:image,file={}]'.format(imagePath)

def cq_record(recordPath):
    '''
    发送语音(record)
        recordPath   将语音放在 data\record 下，并填写相对路径。如 data\record\1.amr 则填写 1.amr
    '''
    return '[CQ:record,file={}]'.format(recordPath)

def _CQ_getRecordV2(authCode: int, file: str, format: str) -> str:
    authCode = ctypes.c_int(authCode)
    file = ctypes.c_char_p(bytes(file, 'gbk'))
    format = ctypes.c_char_p(bytes(format, 'gbk'))
    result = CQDll.CQ_getRecordV2(authCode, file, format)
    return ctypes.c_char_p(result).value.decode('gbk', errors='ignore')

def _CQ_getImage(authCode: int, file: str) -> str:
    authCode = ctypes.c_int(authCode)
    file = ctypes.c_char_p(bytes(file, 'gbk'))
    result = CQDll.CQ_getImage(authCode, file)
    return ctypes.c_char_p(result).value.decode('gbk', errors='ignore')

def _CQ_getGroupMemberList(authCode: int, gourpId: int) -> [dict]:
    authCode = ctypes.c_int(authCode)
    gourpId = ctypes.c_longlong(gourpId)
    result = CQDll.CQ_getGroupMemberList(authCode, gourpId)
    
    source = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')
    
    # 读取数据
    resultList = []

    data = base64.b64decode(source)
    if len(data) < 4:
        return []
    
    u = Unpack(data)
    count = u.GetInt()
    
    for _ in range(count):
        if u.Len() <= 0:
            return resultList
        # 读取列表数据
        _data = Unpack(u.GetToken())
        item = {
            '群号': _data.GetLong (),
            'QQID': _data.GetLong (),
            '昵称': _data.GetLenStr (),
            '名片': _data.GetLenStr (),
            '性别':  _data.GetInt (),
            '年龄':  _data.GetInt (),
            '地区': _data.GetLenStr (),
            '加群时间': _data.GetInt (),
            '最后发言': _data.GetInt (),
            '等级_名称': _data.GetLenStr (),
            '管理权限':  _data.GetInt (),
            '不良记录成员': _data.GetInt () == 1,
            '专属头衔': _data.GetLenStr (),
            '专属头衔过期时间': _data.GetInt (),
            '允许修改名片': _data.GetInt () == 1
        }
        resultList.append(item)
    return resultList

def _CQ_getGroupList(authCode: int) -> [dict]:
    authCode = ctypes.c_int(authCode)
    result = CQDll.CQ_getGroupList(authCode)
    
    source = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')

    # 读取数据
    resultList = []

    data = base64.b64decode(source)
    if len(data) < 4:
        return []
    
    u = Unpack(data)
    count = u.GetInt()
    
    for _ in range(count):
        if u.Len() <= 0:
            return resultList
        # 读取列表数据
        _data = Unpack(u.GetToken())
        item = {
            '群号': _data.GetLong (),
            '名称': _data.GetLenStr (),
        }
        resultList.append(item)
    return resultList

def _CQ_getFriendList(authCode: int) -> [dict]:
    authCode = ctypes.c_int(authCode)
    result = CQDll.CQ_getGroupList(authCode)
    
    source = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')

    # 读取数据
    resultList = []

    data = base64.b64decode(source)
    if len(data) < 4:
        return []
    
    u = Unpack(data)
    count = u.GetInt()
    
    for _ in range(count):
        if u.Len() <= 0:
            return resultList
        # 读取列表数据
        _data = Unpack(u.GetToken())
        item = {
            '帐号': _data.GetLong (),
            '昵称': _data.GetLenStr (),
            '备注': _data.GetLenStr (),
        }
        resultList.append(item)
    return resultList

def _CQ_canSendRecord(authCode: int) -> bool:
    return ctypes.c_int(CQDll.CQ_canSendRecord(authCode)).value > 0

def _CQ_canSendImage(authCode: int) -> bool:
    return ctypes.c_int(CQDll.CQ_canSendImage(authCode)).value > 0

def _CQ_getGroupMemberInfoV2(authCode: int, gourpId: int, QQID, useCache=False) -> [dict]:
    authCode = ctypes.c_int(authCode)
    gourpId = ctypes.c_longlong(gourpId)
    QQID = ctypes.c_longlong(QQID)
    useCache = ctypes.c_bool(useCache)
    result = CQDll.CQ_getGroupMemberInfoV2(authCode, gourpId, QQID, useCache)
    
    source = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')
    
    # 读取数据
    resultList = []

    data = base64.b64decode(source)
    if len(data) < 4:
        return []
    
    u = Unpack(data)
    count = u.GetInt()
    
    for _ in range(count):
        if u.Len() <= 0:
            return resultList
        # 读取列表数据
        _data = Unpack(u.GetToken())
        item = {
            '群号': _data.GetLong (),
            'QQID': _data.GetLong (),
            '昵称': _data.GetLenStr (),
            '名片': _data.GetLenStr (),
            '性别':  _data.GetInt (),
            '年龄':  _data.GetInt (),
            '地区': _data.GetLenStr (),
            '加群时间': _data.GetInt (),
            '最后发言': _data.GetInt (),
            '等级_名称': _data.GetLenStr (),
            '管理权限':  _data.GetInt (),
            '不良记录成员': _data.GetInt () == 1,
            '专属头衔': _data.GetLenStr (),
            '专属头衔过期时间': _data.GetInt (),
            '允许修改名片': _data.GetInt () == 1
        }
        resultList.append(item)
    return resultList

def _CQ_getStrangerInfo(authCode: int, QQID: int, useCache=False) -> dict:
    authCode = ctypes.c_int(authCode)
    QQID = ctypes.c_longlong(QQID)
    result = CQDll.CQ_getStrangerInfo(authCode, QQID, useCache)
    
    source = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')
    
    # 读取数据
    resultList = []

    data = base64.b64decode(source)
    if len(data) < 4:
        return []
    
    u = Unpack(data)

    return {
        'QQID': u.GetLong (),
        '昵称': u.GetLenStr (),
        '性别': u.GetInt (),
        '年龄': u.GetInt ()
    }

def _CQ_getCookiesV2(authCode: int, domain: str) -> str:
    authCode = ctypes.c_int(authCode)
    domain = ctypes.c_char_p(bytes(domain, 'gbk'))
    result = CQDll.CQ_getCookiesV2(authCode, domain)
    result = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')
    return result

def _CQ_getGroupInfo(authCode: int, gourpId: int, useCache=False) -> [dict]:
    authCode = ctypes.c_int(authCode)
    gourpId = ctypes.c_longlong(gourpId)
    useCache = ctypes.c_bool(useCache)
    result = CQDll.CQ_getGroupInfo(authCode, gourpId, useCache)
    
    source = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')
    
    # 读取数据
    resultList = []

    data = base64.b64decode(source)
    if len(data) < 4:
        return []
    
    u = Unpack(data)
    count = u.GetInt()
    
    for _ in range(count):
        if u.Len() <= 0:
            return resultList
        # 读取列表数据
        _data = Unpack(u.GetToken())
        item = {
            '群号': _data.GetLong (),
            '名称': _data.GetLenStr (),
            '当前人数': _data.GetInt (),
            '人数上限': _data.GetInt (),
        }
        resultList.append(item)
    return resultList

def _CQ_sendLikeV2(authCode: int, QQID: int) -> int:
    authCode = ctypes.c_int(authCode)
    QQID = ctypes.c_longlong(QQID)
    result = CQDll.CQ_sendLikeV2(authCode, QQID)
    result = ctypes.c_int32(result).valu
    return result

def _CQ_getCookies(authCode: int) -> str:
    authCode = ctypes.c_int(authCode)
    result = CQDll.CQ_getCookies(authCode)
    result = ctypes.c_char_p(result).value.decode('gbk', errors='ignore')
    return result


CQP.AC = -1
CQP.enable = False
CQP.EVENT_IGNORE = 0
CQP.EVENT_BLOCK = 1
CQP.REQUEST_ALLOW = 1
CQP.REQUEST_DENY = 2
CQP.REQUEST_GROUPADD = 1
CQP.REQUEST_GROUPINVITE = 2
CQP.CQLOG_DEBUG = 0
CQP.CQLOG_INFO = 10
CQP.CQLOG_INFOSUCCESS = 11
CQP.CQLOG_INFORECV = 12
CQP.CQLOG_INFOSEND = 13
CQP.CQLOG_WARNING = 20
CQP.CQLOG_ERROR = 30
CQP.CQLOG_FATAL = 40


# ------ 以下为V9+函数  ------
# CQP.sendPrivateMsg(authCode: int, QQID: int, msg: str) -> int
# CQP.sendGroupMsg(authCode: int, groupid: int, msg: str) -> int
# CQP.sendDiscussMsg(authCode: int, discussid: int, msg: str) -> int
# CQP.deleteMsg(authCode: int, msgid: int) -> int
# CQP.sendLike(authCode: int, QQID: int) -> int
# CQP.setGroupKick(authCode: int, groupid: int, QQID: int, rejectaddrequest: bool) -> int
# CQP.setGroupBan(authCode: int, groupid: int, QQID: int, duration: int) -> int
# CQP.setGroupAdmin(authCode: int, groupid: int, QQID: int, setadmin: bool) -> int
# CQP.setGroupWholeBan(authCode: int, groupid: int, enableban: bool) -> int
# CQP.setGroupAnonymousBan(authCode: int, groupid: int, anomymous: str, duration: int) -> int
# CQP.setGroupAnonymous(authCode: int, groupid: int, enableanomymous: bool) -> int
# CQP.setGroupCard(authCode: int, groupid: int, QQID: int, newcard: str) -> int
# CQP.setGroupLeave(authCode: int, groupid: int, isdismiss: bool) -> int
# CQP.setGroupSpecialTitle(authCode: int, groupid: int, QQID: int, newspecialtitle: str, duration: int) -> int
# CQP.setDiscussLeave(authCode: int, discussid: int) -> int
# CQP.setFriendAddRequest(authCode: int, responseflag: str, responseoperation: int, remark: str) -> int
# CQP.setGroupAddRequestV2(authCode: int, responseflag: str, requesttype: int, responseoperation: int, reason: str) -> int
CQP.getGroupMemberInfoV2 = _CQ_getGroupMemberInfoV2
CQP.getStrangerInfo = _CQ_getStrangerInfo
# CQP.addLog(authCode: int, priority: int, category: str, content: str) -> int
CQP.getCookies = _CQ_getCookies
# CQP.getCsrfToken(authCode: int) -> int
# CQP.getLoginQQ(authCode: int) -> int
# CQP.getLoginNick(authCode: int) -> str
# CQP.getAppDirectory(authCode: int) -> str
# CQP.setFatal(authCode: int, errorinfo: str) -> int
# CQP.getRecord(authCode: int, file: str, outformat) -> str


CQP.getImage = _CQ_getImage
CQP.getRecordV2 = _CQ_getRecordV2
CQP.getGroupMemberList = _CQ_getGroupMemberList
CQP.getGroupList = _CQ_getGroupList
CQP.getFriendList = _CQ_getFriendList
CQP.canSendRecord = _CQ_canSendRecord
CQP.canSendImage = _CQ_canSendImage
CQP.getCookiesV2 = _CQ_getCookiesV2
CQP.getGroupInfo = _CQ_getGroupInfo
CQP.sendLikeV2 = _CQ_sendLikeV2

