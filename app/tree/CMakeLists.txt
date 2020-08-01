add_executable(ht.out ht.c)
target_link_libraries(ht.out PUBLIC list_sq)
target_compile_options(ht.out PRIVATE -Wall)

add_executable(tree_bi.out bi.c)
target_link_libraries(tree_bi.out
        PUBLIC tree_bi
        PUBLIC list_sq)
target_compile_options(tree_bi.out PRIVATE -Wall)