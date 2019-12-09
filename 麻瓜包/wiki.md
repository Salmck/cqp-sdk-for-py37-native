# API文档

需要预先加载, 即可调用  
代码有问题，请提交issus  

```python
import CQP
from core.v9_plus import *
```

# utils.py函数

## get_group_anonymous_info(anonymous: str) -> dict
> 获取匿名者信息(此函数好像无效)
* anonymous     eventGroupMsg事件的fromAnonymous

        返回dict, 如下
        {
            'AID': int,
            '代号': str,
            'Token': bytes
        }

## get_group_upload_file(fileMsg: str) -> dict
> 获取群上传文件信息
* fileMsg   eventGroupMsg事件的file

        返回dict, 如下
        {
            '文件ID': str,
            '文件名': str,
            '大小': int,
            'busid': int,
        }

## get_message_at_qqs(msg: str) -> [str]
> 获取消息中的@的QQ号(注意返回str列表, CQP.xxx函数需要的是int类型)

## get_message_records(msg: str) -> [str]
> 获取消息中的音频文件(注意返回str列表)

## get_message_images(msg: str) -> [str]
> 获取消息中的图片文件名(注意返回str列表)


# v9_plus.py函数

##  cq_face(faceId)
> QQ内置表情(v9_plus.pyd文件中注释处 #表情_ 开头的数值)

##  cq_emoji(emoji)
> emoji表情(unicode编码)

##  cq_at(QQID=-1, space=False)
> @指定QQ, -1 为全群

##  cq_shake()
>   窗口抖动(shake) - 仅支持好友  

##  cq_music(musicId, webType='qq', style='')
>       发送音乐(music)
        musicId     音乐的歌曲数字ID
        webType     目前支持 qq/QQ音乐 163/网易云音乐 xiami/虾米音乐，默认为qq
        style       指定分享样式

##  cq_contact(QQID, type='qq')
>      发送名片分享(contact)
        QQID        类型为qq，则为帐号；类型为group，则为群号
        type        目前支持 qq/好友分享 group/群分享

##  cq_share(shareUrl, title='', content='', imggeUrl='')
>      发送链接分享(share)
        shareUrl   分享链接
        title       分享的标题，建议12字以内
        content     分享的简介，建议30字以内
        imggeUrl   分享的图片链接，留空则为默认图片

##  cq_location(x, y, addressName, address, zoom=15)
>     发送位置分享(location)
        x               经度
        y               纬度
        addressName     地点名称，建议12字以内
        address         地址，建议20字以内
        zoom            放大倍数 默认为 15

##  cq_music2(shareUrl, musicUrl, title='', content='', imageUrl='')
>     发送音乐自定义分享(music)
        shareUrl    点击分享后进入的音乐页面（如歌曲介绍页）
        musicUrl    音乐的音频链接（如mp3链接）
        title       音乐的标题，建议12字以内
        content     音乐的简介，建议30字以内
        imageUrl    音乐的封面图片链接，留空则为默认图片

##  cq_image(imagePath)
>     发送图片(image)  
    imagePath   将图片放在 data\image 下，并填写相对路径。如 data\image\1.jpg 则填写 1.jpg

##  cq_record(recordPath)  
>     发送语音(record)
    recordPath   将语音放在 data\record 下，并填写相对路径。如 data\record\1.amr 则填写 1.amr

##  CQP.sendPrivateMsg(authCode: int, QQID: int, msg: str) -> int
* 发送私聊消息, 成功返回消息ID
* QQID 目标QQ号
* msg 消息内容
    
##  CQP.sendGroupMsg(authCode: int, groupid: int, msg: str) -> int
* 发送群消息, 成功返回消息ID
* groupid 群号
* msg 消息内容

##  CQP.sendDiscussMsg(authCode: int, discussid: int, msg: str) -> int
* 发送讨论组消息, 成功返回消息ID
* discussid 讨论组号
* msg 消息内容

##  CQP.deleteMsg(authCode: int, msgid: int) -> int
* 撤回消息
* msgid 消息ID

##  CQP.sendLike(authCode: int, QQID: int) -> int
* 发送赞 发送手机赞
* QQID QQ号

##  CQP.setGroupKick(authCode: int, groupid: int, QQID: int, rejectaddrequest: bool) -> int
* 置群员移除
* groupid 目标群
* QQID QQ号
* rejectaddrequest 不再接收此人加群申请，请慎用

##  CQP.setGroupBan(authCode: int, groupid: int, QQID: int, duration: int) -> int
* 置群员禁言
* groupid 目标群
* QQID QQ号
* duration 禁言的时间，单位为秒。如果要解禁，这里填写0。

##  CQP.setGroupAdmin(authCode: int, groupid: int, QQID: int, setadmin: bool) -> int
* 置群管理员
* groupid 目标群
* QQID QQ号
* setadmin true:设置管理员 false:取消管理员

##  CQP.setGroupWholeBan(authCode: int, groupid: int, enableban: bool) -> int
* 置全群禁言
* groupid 目标群
* enableban true:开启 false:关闭

##  CQP.setGroupAnonymousBan(authCode: int, groupid: int, anomymous: str, duration: int) -> int
* 置匿名群员禁言
* groupid 目标群
* anomymous 群消息事件收到的 anomymous 参数
* duration 禁言的时间，单位为秒。不支持解禁。

##  CQP.setGroupAnonymous(authCode: int, groupid: int, enableanomymous: bool) -> int
* 置群匿名设置
* groupid 目标群
* enableanomymous true:开启 false:关闭

##  CQP.setGroupCard(authCode: int, groupid: int, QQID: int, newcard: str) -> int
* 置群成员名片
* groupid 目标群
* QQID 目标QQ
* newcard 新名片(昵称)

##  CQP.setGroupLeave(authCode: int, groupid: int, isdismiss: bool) -> int
* 置群退出 慎用, 此接口需要严格授权
* groupid 目标群
* isdismiss 是否解散 true:解散本群(群主) false:退出本群(管理、群成员)

##  CQP.setGroupSpecialTitle(authCode: int, groupid: int, QQID: int, newspecialtitle: str, duration: int) -> int
* 置群成员专属头衔 需群主权限
* groupid 目标群
* QQID 目标QQ
* newspecialtitle 头衔（如果要删除，这里填空）
* duration 专属头衔有效期，单位为秒。如果永久有效，这里填写-1。

##  CQP.setDiscussLeave(authCode: int, discussid: int) -> int
* 置讨论组退出
* discussid 目标讨论组号

##  CQP.setFriendAddRequest(authCode: int, responseflag: str, responseoperation: int, remark: str) -> int
* 置好友添加请求
* responseflag 请求事件收到的 responseflag 参数，加好友时对方发来的理由
* responseoperation REQUEST_ALLOW 或 REQUEST_DENY
* remark 添加后的好友备注

##  CQP.setGroupAddRequestV2(authCode: int, responseflag: str, requesttype: int, responseoperation: int, reason: str) -> int
* 置群添加请求
* responseflag 请求事件收到的 responseflag 参数，加群时对方发来的加群理由
* requesttype根据请求事件的子类型区分 REQUEST_GROUPADD 或 REQUEST_GROUPINVITE
* responseoperation  REQUEST_ALLOW 或 REQUEST_DENY
* reason 操作理由，仅 REQUEST_GROUPADD 且 REQUEST_DENY 时可用，拒绝加群时给对方回复的拒绝理由

##  CQP.getGroupMemberInfoV2(authCode: int, gourpId: int, QQID, useCache=False) -> [dict]
* 取群成员信息
* groupid 目标QQ所在群
* QQID 目标QQ号
* nocache 不使用缓存

        返回一个数组, 每个成员都是一个dict如下:  
        item = {
            '群号': int,
            'QQID':int,
            '昵称': str,
            '名片': str,
            '性别':  int,
            '年龄':  int,
            '地区': str,
            '加群时间': int,
            '最后发言': int,
            '等级_名称': int,
            '管理权限':  int,
            '不良记录成员': bool,
            '专属头衔': str,
            '专属头衔过期时间': int,
            '允许修改名片': bool
        }

##  CQP.getStrangerInfo(authCode: int, QQID: int, useCache=False) -> dict
* 取陌生人信息
* QQID 目标QQ
* nocache 不使用缓存

        返回一个dict如下:  
        {
            'QQID': int,
            '昵称': str,
            '性别': int,
            '年龄': int
        }

##  CQP.addLog(authCode: int, priority: int, category: str, content: str) -> int
* 添加日志
* priority 优先级，CQP.CQLOG_* 开头的常量
* category 类型    日志标题
* content 内容

        ##  调试 灰色
        CQP.CQLOG_DEBUG = 0
        ##  信息 黑色
        CQP.CQLOG_INFO = 10
        ##  信息(成功) 紫色
        CQP.CQLOG_INFOSUCCESS = 11
        ##  信息(接收) 蓝色
        CQP.CQLOG_INFORECV = 12
        ##  信息(发送) 绿色
        CQP.CQLOG_INFOSEND = 13
        ##  警告 橙色
        CQP.CQLOG_WARNING = 20
        ##  错误 红色
        CQP.CQLOG_ERROR = 30

        ##  提示框退出酷Q，致命错误 深红
        CQP.CQLOG_FATAL = 40

##  CQP.getCookies(authCode: int) -> str
* 取Cookies 慎用, 此接口需要严格授权

##  CQP.getCsrfToken(authCode: int) -> int
* 取CsrfToken 慎用, 此接口需要严格授权

##  CQP.getLoginQQ(authCode: int) -> int
* 取登录QQ

##  CQP.getLoginNick(authCode: int) -> str
* 取登录QQ昵称

##  CQP.getAppDirectory(authCode: int) -> str
* 取应用目录，返回的路径末尾带"\"

##  CQP.setFatal(authCode: int, errorinfo: str) -> int
* 置致命错误提示
* errorinfo 错误信息

##  CQP.getRecord(authCode: int, file: str, format: str) -> str
* 接收语音，接收消息中的语音(record),返回保存在 \data\record\ 目录下的文件名
* file 收到消息中的语音文件名(file), 可用get_message_records(msg)[0] 获取第一个
* outformat 应用所需的语音文件格式，目前支持 mp3 amr wma m4a spx ogg wav flac

##  CQP.getImage(authCode: int, file: str) -> str
* 接收图片
* file 收到消息中的图片文件名(file), get_message_images(msg)[0] 获取第一个

##  CQP.getRecordV2(authCode: int, file: str, format: str) -> str
* 接收语音，接收消息中的语音(record),返回保存在 \data\record\ 目录下的文件名
* file 收到消息中的语音文件名(file), 可用get_message_records(msg)[0] 获取第一个
* format 应用所需的语音文件格式，目前支持 mp3 amr wma m4a spx ogg wav flac

##  CQP.getGroupMemberList(authCode: int, gourpId: int) -> [dict]
* 获取群成员列表
* gourpId 群号

        返回一个数组, 每个成员都是一个dict如下:  
        item = {
            '群号': int,
            'QQID':int,
            '昵称': str,
            '名片': str,
            '性别':  int,
            '年龄':  int,
            '地区': str,
            '加群时间': int,
            '最后发言': int,
            '等级_名称': int,
            '管理权限':  int,
            '不良记录成员': bool,
            '专属头衔': str,
            '专属头衔过期时间': int,
            '允许修改名片': bool
        }

##  CQP.getGroupListauthCode: int) -> [dict]
* 获取群列表

        返回一个数组, 每个成员都是一个dict如下:  
        item = {
            '群号': int,
            '名称': str,
        }

##  CQP.getFriendList(authCode: int) -> [dict]
* 获取好友列表

        返回一个数组, 每个成员都是一个dict如下:
        item = {
            '帐号': int,
            '昵称': str,
            '备注': str,
        }

##  CQP.canSendRecord(authCode: int) -> bool
* 是否可发送语音

##  CQP.canSendImage(authCode: int) -> bool
* 是否可发送图片

##  CQP.getCookiesV2(authCode: int, domain: str) -> str
* 取Cookies 慎用, 此接口需要严格授权
* domain 域名，例如：qq.com

##  CQP.getGroupInfo(authCode: int, gourpId: int, useCache=False) -> [dict]
* 取群信息
* gourpId  群号
* useCache 是否使用缓存

        返回一个数组, 每个成员都是一个dict如下:
        item = {
            '群号': int,
            '名称': str,
            '当前人数': int,
            '人数上限': int,
        }

##  CQP.sendLikeV2(authCode: int, QQID: int) -> int
* 发送赞 发送手机赞
* QQID QQ号