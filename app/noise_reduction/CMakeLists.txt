add_executable(noise.out main.c)
target_link_libraries(noise.out PUBLIC list_link)
target_compile_options(linklist.out PRIVATE -Wall)
