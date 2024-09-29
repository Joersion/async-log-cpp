# 基于c++ 和 boost.log 的跨平台异步日志库

## 目录

- [说明](#说明)
- [安装](#安装)
- [简单示例](#简单示例)
- [关于](#关于)

## 说明

这是一个基于boost.log库，采用c++17开发的，支持跨平台的异步日志库，保证高效且线程安全的向指定文件输出日志，支持日志按等级打印用户数据，风格与 std::cout 类似的链式表达式

构建工具：
* 建议采用 cmake 3.10 以上，本人采用 3.28.3

编译器：
* 建议采用 GCC 7.1 以上，本人采用 13.2

boost库：
* 本人采用 1.81.0

## 安装
boost:

* 本地编译(本人采用静态库)：
```boost：
wget https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz
tar -xzf boost_1_81_0.tar.gz
cd boost_1_81_0
./bootstrap.sh --with-toolset=gcc
./b2 link=static cxxflags="-fPIC" install --prefix=../x86
```

* 交叉编译(以aarch64为例)：
```boost：
wget https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz
tar -xzf boost_1_81_0.tar.gz
cd boost_1_81_0
./bootstrap.sh --with-toolset=gcc
vim project-config.jam
if ! gcc in [ feature.values <toolset> ]

{

   using gcc : arm : /home/joersion/tool/aarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-rockchip1031-linux-gnu-gcc ;

}
./b2 link=static cxxflags="-fPIC" install --prefix=../aarch64
```
## 简单示例
* 打印日志信息:
#include "../AsyncLog.h"

void testLog() {
    AsyncLog::init("./log/logText");
    Log("this is a Log");
    LogDebug("this is a LogDebug");
    LogInfo("this is a LogInfo");
    LogWarn("this is a LogWarn");
    LogError("this is a LogError");
}

int main() {
    testLog();
}
```

## 关于

**************************
- 👋 I’m Joersion (WuJiaXiang)
- 👀 I’m interested in code
- 🌱 learning C++ and python and golang
- 📫 e-mail : 1539694343@qq.com

**************************
