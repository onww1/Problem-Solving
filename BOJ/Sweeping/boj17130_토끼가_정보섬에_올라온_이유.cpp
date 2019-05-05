#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int move_r[] = {-1, 0, 1};
int N, M, DP[1000][1000], SR, SC, ans = -1;
char MAP[1000][1001];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j) {
            if (MAP[i][j] == 'R') 
                SR = i, SC = j;
        }
    }

    memset(DP, -1, sizeof(DP));
    DP[SR][SC] = 0;
    for (int j = SC; j < M - 1; ++j) {
        for (int i = 0; i < N; ++i) {
            if (DP[i][j] != -1) {
                for (int k = 0; k < 3; ++k) {
                    int dr = i + move_r[k];
                    if (dr < 0 || dr >= N) continue;
                    switch (MAP[dr][j + 1]) {
                        case 'C':
                            DP[dr][j + 1] = max(DP[dr][j + 1], DP[i][j] + 1);
                            break;
                        case '#':
                            break;
                        case 'O':
                            DP[dr][j + 1] = max(DP[dr][j + 1], DP[i][j]);
                            ans = max(ans, DP[dr][j + 1]);
                            break;
                        case '.':
                            DP[dr][j + 1] = max(DP[dr][j + 1], DP[i][j]);
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}