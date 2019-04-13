#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N, B, DP[2][500001];
int main(int argc, char *argv[]) {
    scanf("%d", &N);
    memset(DP, -1, sizeof(DP)); DP[0][0] = DP[1][0] = 0;

    for (int i = 0, mx = 0; i < N; ++i) {
        scanf("%d", &B);
        for (int j = 0; j <= mx; ++j) {
            if (DP[0][j] == -1) continue;
            if (DP[1][j + B] < DP[0][j] + B)
                DP[1][j + B] = DP[0][j] + B, mx = max(mx, DP[1][j + B]);
            if (j - B >= 0 && DP[1][j - B] < DP[0][j])
                DP[1][j - B] = DP[0][j], mx = max(mx, DP[1][j - B]);
            if (B - j > 0 && DP[1][B - j] < DP[0][j] - j + B)
                DP[1][B - j] = DP[0][j] - j + B, mx = max(mx, DP[1][B - j]);
        }
        for (int j = 0; j <= mx; ++j) DP[0][j] = DP[1][j];
    }

    printf("%d\n", DP[0][0] == 0 ? -1 : DP[0][0]);
    return 0;
}
