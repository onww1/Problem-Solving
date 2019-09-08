#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, c, ans, arr[30], a[1 << 15], b[1 << 15];

int main(int argc, char *argv[]) {
    scanf("%lld %lld", &n, &c);
    for (int i = 0; i < n; ++i) scanf("%lld", arr + i);
    int ai = n / 2, bi = n - n / 2;
    
    for (int i = 0; i < (1 << ai); ++i)
        for (int j = 0; j < ai; ++j)
            if (i & (1 << j)) a[i] += arr[j];

    for (int i = 0; i < (1 << bi); ++i)
        for (int j = 0; j < bi; ++j)
            if (i & (1 << j)) b[i] += arr[ai + j];

    ai = 1 << ai, bi = 1 << bi;
    sort(a, a + ai);
    sort(b, b + bi);

    ans = 1;
    ans += upper_bound(a, a + ai, c) - a - 1;
    ans += upper_bound(b, b + bi, c) - b - 1;

    for (int i = 1; i < ai; ++i) {
        if (a[i] >= c) break;
        ans += upper_bound(b, b + bi, c - a[i]) - b - 1;
    }

    printf("%lld\n", ans);
    return 0;
}