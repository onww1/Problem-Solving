#include <algorithm>
#include <functional>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 1e5;
int N, pa[MAX + 1], G[MAX + 1];
piii edges[MAX];

int _find(int a) {
    if (pa[a] == 0) return a;
    return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
    a = _find(a), b = _find(b);
    if (a == b) return;
    G[a] = G[a] + G[b] + 1;
    pa[b] = a;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, u, v, w; i < N; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i - 1] = {w, {u, v}};
    }
    sort(edges, edges + N - 1, greater<piii>());

    ll ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        int pu = G[_find(edges[i].Y.X)] + 1;
        int pv = G[_find(edges[i].Y.Y)] + 1;
        ans += (ll)pu * pv * edges[i].X;
        _union(edges[i].Y.X, edges[i].Y.Y);
    }

    printf("%lld\n", ans);
    return 0;
}