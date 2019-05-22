#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

ll N, P[40], A[1 << 20], B[1 << 20];

int main(int argc, char *argv[]) {
    P[0] = 1;
    for (int i = 1; i < 40; ++i) P[i] = 3LL * P[i - 1];
    for (int i = 1; i < (1 << 20); ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i & (1 << j)) {
                A[i] += P[j];
                B[i] += P[20 + j];
            }
        }
    }

    scanf("%lld", &N);
    if (N == 0) return !printf("NO\n");
    
    for (int i = 0; i < (1 << 20); ++i) {
        if (A[i] == N || B[i] == N) return !printf("YES\n");
        if (N > A[i]) {
            int lower = lower_bound(B, B + (1 << 20), N - A[i]) - B;
            if (lower < (1 << 20) && B[lower] == N - A[i])
                return !printf("YES\n");
        }
    }
    printf("NO\n");
    return 0;
}