#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 125;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, MAP[MAX][MAX], dist[MAX * MAX];
priority_queue <pii, vector<pii>, greater<pii>> pq; 

int main(int argc, char *argv[]) {
    for (int tc = 1; 1; tc++) {
        scanf("%d", &N);
        if (!N) break;

        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", &MAP[i][j]);
        memset(dist, 0x3f, sizeof(dist)); dist[0] = MAP[0][0];
        while (!pq.empty()) pq.pop();
        pq.push({dist[0], 0});

        while (!pq.empty()) {
            int cost = pq.top().X;
            int r = pq.top().Y / N;
            int c = pq.top().Y % N;
            pq.pop();

            if (dist[r * N + c] < cost) continue;
            if (r == N - 1 && c == N - 1) break;

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                if (dist[dr * N + dc] > dist[r * N + c] + MAP[dr][dc]) {
                    dist[dr * N + dc] = dist[r * N + c] + MAP[dr][dc];
                    pq.push({dist[dr * N + dc], dr * N + dc});
                }
            }
        }

        printf("Problem %d: %d\n", tc, dist[N * N - 1]);
    }

    return 0;
}