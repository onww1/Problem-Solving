#include <cstdio>
const int MAX = 1e5;
int N, S, A[MAX + 1], L[MAX + 1];

int max(int a, int b) { return a > b ? a : b; }
int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &S);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", A + i);
        A[i] += A[i - 1];
    }

    for (int i = 1; i <= N; ++i) {
        int l = 1, r = i, m;
        while (l <= r) {
            m = (l + r) >> 1;
            if (2 * i - m + 1 <= N && A[i] - A[m - 1] <= S &&  A[2 * i - m + 1] - A[i] <= S) 
                r = m - 1;
            else 
                l = m + 1;
        }
        L[l] = i - l + 1;
    }
    
    for (int i = 1; i <= N; ++i) {
        L[i] = max(L[i], L[i - 1] - 1);
        printf("%d\n", 2 * L[i]);
    }

    return 0;
}