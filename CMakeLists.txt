cmake_minimum_required(VERSION 3.20)
project(ProxyMaze)

# Compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Include Conan-generated CMake information
#include(${CMAKE_BINARY_DIR}/build/Release/generators/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)

# Source files
set(SRCS
    main.cpp
    FileManager/FileManager.cpp
    Request/RequestService.cpp
    ProxyService/Debian/ProxyDebianService.cpp
    # Add any new source files here
)

# Executable name
set(TARGET app)

# Add executable target
add_executable(${TARGET} ${SRCS})
find_package(httplib REQUIRED)
find_package(jsoncpp REQUIRED)
# Link Conan libraries
target_link_libraries(${TARGET} httplib::httplib JsonCpp::JsonCpp)

# Clean rule to remove generated files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_clean.cmake
)

