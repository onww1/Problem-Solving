#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, DP[301][301];
char A[301], B[301];

int solve(int a, int b) {
    if (a >= N || b >= M) return INF;
    int &ret = DP[a][b];
    if (~ret) return ret;
    ret = abs(A[a] - B[b]);
    int offset = min({solve(a + 1, b), solve(a, b + 1), solve(a + 1, b + 1)});
    if (offset < INF) ret += offset;
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %s %s", &N, &M, A, B);
    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0, 0));
    return 0;
}