add_library(CoreLib STATIC
    util.hpp
    util.cpp
    DataManager.hpp
    DataManager.cpp
    DataProcessor.hpp
    DataProcessor.cpp
    DataProcessorAlpha.hpp
    DataProcessorAlpha.cpp
)
target_include_directories(CoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
