cmake_minimum_required(VERSION 3.5)
project(bsdsockets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(demo main.cc socket.cc socket.h address.cc address.cc)
