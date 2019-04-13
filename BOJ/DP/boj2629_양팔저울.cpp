#include <cstdio>

int N, M;
int C[30], DP[15001];

int main(int argc, char *argv[]) {
    scanf("%d", &N); DP[0] = 1;
    for (int i = 0; i < N; ++i) {
        scanf("%d", C + i);
        for (int j = 15000; j >= 0; --j) {
            if (DP[j] && DP[j] != 100 + i) {
                if (j + C[i] <= 15000 && !DP[j + C[i]]) DP[j + C[i]] = 100 + i;
                if (j - C[i] >= 0 && !DP[j - C[i]]) DP[j - C[i]] = 100 + i;
                if (C[i] - j >= 0 && !DP[C[i] - j]) DP[C[i] - j] = 100 + i;
            }
        }
    }

    scanf("%d", &M);
    for (int i = 0, D; i < M; ++i) {
        scanf("%d", &D);
        printf("%c ", (D > 15000 || !DP[D]) ? 'N' : 'Y');
    }
    
    puts("");
    return 0;
}
