#pragma once
#include <vector>

class dsu {
public:
    dsu(int n) : n(n), father(n){
        for(int i=0; i<n; i++) {
            father[i] = i;
        }
    };
    int find(int x) {
        if(x == father[x]) return x;
        return father[x] = find(father[x]);
    }
    void merge(int x, int y) {
        father[find(x)] = find(y);
    }

private:
    int n;
    std::vector<int> father;
};