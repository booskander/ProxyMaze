cmake_minimum_required(VERSION 3.20)
project(YourProgram)

# Compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Source files
set(SRCS
    main.cpp
    FileManager/FileManager.cpp
    Request/RequestService.cpp
    ProxyService/Debian/ProxyDebianService.cpp
    # Add any new source files here
)

# Executable name
set(TARGET exec)

# Path to the jsoncpp library
set(JSONCPP_LIB /usr/lib/x86_64-linux-gnu/libjsoncpp.so)

# Add executable target
add_executable(${TARGET} ${SRCS})

# Link jsoncpp library
target_link_libraries(${TARGET} ${JSONCPP_LIB})

# Clean rule to remove generated files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_clean.cmake
)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/cmake_clean.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/${TARGET}.dir
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/_deps
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/cmake_install.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/_deps
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Cleaning generated files"
)
