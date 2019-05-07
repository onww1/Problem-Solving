#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;

const int MAX = 1e5;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
int N, M, D, E, H[MAX + 1];
ll dist[2][MAX + 1];
vector <pii> edges[MAX + 1];

void dijkstra(int src, int idx) {
    priority_queue <pli, vector<pli>, greater<pli>> pq;
    dist[idx][src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        pli cur = pq.top(); pq.pop();
        if (dist[idx][cur.Y] < cur.X) continue;

        for (pii &next : edges[cur.Y]) {
            if (H[cur.Y] < H[next.X] && dist[idx][next.X] > cur.X + next.Y) {
                dist[idx][next.X] = cur.X + next.Y;
                pq.push({dist[idx][next.X], next.X});
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d", &N, &M, &D, &E);
    for (int i = 1; i <= N; ++i) scanf("%d", H + i);
    for (int i = 0, a, b, d; i < M; ++i) {
        scanf("%d %d %d", &a, &b, &d);
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    memset(dist, 0x3f, sizeof(dist));
    dijkstra(1, 0); dijkstra(N, 1);

    ll mx = -LL_INF;
    for (int i = 2; i < N; ++i) {
        if (dist[0][i] != LL_INF && dist[1][i] != LL_INF) {
            mx = max(mx, 1LL * H[i] * E - (dist[0][i] + dist[1][i]) * D);
        }
    }

    if (mx == -LL_INF) puts("Impossible");
    else printf("%lld\n", mx);
    return 0;
}