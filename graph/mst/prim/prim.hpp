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
    int * mark;
    int * lowcost;
    int * vex;
};
