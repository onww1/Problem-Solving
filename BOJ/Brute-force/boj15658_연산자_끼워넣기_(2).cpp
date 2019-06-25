#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, mx, mn, a[11], op[4];

int calc(int a, int b, int oper) {
    switch (oper) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3: return a / b;
    }
    return INF;
}

void solve(int idx, int res) {
    if (idx == n) {
        mx = max(mx, res);
        mn = min(mn, res);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (!op[i]) continue;
        op[i]--;
        solve(idx + 1, calc(res, a[idx], i));
        op[i]++;
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < 4; ++i) scanf("%d", op + i);
    mx = -INF, mn = INF;
    solve(1, a[0]);
    printf("%d\n%d\n", mx, mn);
    return 0;
}