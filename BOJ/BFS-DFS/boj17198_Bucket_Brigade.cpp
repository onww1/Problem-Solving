#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N = 10, dist[10][10];
char MAP[10][11];

int main(int argc, char *argv[]) {
    queue <pii> Q;
    for (int i = 0; i < N; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j) {
            if (MAP[i][j] == 'L') {
                Q.push({i, j});
                dist[i][j] = 1;
            }
        }
    }

    while (!Q.empty()) {
        int r = Q.front().X;
        int c = Q.front().Y;
        Q.pop();

        if (MAP[r][c] == 'B') {
            printf("%d\n", dist[r][c] - 2);
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
            if (MAP[dr][dc] != 'R' && !dist[dr][dc]) {
                dist[dr][dc] = dist[r][c] + 1;
                Q.push({dr, dc});
            }
        }
    }

    return 0;
}