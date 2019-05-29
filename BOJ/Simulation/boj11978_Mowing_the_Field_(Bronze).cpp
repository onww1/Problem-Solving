#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, ans = INF, s, MAP[2001][2001];
char d;

int parse(char c) {
    if (c == 'N') return 0;
    else if (c == 'W') return 1;
    else if (c == 'S') return 2;
    return 3;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    MAP[1000][1000] = 1;
    for (int i = 0, x = 1000, y = 1000, t = 1; i < N; ++i) {
        scanf(" %c %d", &d, &s);
        int idx = parse(d);
        for (int j = 0; j < s; ++j) {
            ++t;
            y += move_r[idx];
            x += move_c[idx];
            if (MAP[y][x]) ans = min(ans, t - MAP[y][x]);
            MAP[y][x] = t;
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}