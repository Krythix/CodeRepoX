#include "prim.hpp"

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Prim prim(n, m);
    prim.init();
    prim();
    auto res = prim.getpath();

    for(int i=0; i<n; i++) {
        printf("%d %d\n", i, res[i]);
    }

    return 0;
}
