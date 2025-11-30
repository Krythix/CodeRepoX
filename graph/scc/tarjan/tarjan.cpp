#include <iostream>
#include <vector>
#include <stack>
using namespace std;

constexpr size_t N=20;

int n, m;
vector<vector<int> > g;
stack<int> stk;
int inStack[N];
int visited[N];

int idx;
int dfn[N];
int low[N];

vector<vector<int> > result;

void init() {
    idx = 0;
    g.resize(N);
}

void readGraph() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
}

void tarjan(int u) {
    low[u] = dfn[u] = idx++;
    visited[u] = 1;
    stk.push(u);
    inStack[u] = 1;
    for(auto v : g[u]) {
        if(!visited[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(inStack[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int v;
        result.emplace_back();
        do {
            result.back().push_back(v = stk.top());
            stk.pop();
            inStack[v] = 0;
        } while(u != v);
    }
}

void printRes() {
    for(auto v : result) {
        for(auto p : v) {
            printf("%d ", p);
        }
        printf("\n");
    }
}

int main() {
    init();
    readGraph();
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            tarjan(i);
        }
    }
    printRes();

    return 0;
}