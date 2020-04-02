cmake_minimum_required(VERSION 3.10.2)
project(documentdistanproblem VERSION 1.0.0)

add_compile_options(
    "-Wall" "-std=c++17"
)
 
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# x64 bit
set(CMAKE_CXX_FLAGS "-m64")

# Add sub directory document_distance
add_subdirectory(document_distance)

add_executable(ccdist main.cc)

target_link_libraries(ccdist PRIVATE document_distance)