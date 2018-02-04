#!/bin/bash

rm CMakeFiles/ CMakeCache* cmake_* Makefile -r 2> /dev/null

LIBS=$(ls | find / -name  libcurl.a  2>/dev/null)
INCL=$(ls | find / -name curlpp 2>/dev/null)

#update CMakeLists.txt
sed -i "/include_directories/c\include_directories\(include ${INCL::-6}\)" CMakeLists.txt
sed -i "/link_directories/c\link_directories\(${LIBS::-9}\)" CMakeLists.txt

cmake -G "Unix Makefiles"
make

rm -r CMake* cmake* Make* include/ src/

./sir & 
exit
