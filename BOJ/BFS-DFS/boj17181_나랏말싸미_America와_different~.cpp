#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M, MAP[50][50], visited[50][50][3];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", MAP[i] + j);
            MAP[i][j] = (MAP[i][j] > 13);
        }
    }
  
    if (MAP[0][0]) return !printf("BAD\n");
    queue <piii> Q;
    Q.push({0, {0, 0}});
    visited[0][0][0] = 1;

    while (!Q.empty()) {
        int stat = Q.front().X;
        int r = Q.front().Y.X;
        int c = Q.front().Y.Y;
        Q.pop();

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
            if (stat == 0 && MAP[dr][dc]) {
                if (!visited[dr][dc][1] || visited[dr][dc][1] > visited[r][c][0]) {
                    visited[dr][dc][1] = visited[r][c][0];
                    Q.push({1, {dr, dc}});
                }
            }
            else if (stat == 1 && !MAP[dr][dc]) {
                if (!visited[dr][dc][2] || visited[dr][dc][2] > visited[r][c][1]) {
                    visited[dr][dc][2] = visited[r][c][1];
                    Q.push({2, {dr, dc}});
                }
                if (!visited[dr][dc][0] || visited[dr][dc][0] > visited[r][c][1] + 1) {
                    visited[dr][dc][0] = visited[r][c][1] + 1;
                    Q.push({0, {dr, dc}});
                }
            }
            else if (stat == 2 && !MAP[dr][dc]) {
                if (!visited[dr][dc][0] || visited[dr][dc][0] > visited[r][c][2] + 1) {
                    visited[dr][dc][0] = visited[r][c][2] + 1;
                    Q.push({0, {dr, dc}});
                }
            }
        }
    }

    int ans = INF;
    if (MAP[N - 1][M - 1]) ans = visited[N - 1][M - 1][1];
    else ans = visited[N - 1][M - 1][2];

    if (ans == 0) printf("BAD\n");
    else printf("%d\n", ans);
    return 0;
}