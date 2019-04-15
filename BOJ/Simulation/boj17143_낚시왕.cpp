#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

struct shark {
    int r, c, s, d, z;
};

const int MAX = 100;
int R, C, M, MAP[2][MAX][MAX];
bool rm[MAX * MAX + 1];
queue <shark> sharks[2];

int main(int argc, char *argv[]) {  
    scanf("%d %d %d", &R, &C, &M);
    for (int i = 0, r, c, s, d, z; i < M; ++i) {
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        sharks[0].push({r - 1, c - 1, s, d, z});
        MAP[0][r - 1][c - 1] = z;
    }

    int ans = 0;
    for (int j = 0; j < C; ++j) {
        // 상어 잡이
        for (int i = 0; i < R; ++i) 
            if (MAP[j % 2][i][j] && !rm[MAP[j % 2][i][j]]) {
                ans += MAP[j % 2][i][j];
                rm[MAP[j % 2][i][j]] = true;
                MAP[j % 2][i][j] = 0;
                break;
            }

        // 상어 이동
        while (!sharks[j % 2].empty()) {
            shark cur = sharks[j % 2].front();
            sharks[j % 2].pop();

            if (rm[cur.z]) continue;
            MAP[j % 2][cur.r][cur.c] = 0;

            int move = cur.s;
            if (cur.d < 3) {
                move %= (2 * R - 2);
                while (move >= abs((R - 1) * (cur.d - 1) - cur.r)) {
                    move -= abs((R - 1) * (cur.d - 1) - cur.r);
                    cur.r = (R - 1) * (cur.d - 1);
                    cur.d = 3 - cur.d;
                }
                cur.r += move * (cur.d == 1 ? -1 : 1);
            } else {
                move %= (2 * C - 2);
                while (move >= abs((C - 1) * (4 - cur.d) - cur.c)) {
                    move -= abs((C - 1) * (4 - cur.d) - cur.c);
                    cur.c = (C - 1) * (4 - cur.d);
                    cur.d = 7 - cur.d;
                }
                cur.c += move * (cur.d == 4 ? -1 : 1);
            }

            if (MAP[1 - j % 2][cur.r][cur.c] < cur.z) {
                rm[MAP[1 - j % 2][cur.r][cur.c]] = true;
                MAP[1 - j % 2][cur.r][cur.c] = cur.z;
                sharks[1 - j % 2].push(cur);
            } else rm[cur.z] = true;
        }
    }

    printf("%d\n", ans);
    return 0;
}