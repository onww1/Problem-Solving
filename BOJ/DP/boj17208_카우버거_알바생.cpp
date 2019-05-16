#include <algorithm>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, M, K, DP[100][301][301];
pii P[100];

int solve(int idx, int a, int b) {
    if (idx >= N || a > M || b > K) return 0;

    int &ret = DP[idx][a][b];
    if (~ret) return ret;
    ret = 0;

    ret = solve(idx + 1, a, b);
    if (a + P[idx].X <= M && b + P[idx].Y <= K)
        ret = max(ret, solve(idx + 1, a + P[idx].X, b + P[idx].Y) + 1);
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; ++i) 
        scanf("%d %d", &P[i].X, &P[i].Y);
    
    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0, 0, 0));

    return 0;
}