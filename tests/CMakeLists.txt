add_executable(Tests test_main.cpp)
target_link_libraries(Tests PRIVATE CoreLib)
add_test(NAME AllTests COMMAND billionrow_tests)
