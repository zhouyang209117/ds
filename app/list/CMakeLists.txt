add_executable(list_se.out se.c)
target_link_libraries(list_se.out PUBLIC list_se)
target_compile_options(list_se.out PRIVATE -Wall)

add_executable(list_link.out link.c)
target_link_libraries(list_link.out PUBLIC list_link)
target_compile_options(list_link.out PRIVATE -Wall)

add_executable(noise.out noise_reduction.c)
target_link_libraries(noise.out PUBLIC list_link)
target_compile_options(noise.out PRIVATE -Wall)
