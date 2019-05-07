#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
int N, M, u, v, w, mn, dist[1005], pa[1005];
vector <pii> edges[1005], min_path;

int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0, pa[1] = -1;
    pq.push({0, 1});

    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        if (dist[cur.Y] < cur.X) continue;

        for (pii &next : edges[cur.Y]) {
            if ((cur.Y == u && next.X == v) || (cur.Y == v && next.X == u)) continue;
            if (dist[next.X] > cur.X + next.Y) {
                dist[next.X] = cur.X + next.Y;
                pa[next.X] = cur.Y;
                pq.push({dist[next.X], next.X});
            }
        }
    }

    return dist[N];
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    mn = dijkstra();
    for (int cur = N; cur != 1; cur = pa[cur]) 
        min_path.push_back({cur, pa[cur]});

    int ans = 0;
    for (pii &p : min_path) {
        u = p.X, v = p.Y;
        ans = max(ans, dijkstra());
    }

    printf("%d\n", ans == INF ? -1 : ans - mn);
    return 0;
}