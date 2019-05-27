#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int N, K, ans, A[1000];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    sort(A, A + N);
    
    queue <int> Q;
    for (int i = 0; i < N; ++i) {
        while (!Q.empty() && Q.front() < A[i] - K) Q.pop();
        Q.push(A[i]);
        ans = max(ans, (int)Q.size());
    }

    printf("%d\n", ans);
    return 0;
}