cmake_minimum_required(VERSION 3.20)
project(ProxyMaze)

# Compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Find package
find_package(jsoncpp REQUIRED)
find_package(httplib REQUIRED)

# Collect source files
file(GLOB SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Create executable
add_executable(exec ${SRC})

# Link 
target_link_libraries(exec PRIVATE JsonCpp::JsonCpp PRIVATE httplib::httplib)
