project(prim)

add_executable(prim
    prim.cpp
    test.cpp
)

target_include_directories(prim PRIVATE
    ../../graph
)
