# 声明子目录的源文件
set(CAPNP_SOURCES
    capn-malloc.c
    capn-stream.c
    capn.c
)

# 声明生成的库
add_library(capn_lib ${CAPNP_SOURCES})

# 可以添加其他配置，例如编译选项、链接库等
target_compile_options(capn_lib PRIVATE -Wall)
#target_link_libraries(capn_lib PRIVATE some_library)

# 指定头文件路径，如果有的话
target_include_directories(capn_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})