# 声明子目录的源文件
set(CAPNP_PROTO_SOURCES
    demo.capnp.c
)

# 声明生成的库
add_library(capnp_proto ${CAPNP_PROTO_SOURCES})

# 可以添加其他配置，例如编译选项、链接库等
target_compile_options(capnp_proto PRIVATE -Wall)
#target_link_libraries(capnp_proto PRIVATE some_library)

target_include_directories(capnp_proto PRIVATE ${CMAKE_SOURCE_DIR}/lib)

# 指定头文件路径，如果有的话
target_include_directories(capnp_proto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
