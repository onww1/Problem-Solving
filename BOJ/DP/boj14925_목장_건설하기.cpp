#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e3;
int N, M, mx, DP[MAX][MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", DP[i] + j);
            DP[i][j] = !DP[i][j];
            if (DP[i][j]) mx = 1;
        }
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (DP[i][j]) {
                DP[i][j] = min({DP[i - 1][j - 1], DP[i - 1][j], DP[i][j - 1]}) + 1;
                mx = max(mx, DP[i][j]);
            }
        }
    }

    printf("%d\n", mx);
    return 0;
}