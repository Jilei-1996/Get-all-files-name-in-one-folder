cmake_minimum_required(VERSION 2.6)
project(getdoc)

add_executable(getdoc main.cpp)

install(TARGETS getdoc RUNTIME DESTINATION bin)
