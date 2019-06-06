#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, pii> pi;

const int move_r[] = {-1, 1, 0, 0};
const int move_c[] = {0, 0, -1, 1};
int N, M, L, R, ans;
char MAP[1000][1001];
bool visited[1000][1000];
pii LR[1000][1000];
queue <pi> Q;

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d", &N, &M, &L, &R);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; Q.empty() && j < M; ++j) 
            if (MAP[i][j] == '2') {
                Q.push({{i, j}, {L, R}});
                visited[i][j] = 1;
                LR[i][j] = {L, R};
                ans++;
            }
    }

    while (!Q.empty()) {
        int row = Q.front().X.X;
        int col = Q.front().X.Y;
        int l = Q.front().Y.X;
        int r = Q.front().Y.Y;
        Q.pop();

        for (int k = 0; k < 4; ++k) {
            int dr = row + move_r[k];
            int dc = col + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
            if (MAP[dr][dc] == '0' && l + (k != 2) > 0 && r + (k != 3) > 0 && (!visited[dr][dc] || LR[dr][dc].X < l - (k == 2) || LR[dr][dc].Y < r - (k == 3))) {
                Q.push({{dr, dc}, {l - (k == 2), r - (k == 3)}});
                if (!visited[dr][dc]) ans++;
                visited[dr][dc] = true;
                LR[dr][dc].X = max(LR[dr][dc].X, l - (k == 2));
                LR[dr][dc].Y = max(LR[dr][dc].Y, r - (k == 3));
            }
        }
    }  

    printf("%d\n", ans);
    return 0;
}