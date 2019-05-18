#include <algorithm>
#include <cstdio>
using namespace std;

int L, N, A[50];

int main(int argc, char *argv[]) {
    scanf("%d", &L);
    for (int i = 0; i < L; ++i) scanf("%d", A + i);
    scanf("%d", &N);

    sort(A, A + L);
    int idx = lower_bound(A, A + L, N) - A;
    if (A[idx] == N) return !printf("0\n");

    
    if (idx == 0) printf("%d\n", N * (A[idx] - N) - 1);
    else printf("%d\n", (N - A[idx - 1]) * (A[idx] - N) - 1);
    return 0;
}