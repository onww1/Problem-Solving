#include <cstdio>
#include <cstring>

const int MAX = 3e5 + 1;
int n, pa[MAX];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    int pu = _find(u);
    int pv = _find(v);
    if (pu != pv) 
        pa[pu] = pv;
}

int main(int argc, char *argv[]) {
    memset(pa, -1, sizeof(pa));
    scanf("%d", &n);
    for (int i = 2, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        _union(u, v);
    }
    int f = _find(1);
    for (int i = 2; i <= n; ++i) {
        int p = _find(i);
        if (f != p) return !printf("%d %d\n", 1, i);
    }
    return 0;
}