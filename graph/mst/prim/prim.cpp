#include <cassert>
#include "prim.hpp"

using namespace MyGraph;

#define N 10000
//#define INT_MAX 0x7fffffff
#define INF 0x3f3f3f3f

Prim::Prim(int n, int m) : graph(n), n(n), m(m){
    mark = new int[n];
    lowcost = new int[n];
    vex = new int[n];
}

Prim::~Prim() {
    delete [] mark;
    delete [] lowcost;
    delete [] vex;

}

void Prim::init() {
    assert (m>=1);
    inputNonDirGraph(graph, m);
    for(int i=0; i<n; i++) {
        mark[i] = 0;
        lowcost[i] = INT_MAX;
        vex[i] = -1;
    }

    mark[0] = 1;
    lowcost[0] = 0;
    for(auto p : graph[0].adjacents) {
        lowcost[p.v] = p.weight;
        vex[p.v] = p.u;
    }
}

void Prim::operator()() {
    // add n-1 edges
    for(int j=1; j<n; j++) {
        int minEW = INT_MAX;
        int u;
        for(int i=0; i<n; i++) {
            if(mark[i] == 0 && lowcost[i] < minEW) {
                minEW = lowcost[i];
                u = i;
            }
        }
        mark[u] = 1;
        for(auto p : graph[u].adjacents) {
            int v = p.v;
            if(mark[v] == 0 && p.weight < lowcost[v]) {
                lowcost[v] = p.weight;
                vex[v] = u;
            }
        }
    }
}

const int * const Prim::getpath() {
    return vex;
}

Graph<int>& Prim::getGraph() {
    return graph;
}
