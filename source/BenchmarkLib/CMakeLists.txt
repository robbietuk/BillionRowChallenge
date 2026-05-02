file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_library(BenchmarkLib STATIC ${SOURCE_FILES})

target_include_directories(BenchmarkLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BenchmarkLib PUBLIC AlgorithmsLib)
