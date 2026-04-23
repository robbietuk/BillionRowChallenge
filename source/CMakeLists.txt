add_library(CoreLib STATIC
    lib/util.cpp
)
target_include_directories(CoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(BillionRowChallengeApp development/main.cpp)
target_link_libraries(BillionRowChallengeApp PRIVATE CoreLib)
