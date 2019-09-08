#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[20], b[20];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);

    int lim = 1 << n, ans = 0;
    for (int i = 0; i < lim; ++i) {
        int sum = 0, ss = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += a[j];
                ss += b[j];
            }
        }
        if (sum < 100) ans = max(ans, ss);
    }

    printf("%d\n", ans);
    return 0;
}