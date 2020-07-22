add_executable(list_sq.out sq.c)
target_link_libraries(list_sq.out PUBLIC list_sq)
target_compile_options(list_sq.out PRIVATE -Wall)

add_executable(list_link.out link.c)
target_link_libraries(list_link.out PUBLIC list_link)
target_compile_options(list_link.out PRIVATE -Wall)

add_executable(noise.out noise_reduction_link.c)
target_link_libraries(noise.out PUBLIC list_link)
target_compile_options(noise.out PRIVATE -Wall)

add_executable(list_clink.out clink.c)
target_link_libraries(list_clink.out PUBLIC list_clink)
target_compile_options(list_clink.out PRIVATE -Wall)
