#include <algorithm>
#include <cstdio>
using namespace std;

int n, mx, w[10], lim;

void solve(int v, int sum) {
    if (v == lim) {
        mx = max(mx, sum);
        return;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (v & (1 << i)) continue;
        int mul = 1;
        for (int j = i - 1; j >= 0; --j)
            if (!(v & (1 << j))) { mul *= w[j]; break; }
        for (int j = i + 1; j < n; ++j)
            if (!(v & (1 << j))) { mul *= w[j]; break; }
        solve(v | (1 << i), sum + mul);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    lim = (1 << (n - 1)) - 2;
    for (int i = 0; i < n; ++i) scanf("%d", w + i);
    solve(0, 0);
    printf("%d\n", mx);
    return 0;
}