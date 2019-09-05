#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, k, mn = INF;
int a[51][51], ss[51], r[6], c[6], s[6], v[6], p[6] = {0, 1, 2, 3, 4, 5};

void rotate_cw(int idx) {
    for (int tt = 1; tt <= s[idx]; ++tt) {
        int tmp = a[r[idx] - tt][c[idx] - tt];
        for (int i = r[idx] - tt + 1; i <= r[idx] + tt; ++i) ss[i] -= a[i][c[idx] - tt], ss[i - 1] += a[i][c[idx] - tt], a[i - 1][c[idx] - tt] = a[i][c[idx] - tt];
        for (int j = c[idx] - tt + 1; j <= c[idx] + tt; ++j) a[r[idx] + tt][j - 1] = a[r[idx] + tt][j];
        for (int i = r[idx] + tt - 1; i >= r[idx] - tt; --i) ss[i] -= a[i][c[idx] + tt], ss[i + 1] += a[i][c[idx] + tt], a[i + 1][c[idx] + tt] = a[i][c[idx] + tt];
        for (int j = c[idx] + tt - 1; j >  c[idx] - tt; --j) a[r[idx] - tt][j + 1] = a[r[idx] - tt][j];
        a[r[idx] - tt][c[idx] - tt + 1] = tmp;
    }
}

void rotate_ccw(int idx) {
    for (int tt = 1; tt <= s[idx]; ++tt) {
        int tmp = a[r[idx] - tt][c[idx] - tt];
        for (int j = c[idx] - tt + 1; j <= c[idx] + tt; ++j) a[r[idx] - tt][j - 1] = a[r[idx] - tt][j];
        for (int i = r[idx] - tt + 1; i <= r[idx] + tt; ++i) ss[i] -= a[i][c[idx] + tt], ss[i - 1] += a[i][c[idx] + tt], a[i - 1][c[idx] + tt] = a[i][c[idx] + tt];
        for (int j = c[idx] + tt - 1; j >= c[idx] - tt; --j) a[r[idx] + tt][j + 1] = a[r[idx] + tt][j];
        for (int i = r[idx] + tt - 1; i >  r[idx] - tt; --i) ss[i] -= a[i][c[idx] - tt], ss[i + 1] += a[i][c[idx] - tt], a[i + 1][c[idx] - tt] = a[i][c[idx] - tt];
        ss[r[idx] - tt] -= tmp, ss[r[idx] - tt + 1] += tmp, a[r[idx] - tt + 1][c[idx] - tt] = tmp;
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            scanf("%d", a[i] + j);
            ss[i] += a[i][j];
        }
    
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", r + i, c + i, s + i);
        r[i]--, c[i]--;
    }

    do {
        for (int i = 0; i < k; ++i) rotate_cw(p[i]);
        for (int i = 0; i < n; ++i) mn = min(mn, ss[i]);
        for (int i = k - 1; i >= 0; --i) rotate_ccw(p[i]);
    } while (next_permutation(p, p + k));
    
    printf("%d\n", mn);
    return 0;
}