cmake_minimum_required(VERSION 3.3.2)
project(Component CXX)
find_package(HPX REQUIRED)
add_hpx_executable(Component SOURCES component.cpp)
