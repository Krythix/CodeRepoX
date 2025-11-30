#include "dijkstra.hpp"
#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;

Dijkstra::Dijkstra() {}

void Dijkstra::InputGraph() {
    scanf("%d%d", &n, &m);
    graph.resize(n+1);

    for(int i=0; i<m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        graph[a].push_back(Link{b, w});
    }
}

void Dijkstra::operator()(int x) {
    dist = vector<int>(n+1, INT_MAX/2);
    mark = vector<int>(n+1, 0);
    q = pq_t();

    dist[x] = 0;
    q.emplace(0, x);

    while(!q.empty()) {
        int node = q.top().second;
        q.pop();
        mark[node] = 1;
        for(auto l : graph[node]) {
            if(!mark[l.v] && dist[l.v] > l.w+dist[node]) {
                q.emplace(l.w+dist[node], l.v);
                dist[l.v] = l.w+dist[node];
            }
        }
    }
}

std::vector<int> Dijkstra::getResult() {
    return dist;
}