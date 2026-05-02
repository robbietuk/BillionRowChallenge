file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_executable(BillionRowChallengeApp ${SOURCE_FILES})

target_link_libraries(BillionRowChallengeApp PRIVATE BenchmarkLib)
