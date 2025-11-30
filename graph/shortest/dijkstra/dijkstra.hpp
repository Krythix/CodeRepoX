#pragma once

#include <vector>
#include <queue>

struct Link {
    Link(int v, int w) : v(v), w(w) {}
    int v;
    int w;
};

class Dijkstra {
public:
    Dijkstra();
    void InputGraph();
    void operator()(int x);
    std::vector<int> getResult();

private:
    int n, m;
    std::vector<std::vector<Link> > graph;
    std::vector<int> mark;
    std::vector<int> dist;
    // pair<int, int>
    //      distance, node
    typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq_t;
    pq_t q;
};