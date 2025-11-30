#include "dijkstra.hpp"
#include <iostream>
using namespace std;

int main() {
    Dijkstra d;
    d.InputGraph();
    d(1);
    auto r = d.getResult();
    for(auto e : r) {
        cout << e << " ";
    }
}