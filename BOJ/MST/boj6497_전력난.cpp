#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 2e5 + 1;
int M, N, ans, pa[MAX];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) pa[v] = u;
}

int main(int argc, char *argv[]) {
    while (1) {
        scanf("%d %d", &N, &M);
        if (!N && !M) break;
        memset(pa, -1, sizeof(pa));
        
        ans = 0;
        priority_queue <piii, vector<piii>, greater<piii>> pq;
        for (int i = 0, x, y, z; i < M; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            pq.push({z, {x, y}});
            ans += z;
        }

        int cnt = 0;
        while (cnt < N - 1 && !pq.empty()) {
            int u = pq.top().Y.X;
            int v = pq.top().Y.Y;
            int w = pq.top().X;
            pq.pop();

            int pu = _find(u), pv = _find(v);
            if (pu == pv) continue;

            cnt++;
            ans -= w;
            _union(u, v);
        }

        printf("%d\n", ans);
    }
    return 0;
}