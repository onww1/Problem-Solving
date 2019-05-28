#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, R[1000];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", R + i);

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        int cnt = 0, dist = 1;
        for (int j = i + 1; j < N; ++j) cnt += R[j] * (dist++);
        for (int j = 0; j < i; ++j) cnt += R[j] * (dist++);
        ans = min(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}