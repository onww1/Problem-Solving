#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
int N, K, D[10][10], P[10];
int dist[10][10];

void dijkstra(int src) {
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    memset(dist[src], 0x3f, sizeof(dist[src]));
    dist[src][src] = 0; pq.push({0, src});

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        if (cur.X > dist[src][cur.Y]) continue;

        for (int i = 0; i < N; ++i) {
            if (cur.Y == i) continue;
            if (dist[src][i] > D[cur.Y][i] + dist[src][cur.Y]) {
                dist[src][i] = D[cur.Y][i] + dist[src][cur.Y];
                pq.push({dist[src][i], i});
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", D[i] + j);
        }
    }

    for (int i = 0; i < N; ++i) dijkstra(i);
    P[0] = K;
    for (int i = 1; i < N; ++i) {
        if (i <= K) P[i] = i - 1;
        else P[i] = i;
    }

    int mn = INF;
    do {
        int cost = 0;
        for (int i = 0; i < N - 1; ++i) 
            cost += dist[P[i]][P[i + 1]];
        mn = min(mn, cost);
    } while (next_permutation(P + 1, P + N));

    printf("%d\n", mn);
    return 0;
}