#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

const int MAX = 1e5;
int N, A, C[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", C + i);
    sort(C, C + N, greater<int>());
    for (int i = 0; i < N; ++i) {
        if (i % 3 == 2) continue;
        A += C[i];
    }
    printf("%d\n", A);
    return 0;
}