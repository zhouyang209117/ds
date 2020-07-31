set (PROJECT_LINK_LIBS /usr/local/lib/libgtest.a)
add_executable(unittest_list.out
        list/sq.cpp
        main.cpp)
target_link_libraries(unittest_list.out
        PUBLIC list_sq
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_dclink_list.out
        list/dclink.cpp
        main.cpp)
target_link_libraries(unittest_dclink_list.out
        PUBLIC list_dclink
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_stack.out
        stack/link.cpp
        main.cpp)
target_link_libraries(unittest_stack.out
        PUBLIC list_link
        PUBLIC ${PROJECT_LINK_LIBS})

add_executable(unittest_tree_bi.out
        tree/bi.cpp
        main.cpp)
target_link_libraries(unittest_tree_bi.out
        PUBLIC list_sq
        PUBLIC tree_bi
        PUBLIC ${PROJECT_LINK_LIBS})