#include "kruskal.hpp"
#include <algorithm>

Kruskal::Kruskal(int n, int m) : n(n), m(m), dsunion(n+1){

}

void Kruskal::inputGraph() {
    for(int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
    }
}

void Kruskal::operator()() {
    std::sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b){
        return std::get<2>(a) < std::get<2>(b);
    });
    for(int i=0; i<m; i++) {
        int a = std::get<0>(edges[i]);
        int b = std::get<1>(edges[i]);
        if(dsunion.find(a) == dsunion.find(b)) continue;
        else {
            mst.push_back(edges[i]);
            dsunion.merge(a, b);
        }
    }
}

std::vector<Kruskal::edge_t>& Kruskal::getMst() {
    return mst;
}
