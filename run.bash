#!/bin/bash

# Check if the script is run as root, if not, exit
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 
   exit 1
fi

# Change directory to your executable directory
cd build/ || exit

cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build . 
# Run your application with sudo
sudo ./exec

# If your application requires any arguments, you can pass them after './exec' in the above command
# For example:
# sudo ./exec arg1 arg2
