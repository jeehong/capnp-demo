# capnp demo in c program language

Unix: [![Unix Build Status](https://travis-ci.org/capnproto/capnproto.svg?branch=master)](https://travis-ci.org/capnproto/capnproto) Windows: [![Windows Build Status](https://ci.appveyor.com/api/projects/status/9rxff2tujkae4hte?svg=true)](https://ci.appveyor.com/project/kentonv/capnproto)

<img src='http://kentonv.github.com/capnproto/images/infinity-times-faster.png' style='width:334px; height:306px; float: right;'>

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
Start processing!
Build time: Mar 20 2019,13:52:32
Final data length is 160 byte(s)
[107] Verifying...    Result: Successful!
[108] Verifying...    Result: Successful!
[112] Verifying...    Result: Successful!
[113] Verifying...    Result: Successful!
[114] Verifying...    Result: Successful!
[116] Verifying...    Result: Successful!
[120] Verifying...    Result: Successful!
[121] Verifying...    Result: Successful!
[125] Verifying...    Result: Successful!
[126] Verifying...    Result: Successful!
Successful!
```

#End


