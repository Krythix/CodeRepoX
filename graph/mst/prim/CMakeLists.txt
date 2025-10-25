cmake_minimum_required(VERSION 3.10)

project(prim)


add_executable(prim
    prim.cpp
    test.cpp
)

target_include_directories(prim PRIVATE
    ../../graph
)
