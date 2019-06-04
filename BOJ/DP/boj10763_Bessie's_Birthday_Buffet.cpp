#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, E, Q[1001], DP[1001];
vector <int> edges[1001];
pii P[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &E);
    for (int i = 1, e, v; i <= N; ++i) {
        scanf("%d %d", Q + i, &e);
        P[i] = {Q[i], i};
        for (int j = 0; j < e; ++j) {
            scanf("%d", &v);
            edges[i].push_back(v);
        }
    }

    sort(P + 1, P + N + 1);

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int src = P[i].Y;
        DP[src] = max(DP[src], P[i].X);
        ans = max(ans, DP[src]);

        int dist[1001]{};
        dist[src] = 1;
        queue <int> qu; qu.push(src);

        while (!qu.empty()) {
            int node = qu.front(); qu.pop();
            for (int next : edges[node]) {
                if (dist[next]) continue;
                dist[next] = dist[node] + 1;
                qu.push(next);
            }
        }

        for (int j = 1; j <= N; ++j) {
            if (j == src || Q[j] <= Q[src] || !dist[j]) continue;
            DP[j] = max(DP[j], DP[src] + Q[j] - E * (dist[j] - 1));
        }
    }

    printf("%d\n", ans);
    return 0;
}