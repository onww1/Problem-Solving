#include <algorithm>
#include <cstdio>
using namespace std;

const int MOD = 987654321;
int N, DP[5001];

int main(int argc, char *argv[]) {
    scanf("%d", &N); N /= 2;
    DP[0] = DP[1] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < i / 2; ++j) 
            DP[i] = (DP[i] + 2LL * DP[j] * DP[i - 1 - j]) % MOD;
        if (i % 2) DP[i] = (DP[i] + 1LL * DP[i / 2] * DP[i / 2]) % MOD;
    }

    printf("%lld\n", DP[N]);
    return 0;
}