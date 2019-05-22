#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 1;
int N, M, A[MAX];

bool solve(int d) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < N; ++i) {
        if (sum + A[i] > d) {
            cnt++;
            sum = A[i];
        }
        else sum += A[i];
    }
    return cnt <= M;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    int lo = 1, hi = 1e9, ans = hi;
    for (int i = 0; i < N; ++i) {
        scanf("%d", A + i);
        lo = max(lo, A[i]);
    }
    while (lo <= hi) {
        int m = (lo + hi) >> 1;
        if (solve(m)) {
            ans = m;
            hi = m - 1;
        } else lo = m + 1;
    }
    printf("%d\n", ans);
    return 0;
}