#include "kruskal.hpp"

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Kruskal kru(n, m);
    kru.inputGraph();
    kru();

    return 0;
}