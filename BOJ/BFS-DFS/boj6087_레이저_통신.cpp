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
int N, M, DR = -1, DC = -1, visited[100][100][4];
char MAP[100][101];

int main(int argc, char *argv[]) {
    queue <piii> Q;
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j) {
            if (MAP[i][j] == 'C') {
                if (DR == -1) { DR = i, DC = j; }
                else {
                    for (int k = 0; k < 4; ++k) {
                        Q.push({k, {i, j}});
                        visited[i][j][k] = 1;
                    }
                }
            }
        }
    }

    while (!Q.empty()) {
        int d = Q.front().X;
        int r = Q.front().Y.X;
        int c = Q.front().Y.Y;
        Q.pop();

        for (int k = 3; k <= 5; ++k) {
            int dd = (d + k) % 4;
            int dr = r + move_r[dd];
            int dc = c + move_c[dd];
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
            if (MAP[dr][dc] != '*' && (!visited[dr][dc][dd] || (visited[dr][dc][dd] > visited[r][c][d] + (dd == d ? 0 : 1)))) {
                Q.push({dd, {dr, dc}});
                visited[dr][dc][dd] = visited[r][c][d] + (dd == d ? 0 : 1);
            }
        }
    }

    int mn = INF;
    for (int k = 0; k < 4; ++k) 
        if (visited[DR][DC][k]) 
            mn = min(mn, visited[DR][DC][k]);
    printf("%d\n", mn - 1);
    return 0;
}