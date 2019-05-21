#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int N, DP[MAX], A[] = {1, 2, 5, 7};

int solve(int n) {
    if (n < 1) return !n ? 0 : INF;

    int &ret = DP[n];
    if (~ret) return ret;
    ret = INF;

    for (int i = 0; i < 4; ++i) 
        ret = min(ret, 1 + solve(n - A[i]));

    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    memset(DP, -1, sizeof(DP));
    DP[1] = DP[2] = DP[5] = DP[7] = 1;
    printf("%d\n", solve(N));
    return 0;
}