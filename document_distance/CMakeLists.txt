# Create shared library 
add_library(
    document_distance SHARED
    distance.h
    distance.cc
    document.h
    document.cc
    ../api/distance_api.h
    ../api/distance_api.cc
    )

target_include_directories(document_distance PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")