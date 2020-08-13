add_executable(conversion.out conversion.c)
target_link_libraries(conversion.out PUBLIC link_stack)
target_compile_options(conversion.out PRIVATE -Wall)