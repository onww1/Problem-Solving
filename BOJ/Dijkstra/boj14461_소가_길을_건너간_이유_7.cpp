#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, T, A[100][100], dist[3][100][100];
priority_queue <piii, vector<piii>, greater<piii>> pq;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &T);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", A[i] + j);
    memset(dist, 0x3f, sizeof(dist));

    dist[0][0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        int d = pq.top().X;
        int r = pq.top().Y.X / N;
        int c = pq.top().Y.X % N;
        int t = pq.top().Y.Y;
        pq.pop();

        if (dist[t][r][c] < d) continue;

        int dt = (t + 1) % 3;
        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
            if (dist[dt][dr][dc] > d + T + (dt ? 0 : A[dr][dc])) {
                dist[dt][dr][dc] = d + T + (dt ? 0 : A[dr][dc]);
                pq.push({dist[dt][dr][dc], {dr * N + dc, dt}});
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 3; ++i) ans = min(ans, dist[i][N - 1][N - 1]);
    printf("%d\n", ans);
    return 0;
}