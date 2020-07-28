set (PROJECT_LINK_LIBS /usr/local/lib/libgtest.a)
add_executable(calc_test.out
        list/sq.cpp
        main.cpp)
target_link_libraries(calc_test.out
        PUBLIC list_sq
        PUBLIC ${PROJECT_LINK_LIBS})