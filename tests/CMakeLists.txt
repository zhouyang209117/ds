set (PROJECT_LINK_LIBS /usr/local/lib/libgtest.a)
add_executable(unittest_list.out
        list/sq.cpp
        main.cpp)
target_link_libraries(unittest_list.out
        PUBLIC list_sq
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_clink_list.out
        list/clink.cpp
        main.cpp)
target_link_libraries(unittest_clink_list.out
        PUBLIC list_clink
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_dclink_list.out
        list/dclink.cpp
        main.cpp)
target_link_libraries(unittest_dclink_list.out
        PUBLIC list_dclink
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_link_list.out
        list/link.cpp
        main.cpp)
target_link_libraries(unittest_link_list.out
        PUBLIC list_link
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_stack.out
        stack/link.cpp
        main.cpp)
target_link_libraries(unittest_stack.out
        PUBLIC link_stack
        PUBLIC tree_bi
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_sq_stack.out
        stack/sq.cpp
        main.cpp)
target_link_libraries(unittest_sq_stack.out
        PUBLIC sq_stack
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_sq_queue.out
        queue/sq.cpp
        main.cpp)
target_link_libraries(unittest_sq_queue.out
        PUBLIC sq_queue
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_tree_bi.out
        tree/bi.cpp
        main.cpp)
target_link_libraries(unittest_tree_bi.out
        PUBLIC list_sq
        PUBLIC link_stack
        PUBLIC tree_bi
        PUBLIC ${PROJECT_LINK_LIBS})