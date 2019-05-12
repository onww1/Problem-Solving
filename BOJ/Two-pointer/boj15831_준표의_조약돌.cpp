#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 3e5;
const int INF = 0x3f3f3f3f;
int N, M, K, W[MAX + 1], B[MAX + 1];
char in[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d %d %s", &N, &M, &K, in);
    for (int i = 0; i < N; ++i) {
        W[i + 1] = W[i] + (in[i] == 'W');
        B[i + 1] = B[i] + (in[i] == 'B');
    }

    int l = 0, r = 1, ans = 0;
    while (r <= N && l < r) {
        if (W[r] - W[l] >= K && B[r] - B[l] <= M) {
            ans = max(ans, r - l);
            r++;
        }
        else {
            if (W[r] - W[l] < K) r++;
            if (B[r] - B[l] > M) l++;
        }
        if (l == r) r++;
    }

    printf("%d\n", ans);
    return 0;
}
