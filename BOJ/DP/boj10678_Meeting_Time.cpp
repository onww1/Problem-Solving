#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int N, M, A[2][17][17];
set <int> S[2][17];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    memset(A, -1, sizeof(A));
    for (int i = 0, a, b, c, d; i < M; ++i) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        A[0][a][b] = c; A[1][a][b] = d;
    }

    for (int i = 0; i < 2; ++i) {
        S[i][1].insert(0);
        for (int j = 1; j < N; ++j) 
            for (int k = j + 1; k <= N; ++k) 
                if (A[i][j][k] != -1)
                    for (int d : S[i][j]) 
                        S[i][k].insert(d + A[i][j][k]);
    }

    for (int dd : S[0][N]) 
        if (S[1][N].count(dd))
            return !printf("%d\n", dd);

    puts("IMPOSSIBLE");
    return 0;
}
