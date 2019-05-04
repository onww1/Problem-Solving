#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M;
char MAP[3000][3001];
bool visited[3000][3000];

int main(int argc, char *argv[]) {
    queue <piii> Q;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j) {
            if (MAP[i][j] == '2') {
                Q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    while (!Q.empty()) {
        int T = Q.front().X;
        int r = Q.front().Y.X;
        int c = Q.front().Y.Y;
        Q.pop();

        if (MAP[r][c] > '2') return !printf("TAK\n%d\n", T);

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
            if (MAP[dr][dc] != '1' && !visited[dr][dc]) {
                Q.push({T + 1, {dr, dc}});
                visited[dr][dc] = true;
            }
        }
    }

    puts("NIE");
    return 0;
}