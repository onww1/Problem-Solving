#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M, W, B;
char MAP[100][101];
bool visited[100][100];

int main(int argc, char *argv[]) {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                queue <pii> Q;
                Q.push({i, j});
                visited[i][j] = true;
                int cnt = 0;
                char C = MAP[i][j];

                while (!Q.empty()) {
                    int r = Q.front().X;
                    int c = Q.front().Y;
                    Q.pop();

                    cnt++;

                    for (int k = 0; k < 4; ++k) {
                        int dr = r + move_r[k];
                        int dc = c + move_c[k];
                        if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
                        if (!visited[dr][dc] && MAP[dr][dc] == C) {
                            visited[dr][dc] = true;
                            Q.push({dr, dc});
                        }
                    }
                }

                if (C == 'W') W += cnt * cnt;
                else B += cnt * cnt;
            }
        }
    }

    printf("%d %d\n", W, B);
    return 0;
}