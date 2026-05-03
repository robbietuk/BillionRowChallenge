file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_library(AlgorithmsLib STATIC ${SOURCE_FILES})

target_include_directories(AlgorithmsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
