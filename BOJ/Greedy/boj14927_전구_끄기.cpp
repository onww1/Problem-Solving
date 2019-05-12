#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, A[18][18];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", A[i] + j);

    int lim = 1 << N, cnt = 0, ans = INF;
    for (int i = 0; i < lim; ++i) {
        cnt = 0;
        int flip[18][18]{};
        for (int j = 0; j < N; ++j) if (i & (1 << j)) {
            cnt++;
            flip[0][j] ^= 1;
            for (int k = 0; k < 4; ++k) {
                int dr = move_r[k];
                int dc = j + move_c[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                flip[dr][dc] ^= 1;
            }
        }

        for (int r = 1; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (flip[r - 1][c] ^ A[r - 1][c]) {
                    cnt++;
                    flip[r][c] ^= 1;
                    for (int k = 0; k < 4; ++k) {
                        int dr = r + move_r[k];
                        int dc = c + move_c[k];
                        if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                        flip[dr][dc] ^= 1;   
                    }
                }
            }
        }

        bool valid = true;
        for (int c = 0; c < N; ++c) {
            if (A[N - 1][c] ^ flip[N - 1][c]) {
                valid = false;
                break;
            }
        }

        if (valid) ans = min(ans, cnt);
    }
  
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}