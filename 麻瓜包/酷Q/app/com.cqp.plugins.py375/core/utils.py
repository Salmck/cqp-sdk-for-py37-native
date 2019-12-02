
import ctypes
import re
import traceback
import struct
import base64


MB_OK = 0
MB_OKCANCEL = 1
MB_ABORTRETRYIGNORE = 2
MB_YESNOCANCEL = 3
MB_YESNO = 4
MB_RETRYCANCEL = 5
MB_CANCELTRYCONTINUE = 6
MB_ICONHAND = 0x10
MB_ICONQUESTION = 0x20
MB_ICONEXCLAMATION = 0x30
MB_ICONASTERISK = 0x40
MB_USERICON = 0x80
MB_ICONWARNING = MB_ICONEXCLAMATION
MB_ICONERROR = MB_ICONHAND
MB_DEFBUTTON1 = 0
MB_DEFBUTTON2 = 0x100
MB_DEFBUTTON3 = 0x200
MB_DEFBUTTON4 = 0x400
MB_APPLMODAL = 0
MB_SYSTEMMODAL = 0x1000
MB_TASKMODAL = 0x2000
MB_HELP = 0x4000
MB_NOFOCUS = 0x8000
MB_SETFOREGROUND = 0x10000
MB_DEFAULT_DESKTOP_ONLY = 0x20000
MB_TOPMOST = 0x40000
MB_RIGHT = 0x80000
MB_RTLREADING = 0x100000
MB_TYPEMASK = 0xf
MB_ICONMASK = 0xf0
MB_DEFMASK = 0xf00
MB_MODEMASK = 0x3000
MB_MISCMASK = 0xc000


class Unpack:
    def __init__(self, data):
        self.data = data
        self.pos = 0
    
    def _size(self, s):
        return struct.calcsize(s)

    def _buf(self, format):
        _next_pos = self.pos + self._size(format)
        _data = self.data[self.pos: _next_pos]
        _result = struct.unpack(format, _data)
        self.pos = _next_pos
        return _result[0]

    def Empty(self):
        self.data = bytes()

    def GetAll(self):
        return self.data[self.pos:]

    def GetBin(self, len):
        _next_pos = self.pos + len
        _data = self.data[self.pos: _next_pos]
        self.pos = _next_pos
        return _data
    
    def GetByte(self):
        return self._buf('>b')

    def GetShort(self):
        return self._buf('>h')

    def GetInt(self):
        return self._buf('>l')

    def GetLong(self):
        return self._buf('>q')

    def GetLenStr(self):
        len = self.GetShort()
        return self.GetBin(len).decode('gbk', errors='ignore')
    
    def GetToken(self):
        len = self.GetShort()
        return self.GetBin(len)
    
    def Len(self):
        return len(self.data) - self.pos


# 消息框显示提示信息
def msgbox(content, title="提示", button=MB_OK):
    USER32DLL = ctypes.WinDLL('user32.dll')
    content = ctypes.c_char_p(bytes(str(content), 'gbk'))
    title = ctypes.c_char_p(bytes(str(title), 'gbk'))
    return ctypes.c_int(USER32DLL.MessageBoxA(0	, content, title, button)).value

# 消息框显示异常信息
def show_exception():
    msgbox(traceback.format_exc(), '异常')
# 获取消息中的图片文件名
def get_message_images(msg: str) -> [str]:
    return re.findall(r'\[CQ:image,file=(.*?)\]', msg)
# 获取消息中的语音文件名
def get_message_records(msg: str) -> [str]:
    return re.findall(r'\[CQ:record,file=(.*?)\]', msg)
# 获取消息中的@的QQ号
def get_message_at_qqs(msg: str) -> [str]:
    return re.findall(r'\[CQ:at,qq=(.*?)\]', msg)
# 获取群消息中的上传文件名
def get_group_upload_file(fileMsg: str) -> dict:
    data = base64.b64decode(fileMsg)
    if len(data) < 20:
        return None
    u = Unpack(data)
    return {
        '文件ID': u.GetLenStr(),
        '文件名': u.GetLenStr(),
        '大小': u.GetLong(),
        'busid': u.GetLong(),
    }
# 获取群消息中的匿名发送者的信息
def get_group_anonymous_info(anonymous: str) -> dict:
    data = base64.b64decode(anonymous)
    if len(data) < 20:
        return None
    u = Unpack(data)
    return {
        'AID': u.GetLong(),
        '代号': u.GetLenStr(),
        'Token': u.GetToken()
    }
