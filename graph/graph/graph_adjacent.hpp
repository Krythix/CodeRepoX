#pragma once

#include <vector>
#include <cstdio>
#include <climits>

namespace MyGraph {

struct Link {
    int u, v;
    int weight;
};

template <typename T>
struct Vertex {
    // T value;
    std::vector<Link> adjacents; // index of adjacent node
};

template <typename T>
class Graph {
friend void inputGraph(Graph<T>& graph);
friend void inputNonDirGraph(Graph<T>& graph);
public:
    Graph(int n) : nodes(n) {};
    Vertex<T>& operator[](int index) {return nodes[index];};
    size_t size() {return nodes.size();}
private:
    std::vector<Vertex<T> > nodes;
};

/*
 * @brief: read n edges to graph
 * a, b: index of vertex which link by edge
 * w: weight
 */
template<typename T>
void inputGraph(Graph<T>& graph, int n) {
    for(int i=0; i<n; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        Link newLink{.u=a, .v=b, .weight=w};
        graph[a].adjacents.push_back(newLink);
        // graph[a].value = a;
    }
}

template<typename T>
void inputNonDirGraph(Graph<T>& graph, int n) {
    for(int i=0; i<n; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        Link newLink{.u=a, .v=b, .weight=w};
        graph[a].adjacents.push_back(newLink);
        newLink.u = b; newLink.v = a;
        graph[b].adjacents.push_back(newLink);
        // graph[a].value = a;
    }
}

};
