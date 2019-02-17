cmake_minimum_required(VERSION 3.12)
project(segyParser)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(segyParser main.cpp ./include/Segy.h 
./include/BinaryHeader.h ./src/Segy.cpp ./include/TraceHeader.h 
./include/utils/endianConversion.h ./src/printUtil.cpp)
