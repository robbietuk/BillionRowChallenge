add_executable(Tests test_main.cpp)
target_link_libraries(Tests PRIVATE BenchmarkLib)
enable_testing()
add_test(NAME AllTests COMMAND $<TARGET_FILE:Tests>)