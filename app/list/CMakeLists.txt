add_executable(sqlist.out main.c)
target_link_libraries(sqlist.out PUBLIC list)
target_compile_options(sqlist.out PRIVATE -Wall)
