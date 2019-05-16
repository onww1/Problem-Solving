#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 1e4 + 1;
int N, M, T, ans, pa[MAX];
priority_queue <piii, vector<piii>, greater<piii>> pq;

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) pa[u] = v;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &T);
    for (int i = 0, u, v, w; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        pq.push({w, {u, v}});
    }

    memset(pa, -1, sizeof(pa));
    while (!pq.empty()) {
        int w = pq.top().X;
        int u = pq.top().Y.X;
        int v = pq.top().Y.Y;
        pq.pop();

        int pa_u = _find(u);
        int pa_v = _find(v);
        if (pa_u == pa_v) continue;

        ans += w;
        _union(u, v);
    }

    ans += (N - 2) * (N - 1) / 2 * T;
    printf("%d\n", ans);
    return 0;
}