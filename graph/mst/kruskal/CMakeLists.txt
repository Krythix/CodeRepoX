project(kruskal)

add_executable(kruskal
    kruskal.cpp
    test.cpp
)

target_include_directories(kruskal PRIVATE
    ../../graph
    ../../../tree/dsu
)

