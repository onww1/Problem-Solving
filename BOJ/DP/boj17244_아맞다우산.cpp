#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, M, NN, SR, SC, dist[7][7], DP[6][1 << 6];
char MAP[50][51], chk[50][50];
vector <pii> V;
map <pii, int> idx;

int TSP(int node, int visited) {
    if (visited == (1 << (NN - 1)) - 1)
        return dist[node][0];

    int &ret = DP[node - 1][visited];
    if (~ret) return ret;
    ret = INF;

    for (int i = 2; i < NN; ++i) {
        if (visited & (1 << (i - 1))) continue;
        ret = min(ret, dist[node][i] + TSP(i, visited | (1 << (i - 1))));
    }

    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j)
            if (MAP[i][j] != '.' && MAP[i][j] != '#')
                V.push_back({i, j});
    }
    NN = (int)V.size();

    sort(V.begin(), V.end(), [](const pii& a, const pii& b) {
        return MAP[a.X][a.Y] < MAP[b.X][b.Y];
    });

    for (int i = 0; i < NN; ++i) 
        idx[V[i]] = i;

    for (int i = 0; i < NN; ++i) {
        memset(chk, 0, sizeof(chk));
        queue <piii> Q;
        Q.push({0, V[i]});
        chk[V[i].X][V[i].Y] = 1;

        while (!Q.empty()) {
            int d = Q.front().X;
            int r = Q.front().Y.X;
            int c = Q.front().Y.Y;
            Q.pop();

            if ('A' <= MAP[r][c] && MAP[r][c] <= 'Z')
                dist[i][idx[pii(r, c)]] = d;

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
                if (!chk[dr][dc] && MAP[dr][dc] != '#') {
                    Q.push({d + 1, {dr, dc}});
                    chk[dr][dc] = 1;
                }
            }
        }
    }

    memset(DP, -1, sizeof(DP));
    printf("%d\n", TSP(1, 1));
    return 0;
}