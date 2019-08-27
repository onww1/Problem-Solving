#include <algorithm>
#include <cstdio>
using namespace std;

int n, q, l, r, a[300050];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    return 0;
}