#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N, A[1000], B[1000], DP[1000][1000];

int solve(int a, int b) {
    if (a == N || b == N) return 0;

    int &ret = DP[a][b];
    if (~ret) return ret;
    ret = 0;

    if (abs(A[a] - B[b]) <= 4) ret = 1 + solve(a + 1, b + 1);
    else ret = max(solve(a + 1, b), solve(a, b + 1));
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    for (int i = 0; i < N; ++i) scanf("%d", B + i);
    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0, 0));
    return 0;
}