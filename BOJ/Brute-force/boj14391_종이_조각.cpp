#include <algorithm>
#include <cstdio>
using namespace std;

int n, m, mx, lim, s[4];
char in[4][5];

void solve(int idx) {
    if (idx == n) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i] & (1 << j)) {
                    if (i == 0 || !(s[i - 1] & (1 << j))) {
                        int lsum = (in[i][j] - '0');
                        for (int k = i + 1; k < n; ++k) {
                            if (s[k] & (1 << j)) lsum = lsum * 10 + in[k][j] - '0';
                            else break;
                        }
                        sum += lsum;
                    }
                } 
                else {
                    if (j == 0 || (s[i] & (1 << (j - 1)))) {
                        int lsum = 0;
                        for (; j < m; ++j) {
                            if (s[i] & (1 << j)) break;
                            lsum = lsum * 10 + in[i][j] - '0';
                        }
                        sum += lsum;
                    }
                }
            }
        }
        mx = max(mx, sum);
        return;
    }

    for (int i = 0; i < lim; ++i) {
        s[idx] = i;
        solve(idx + 1);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf(" %s", in[i]);
    lim = 1 << m;
    solve(0);
    printf("%d\n", mx);
    return 0;
}