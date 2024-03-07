# Makefile for YourProgram

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall

# Source files
SRCS = main.cpp FileManager/FileManager.cpp Request/RequestService.cpp ProxyService/Debian/ProxyDebianService.cpp # List all your source files

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = exec

# Path to the jsoncpp library
JSONCPP_LIB = /usr/lib/x86_64-linux-gnu/libjsoncpp.so

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -L$(JSONCPP_LIB) -o $(TARGET) $(OBJS) -ljsoncpp

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)
