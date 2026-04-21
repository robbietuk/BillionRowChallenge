add_library(billionrow STATIC
    lib/util.cpp
)
target_include_directories(billionrow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(development development/main.cpp)
target_link_libraries(development PRIVATE billionrow)
