set (PROJECT_LINK_LIBS /usr/local/lib/libgtest.a)
add_executable(unittest.out
        list/sq.cpp
        main.cpp)
target_link_libraries(unittest.out
        PUBLIC list_sq
        PUBLIC ${PROJECT_LINK_LIBS})