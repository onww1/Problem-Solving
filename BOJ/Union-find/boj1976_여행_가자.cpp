#include <cstdio>
#include <cstring>
int n, m, pa[201];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

 void _union(int u, int v) {
    int pu = _find(u);
    int pv = _find(v);
    if (pu != pv) pa[pu] = pv;
 }

int main(int argc, char *argv[]) {
    memset(pa, -1, sizeof(pa));
    scanf("%d %d", &n, &m);

    for (int i = 1, a; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a);
            if (a) _union(i, j);
        }
    }

    bool flag = true;
    int pr = 0, b = 0;
    scanf("%d", &pr);
    for (int i = 0; i < m - 1; ++i) {
        scanf("%d", &b);
        if (_find(pr) != _find(b)) flag = false;
        pr = b;
    }

    puts(flag ? "YES" : "NO");
    return 0;
}