#include <algorithm>
#include <cstdio>
using namespace std;

int N, ans, A[1000], DP[1000];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", A + i);
        DP[i] = A[i];
        for (int j = i - 1; j >= 0; --j)
            if (A[j] > A[i]) 
                DP[i] = max(DP[i], DP[j] + A[i]);
        ans = max(ans, DP[i]);
    }

    printf("%d\n", ans);
    return 0;
}