add_library(CoreLib STATIC
    util.hpp
    util.cpp
)
target_include_directories(CoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
