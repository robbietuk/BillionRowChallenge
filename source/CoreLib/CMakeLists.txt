add_library(CoreLib STATIC
    DataManager.hpp
    DataManager.cpp
    DataProcessor.hpp
    DataProcessor.cpp
    DataProcessorAlpha.hpp
    DataProcessorAlpha.cpp
)
target_include_directories(CoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
