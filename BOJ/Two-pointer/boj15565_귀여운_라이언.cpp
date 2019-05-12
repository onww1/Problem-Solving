#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e6;
const int INF = 0x3f3f3f3f;
int N, K, A[MAX + 5];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", A + i);
        if (A[i] == 2) A[i] = 0;
        A[i] += A[i - 1];
    }

    int l = 0, r = 1, ans = INF;
    while (r <= N && l < r) {
        if (A[r] - A[l] >= K) {
            if (A[r] - A[l] == K) ans = min(ans, r - l);
            l++;
        } 
        else r++;
    }

    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}