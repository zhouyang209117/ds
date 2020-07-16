add_executable(linklist.out main.c)
target_link_libraries(linklist.out PUBLIC list_link)
target_compile_options(linklist.out PRIVATE -Wall)
