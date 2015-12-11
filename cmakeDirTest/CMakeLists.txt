cmake_minimum_required(VERSION 3.0.0)

project(cmakeDirTest)

set(cmakeDirTest_VERSION_MAJOR 1)
set(cmakeDirTest_VERSION_MINOR 0)

add_subdirectory(libFile)

add_executable(cmakeDirTest main.cpp)
target_link_libraries(cmakeDirTest libFile)