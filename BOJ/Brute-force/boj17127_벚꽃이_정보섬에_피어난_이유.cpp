#include <algorithm>
#include <cstdio>
using namespace std;

int N, A[10], P[10];
int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    for (int i = N - 1; i >= N - 4; --i) P[i] = 1;

    int mx = 0;
    do {
        int val = 0, s = 1;
        for (int i = 0; i < N; ++i) {
            s *= A[i];
            if (P[i]) {
                val += s;
                s = 1;
            }
        }
        mx = max(mx, val);
    } while (next_permutation(P, P + N - 1));

    printf("%d\n", mx);
    return 0;
}