add_executable(ht.out ht.c)
target_link_libraries(ht.out PUBLIC list_sq)
target_compile_options(ht.out PRIVATE -Wall)