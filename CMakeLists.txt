cmake_minimum_required(VERSION 3.8)
project(compProg)

set(CMAKE_CXX_STANDARD 14)

AUX_SOURCE_DIRECTORY(mylib MYLIB)
set(SOURCE_FILES main.cpp ${MYLIB})
add_executable(compProg ${SOURCE_FILES})