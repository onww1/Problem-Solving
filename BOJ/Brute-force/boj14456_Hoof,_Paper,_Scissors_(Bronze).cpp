#include <cstdio>
#include <algorithm>
using namespace std;

int N, P[3] = {1, 2, 3}, A[100], B[100];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d", A + i, B + i);
    int ans = 0;
    do {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == P[1] && B[i] == P[0]) cnt++;
            if (A[i] == P[2] && B[i] == P[1]) cnt++;
            if (A[i] == P[0] && B[i] == P[2]) cnt++;
        }
        ans = max(ans, cnt);
    } while (next_permutation(P, P + 3));
    
    printf("%d\n", ans);
    return 0;
}