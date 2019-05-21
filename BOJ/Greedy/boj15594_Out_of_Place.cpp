#include <algorithm>
#include <cstdio>
using namespace std;

int N, ans, A[100], B[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", A + i);
        B[i] = A[i];
    }
    sort(B, B + N);

    for (int i = 0; i < N; ++i) 
        if (A[i] != B[i]) ans++;

    printf("%d\n", max(0, ans - 1));
    return 0;
}