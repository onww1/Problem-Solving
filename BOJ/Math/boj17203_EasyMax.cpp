#include <algorithm>
#include <cstdio>
using namespace std;

int N, Q, A[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", A + i);
        if (i > 1) A[i - 1] = abs(A[i] - A[i - 1]);
    }

    for (int i = 1; i < N; ++i) A[i] += A[i - 1];

    while (Q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b - 1 < a) {
            puts("0");
            continue;
        }
        printf("%d\n", A[b - 1] - A[a - 1]);
    }
  
    return 0;
}