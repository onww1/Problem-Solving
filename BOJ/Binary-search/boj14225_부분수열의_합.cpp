#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[20], s[1 << 20];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < (1 << n); ++i) 
        for (int j = 0; j < n; ++j) 
            if (i & (1 << j)) 
                s[i] += a[j];
    sort(s, s + (1 << n));
    n = unique(s, s + (1 << n)) - s;

    int l = 1, r = n - 1, m = r, ans = 1;
    while (l <= r) {
        m = (l + r) >> 1;
        if (s[m] > m) r = m - 1;
        else {
            ans = m + 1;
            l = m + 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}