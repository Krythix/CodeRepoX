#include "graph_adjacent.hpp"
#include "dsu.hpp"
#include <tuple>

class Kruskal {
typedef std::tuple<int, int, int> edge_t;
public:
    Kruskal(int n, int m);
    void inputGraph();
    void operator()();
    std::vector<edge_t>& getMst();

private:
    int n, m;
    std::vector<edge_t> edges;
    std::vector<edge_t> mst;
    dsu dsunion;
};