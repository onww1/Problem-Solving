#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int a, b, n;

int main(int argc, char *argv[]) {
    int ans = INF;
    scanf("%d %d %d", &a, &b, &n);
    if (a == b) return !printf("0\n");
    for (int i = 0, c, k; i < n; ++i) {
        scanf("%d %d", &c, &k);
        int aa = -1, bb = -1;
        for (int j = 0, p; j < k; ++j) {
            scanf("%d", &p);
            if (p == a) aa = j;
            if (p == b) bb = j;
        }
        if (~aa && ~bb && bb >= aa) 
            ans = min(ans, c);
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}