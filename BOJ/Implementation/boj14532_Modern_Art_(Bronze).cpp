#include <algorithm>
#include <cstdio>
using namespace std;

int N, pos[10][2][2];
char in[10][11];
bool chk[10];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < 10; ++i) {
        pos[i][0][0] = pos[i][0][1] = 100;
        pos[i][1][0] = pos[i][1][1] = -100;
    }

    for (int i = 0; i < N; ++i) {
        scanf(" %s", in[i]);
        for (int j = 0; in[i][j]; ++j) {
            pos[in[i][j] - '0'][0][0] = min(pos[in[i][j] - '0'][0][0], i);
            pos[in[i][j] - '0'][0][1] = min(pos[in[i][j] - '0'][0][1], j);
            pos[in[i][j] - '0'][1][0] = max(pos[in[i][j] - '0'][1][0], i);
            pos[in[i][j] - '0'][1][1] = max(pos[in[i][j] - '0'][1][1], j);
        }
    }

    for (int i = 1; i < 10; ++i) {
        if (pos[i][0][0] == 100) continue;
        for (int r = pos[i][0][0]; r <= pos[i][1][0]; ++r) {
            for (int c = pos[i][0][1]; c <= pos[i][1][1]; ++c) {
                if (in[r][c] - '0' != i) {
                    chk[in[r][c] - '0'] = true;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i < 10; ++i) {
        if (pos[i][0][0] == 100) continue;
        if (!chk[i]) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}