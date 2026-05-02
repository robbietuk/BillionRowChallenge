file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_executable(GenerateData ${SOURCE_FILES})
