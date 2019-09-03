#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int n, m, p, l, a[105], s[105];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p, &l);
        for (int j = 0; j < p; ++j) scanf("%d", a + j);
        sort(a, a + p, greater<int>());
        if (p >= l) s[i] = a[l - 1];
        else s[i] = 1;
    }

    sort(s, s + n);
    int ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + s[i] <= m) sum += s[i], ans++;
        else break;
    }

    printf("%d\n", ans);
    return 0;
}