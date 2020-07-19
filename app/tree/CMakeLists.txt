add_executable(tree_bi.out bi.c)
target_link_libraries(tree_bi.out PUBLIC tree_bi)
target_compile_options(tree_bi.out PRIVATE -Wall)
