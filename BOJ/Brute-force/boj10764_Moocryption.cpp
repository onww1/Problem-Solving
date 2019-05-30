#include <algorithm>
#include <cstdio>
using namespace std;

const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int N, M, ans[26][26];
char MAP[50][51];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < 8; ++k) {
                int br = i + move_r[k] * 2;
                int bc = j + move_c[k] * 2;
                if (br < 0 || br >= N || bc < 0 || bc >= M) continue;
                if (MAP[br][bc] == MAP[i][j] || MAP[i][j] == 'D' || MAP[br][bc] == 'O') continue;
                int dr = i + move_r[k];
                int dc = j + move_c[k];
                if (MAP[br][bc] == MAP[dr][dc])
                    ans[MAP[i][j] - 'A'][MAP[dr][dc] - 'A']++;
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            mx = max(mx, ans[i][j]);

    printf("%d\n", mx);
    return 0;
}