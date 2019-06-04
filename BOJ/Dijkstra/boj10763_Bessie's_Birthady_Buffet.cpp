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
int N, E, Q[1001], DP[1001], dist[1001];
vector <int> edges[1001];
priority_queue <pii, vector<pii>, greater<pii>> inc;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &E);
    for (int i = 1, e, v; i <= N; ++i) {
        scanf("%d %d", Q + i, &e);
        inc.push({Q[i], i});
        for (int j = 0; j < e; ++j) {
            scanf("%d", &v);
            edges[i].push_back(v);
        }
    }

    int ans = 0;
    while (!inc.empty()) {
        int src = inc.top().Y;
        int val = inc.top().X;
        inc.pop();
        DP[src] = max(DP[src], val);
        ans = max(ans, DP[src]);

        priority_queue <pii, vector<pii>, greater<pii>> pq;
        memset(dist, 0x3f, sizeof(dist)); dist[src] = 0;
        pq.push({dist[src], src});

        while (!pq.empty()) {
            int d = pq.top().X;
            int node = pq.top().Y;
            pq.pop();

            if (dist[node] < d) continue;

            for (int next : edges[node]) {
                if (dist[next] > d + 1) {
                    dist[next] = d + 1;
                    pq.push({dist[next], next});
                }
            }
        }

        for (int i = 1; i <= N; ++i) {
            if (i == src || Q[i] <= Q[src] || dist[i] == INF) continue;
            DP[i] = max(DP[i], DP[src] + Q[i] - E * dist[i]);
        }
    }

    printf("%d\n", ans);
    return 0;
}