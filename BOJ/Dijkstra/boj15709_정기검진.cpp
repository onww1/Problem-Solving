#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;

const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
int N, M, B, K, Q;
ll dist[100][20101];
vector <pii> edges[20101];

void dijkstra(int bridge) {
    memset(dist[bridge], 0x3f, sizeof(dist[bridge]));
    dist[bridge][N + M + bridge + 1] = 0;
    priority_queue <pli, vector<pli>, greater<pli>> pq;
    pq.push({dist[bridge][N + M + bridge + 1], N + M + bridge + 1});

    while (!pq.empty()) {
        pli cur = pq.top(); pq.pop();
        if (cur.X > dist[bridge][cur.Y]) continue;
        for (pii edge : edges[cur.Y]) {
            if (dist[bridge][edge.X] > cur.X + edge.Y) {
                dist[bridge][edge.X] = cur.X + edge.Y;
                pq.push({dist[bridge][edge.X], edge.X});
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d %d", &N, &M, &B, &K, &Q);
    for (int i = 0, u, v, k; i < K; ++i) {
        scanf("%d %d %d", &u, &v, &k);
        edges[u].push_back({v, k});
        edges[v].push_back({u, k});
    }

    for (int bridge = 0; bridge < B; ++bridge) dijkstra(bridge);

    int u, v;
    while (Q--) {
        scanf("%d %d", &u, &v);
        ll ans = LL_INF;
        for (int bridge = 0; bridge < B; ++bridge) 
            ans = min(ans, dist[bridge][u] + dist[bridge][v]);
        printf("%lld\n", ans == LL_INF ? -1 : ans);
    }

    return 0;
}