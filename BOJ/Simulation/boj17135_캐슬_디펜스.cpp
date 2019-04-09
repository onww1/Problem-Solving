#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<pii, pii> piiii;

const int MAX = 15;
const int move_r[] = {0, 1, 0};
const int move_c[] = {-1, 0, 1};
int N, M, D, mx, org[MAX + 1][MAX], MAP[MAX + 1][MAX], P[MAX];
bool visited[MAX + 1][MAX][3];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &D);
    for (int i = N; i > 0; --i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &org[i][j]);
        }
    }

    for (int i = M - 1; i >= M - 3; --i) P[i] = 1;

    do {
        int C = 0;
        for (int i = 1; i <= N; ++i) for (int j = 0; j < M; ++j) MAP[i][j] = org[i][j];
        for (int i = 0; i < N; ++i) {
            memset(visited, 0, sizeof(visited));
            queue <piiii> Q;
            for (int j = 0, who = 0; j < M; ++j) if (P[j]) {
                Q.push({{i, j}, {who, 0}});
                visited[i][j][who++] = true;
                if (who == 3) break;
            }

            vector <pii> target;
            bool chk[3]{};
            while (!Q.empty()) {
                int r = Q.front().X.X;
                int c = Q.front().X.Y;
                int who = Q.front().Y.X;
                int dist = Q.front().Y.Y;
                Q.pop();

                if (chk[who] || dist >= D) continue;

                for (int k = 0; k < 3; ++k) {
                    int dr = r + move_r[k];
                    int dc = c + move_c[k];

                    if (dr <= i || dr > N || dc < 0 || dc >= M) continue;
                    if (!visited[dr][dc][who]) {
                        visited[dr][dc][who] = true;
                        if (MAP[dr][dc]) {
                            target.push_back({dr, dc});
                            if (MAP[dr][dc] == 1) C++;
                            MAP[dr][dc]++;
                            chk[who] = true;
                            break;
                        }
                        else Q.push({{dr, dc}, {who, dist + 1}});
                    }
                }
            }

            for (pii v : target) MAP[v.X][v.Y] = 0;
        }
        mx = max(mx, C);
    } while (next_permutation(P, P + M));

    printf("%d\n", mx);
    return 0;
}