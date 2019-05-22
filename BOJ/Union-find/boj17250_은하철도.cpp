#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 1;
int N, M, G[MAX], pa[MAX];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

int _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        if (u > v) swap(u, v);
        pa[v] = u;
        G[u] += G[v];    
    }
    return G[u];
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) scanf("%d", G + i);
    memset(pa, -1, sizeof(pa));

    while (M--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", _union(u, v));
    }
    
    return 0;
}