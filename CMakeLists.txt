cmake_minimum_required(VERSION 3.12)
project(capnp-demo C)

# 设置编译器
#set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_C_COMPILER gcc)

# 使用CMAKE_EXE_LINKER_FLAGS添加-static参数
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

# 添加可执行文件
add_executable(capnp-demo main.c)

# 添加子目录
add_subdirectory(lib)
add_subdirectory(proto)

target_link_libraries(capnp-demo capn_lib)
target_link_libraries(capnp-demo capnp_proto)

