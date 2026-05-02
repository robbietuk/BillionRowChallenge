add_library(AlgorithmsLib STATIC
    DataManager.hpp
    DataManager.cpp
    DataProcessor.hpp
    DataProcessor.cpp
    DataProcessorAlpha.hpp
    DataProcessorAlpha.cpp 
    Statistics.hpp
)
target_include_directories(AlgorithmsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
