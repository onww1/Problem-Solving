#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e3;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M, K, SR, SC, DR, DC, dist[MAX][MAX];
char MAP[MAX][MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);
    scanf("%d %d %d %d", &SR, &SC, &DR, &DC);
    SR--, SC--, DR--, DC--;

    memset(dist, -1, sizeof(dist)); 
    
    queue <pii> Q; 
    Q.push({SR, SC});
    dist[SR][SC] = 0;
    
    while (!Q.empty()) {
        int r = Q.front().X;
        int c = Q.front().Y;
        Q.pop();

        for (int k = 0; k < 4; ++k) {
            for (int x = 1; x <= K; ++x) {
                int dr = r + move_r[k] * x;
                int dc = c + move_c[k] * x;
                if (dr < 0 || dr >= N || dc < 0 || dc >= M || MAP[dr][dc] == '#') break;
                if (dist[dr][dc] != -1) {
                    if (dist[dr][dc] <= dist[r][c]) break;
                    else continue;
                }
                dist[dr][dc] = dist[r][c] + 1;
                Q.push({dr, dc});
            }
        }
    }

    printf("%d\n", dist[DR][DC]);
    return 0;
}