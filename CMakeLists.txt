cmake_minimum_required(VERSION 3.20)
project(ProxyMaze)

# Compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(LIB 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ProxyDebianService.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RequestService.cpp
)
