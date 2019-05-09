#include <algorithm>
#include <cstdio>
using namespace std;
typedef double db;

int N, sum, W[5000], DP[5000];
db S[5000];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%lf", S + i);
    for (int i = 0; i < N; ++i) scanf("%d", W + i), sum += W[i];

    int mx = (DP[0] = W[0]);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) 
            if (S[j] <= S[i]) DP[i] = max(DP[i], DP[j]);
        DP[i] += W[i];
        mx = max(mx, DP[i]);
    }

    printf("%d\n", sum - mx);
    return 0;
}