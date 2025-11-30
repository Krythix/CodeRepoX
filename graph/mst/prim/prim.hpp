#pragma once

#include "graph_adjacent.hpp"

class Prim {
public:
    Prim(int n, int m);
    ~Prim();
    MyGraph::Graph<int>& getGraph();
    void init();
    void operator()();
    const int * const getpath();

private:
    MyGraph::Graph<int> graph;
    int n, m;
    // if a vertex is contained in current mst
    int * mark;
    // lowest length to each vertex
    int * lowcost;
    // record path
    int * vex;
};
