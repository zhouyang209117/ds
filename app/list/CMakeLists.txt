add_executable(list_sq.out sq.c)
target_link_libraries(list_sq.out PUBLIC list_sq)
target_compile_options(list_sq.out PRIVATE -Wall)

add_executable(list_sq1.out sq1.c)
target_link_libraries(list_sq1.out PUBLIC list_sq)
target_compile_options(list_sq1.out PRIVATE -Wall)

add_executable(list_link.out link.c)
target_link_libraries(list_link.out PUBLIC list_link)
target_compile_options(list_link.out PRIVATE -Wall)

add_executable(noise.out noise_reduction_link.c)
target_link_libraries(noise.out PUBLIC list_link)
target_compile_options(noise.out PRIVATE -Wall)

add_executable(list_clink.out clink.c)
target_link_libraries(list_clink.out PUBLIC list_clink)
target_compile_options(list_clink.out PRIVATE -Wall)

add_executable(list_dclink.out dclink.c)
target_link_libraries(list_dclink.out PUBLIC list_dclink)
target_compile_options(list_clink.out PRIVATE -Wall)

add_executable(simple_sq.out simple_sq.c)
add_executable(simple_link.out simple_link.c)
add_executable(simple_clink.out simple_clink.c)
add_executable(simple_dclink.out simple_dclink.c)