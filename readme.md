# 酷Q SDK for Python

![AppVeyor](https://img.shields.io/appveyor/ci/crud-boy/cqp-sdk-for-py37-native)
[![GitHub license](https://img.shields.io/github/license/crud-boy/cqp-sdk-for-py37-native)](https://github.com/crud-boy/cqp-sdk-for-py37-native/blob/master/LICENSE)

# 插件说明
[Github项目链接](https://github.com/crud-boy/cqp-sdk-for-py37-native) 

    插件基于CPP CQP v9+, 部分补丁为易语言代码翻译

    插件包名: com.cqp.plugins.py375

    如果不知道插件使用方法,请查看v9_plus.py和utils.py

    注意: 
        1. 插件路径最多只能容纳260个ansii字符, 请不要把插件放到太深层的目录
        2. 进程内的插件只能运行一个，且不能有其他python37的插件，如果有其他同类型插件请自行整合
        3. 请不要改写cqpplugin.py的代码，请复制template.py到plugins目录, 并改名为xxx.py, 然后在__init__.py 添加你的插件,方可生效

# 安装说明

> 首先要安装vc2019 x86运行库  
[下载地址](https://www.cr173.com/soft/3106.html)  

一定要安装python3.7.5 x86 到这个位置 C:\Python37-32, 否则加载失败

我也不知道为什么,明明调用的是插件目录的python, 但是这个位置不安装python的话，就会加载失败



# pip说明
    1. cd /d 酷Q目录\app\com.cqp.plugins.py375\python
    2. pipenv.bat
    3. python -m pip install requests

    注意: 不能用pip install xxx, 一定要用python -m pip install xxx

# 函数说明
    具体文档, 请查看v9_plus.py和utils.py

    CQP.AC     = -1   为AuthCode
    CQP.enable = False 为判断插件是否启用

    其他参考v9_plus.py, v9方法可能参数不正确，参考以下说明

    参数类型对应表
        c++             python
        int32_t         int
        int64_t         int
        const char*     str
        CQBOOL          int 或者 bool    bool可能不对，自己测试

        特别注意: sdk代码里面接收的CQBOOL为python的int类型, 不是bool类型


# 事件回调表说明
    如果例子里面事件函数没写明返回值,则不用返回值, 如果有返回值一定要写,而且类型必须为int类型, 不能忽略返回值

    menuClick(index)   对应10个菜单序号1-10, 不用改json里面的函数名,可以改菜单名(sdk c++里面固定了菜单个数)
    Initialize         不能调用sdk发送消息, 可能会出错
    eventStartup       可以调用sdk, 但是要先判断CQP.AC != -1, 不然可能会出错


# 压力测试(无GIL死锁,不崩溃)
    群消息(带转发私聊)        2700/min


# 多线程支持
    已测试:
        支持:
            concurrent.futures.thread.ThreadPoolExecutor
            threading.Thread
            apscheduler.schedulers.background.BackgroundScheduler


# 未实现功能
    其他: 
        其他_转换_悬浮窗到文本


# 重要说明
    1. 不要在入口写多线程, 不然会假死或者重复执行多次  
    2. 多线程必须在酷Q回调事件写, 建议在eventStartup写  
    3. 不要用酷Q的重载应用，可能会导致多线程不关闭
    4. 建议在eventEnable中开启多线程，eventDisable和eventExit停止多线程  
    5. eventExit事件最好写try, 一定要关闭多线程，不然酷Q无法正常退出  
    6. 所有事件回调最好写try, 保证正确返回值
