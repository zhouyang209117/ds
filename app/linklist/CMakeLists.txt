add_executable(linklist.out main.c)
target_link_libraries(linklist.out PUBLIC linklist)
target_compile_options(linklist.out PRIVATE -Wall)
