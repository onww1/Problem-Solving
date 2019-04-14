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

const int MAX = 50;
const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M, K, Z, MAP[MAX][MAX], P[10];
bool visited[MAX][MAX];
vector <pii> virus;
queue <piii> Q;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", MAP[i] + j);
            if (MAP[i][j] == 2) {
                virus.push_back({i, j});
                MAP[i][j] = 0; K++;
            }
            if (!MAP[i][j]) Z++;
        }
    }

    Z -= M;
    for (int i = K - 1; i >= K - M; --i) P[i] = 1;

    int ans = INF;
    do {
        memset(visited, 0, sizeof(visited));
        while (!Q.empty()) Q.pop();

        for (int i = 0; i < K; ++i) if (P[i]) {
            Q.push({0, virus[i]});
            visited[virus[i].X][virus[i].Y] = true;
        }

        int cnt = 0, T = 0;
        while (!Q.empty()) {
            int t = Q.front().X;
            int r = Q.front().Y.X;
            int c = Q.front().Y.Y;
            Q.pop();

            T = max(T, t);
            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                if (!visited[dr][dc] && !MAP[dr][dc]) {
                    visited[dr][dc] = true;
                    Q.push({t + 1, {dr, dc}});
                    cnt++;
                }
            }
        }
        if (cnt == Z) ans = min(ans, T);
    } while (next_permutation(P, P + K));

    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}