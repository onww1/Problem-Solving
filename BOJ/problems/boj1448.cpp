#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e6;
int N, A[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    sort(A, A + N);

    for (int i = N - 1; i > 1; --i) 
        if (A[i] < A[i - 1] + A[i - 2]) return !printf("%d\n", A[i] + A[i - 1] + A[i - 2]);
    
    puts("-1");
    return 0;
}