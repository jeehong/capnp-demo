# capnp demo in c program language

Unix: [![Unix Build Status](https://travis-ci.org/capnproto/capnproto.svg?branch=master)](https://travis-ci.org/capnproto/capnproto) Windows: [![Windows Build Status](https://ci.appveyor.com/api/projects/status/9rxff2tujkae4hte?svg=true)](https://ci.appveyor.com/project/kentonv/capnproto)

<img src='pictures/infinity-times-faster.png' style='width:334px; height:306px; float: right;'>

Cap'n Proto is an insanely fast data interchange format and capability-based RPC system. Think
JSON, except binary. Or think [Protocol Buffers](https://github.com/google/protobuf), except faster.
In fact, in benchmarks, Cap'n Proto is INFINITY TIMES faster than Protocol Buffers.

[Read more...](http://kentonv.github.com/capnproto/)

## Introduce
- This is a demonstration program about [c-capnproto](https://github.com/opensourcerouting/c-capnproto), and c-capnproto is just a subset of [capnproto](https://github.com/capnproto/capnproto) in C program language.
- This demo can be used as a reference if you want to use the C version of capnp.

## Usage
I would not like to introduce the usage about capnproto and c-capnproto, i just give a series of steps to explain how to introduce it into real project.
1. copy capn.c capn-list.inc capn-malloc.c capnp_c.h capnp_priv.h capn-stream.c into folder of lib.
2. Create and edit schema file according to rules of capnp and your demand.
3. Generate a C struct that corresponds to each proto struct, along with read/write functions that convert to/from capn proto form.
```
capnp compile -o ./capnpc-c demo.capnp
```
note: **capnp** is a executable tool and you can install it by building source code or inputing following command  on Ubuntu.
``` 
sudo apt-get install capnp
```
**capnpc-c** is a C language plugin for use with the **capnp**. it is made from c-capnproto project.

4. You will find 2 files(demo.capnp.h demo.capnp.c) which is located in the folder with demo.capnp together.
5. Setting the project environment in eclipse.
6. Build and execute it in command line, you will see the log such as the following display.
```

# 安装cmake & ninja
sudo apt install cmake ninja-build

# 打开根目录下CMakeLists.txt设置修改编译器

# 在主项目目录下创建一个build目录并进入
mkdir build
cd build

# 配置工程，使用Ninja生成构建文件
cmake -G "Ninja" ..

# 使用Ninja构建项目
ninja

# 执行目标文件
./capnp-demo

Start!
Build time: Mar 21 2019,13:24:37
Final data length is 160 byte(s).
[100] Verifying...    Result: Successful!
[101] Verifying...    Result: Successful!
[105] Verifying...    Result: Successful!
[106] Verifying...    Result: Successful!
[107] Verifying...    Result: Successful!
[109] Verifying...    Result: Successful!
[113] Verifying...    Result: Successful!
[114] Verifying...    Result: Successful!
[118] Verifying...    Result: Successful!
[119] Verifying...    Result: Successful!
Finish!
```

# End


