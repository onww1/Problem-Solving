#include <cstdio>

int n, m, s, cnt[55][128];
char in[1050][55], c[] = "ACGT", ans[55];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", in[i]);
        for (int j = 0; in[i][j]; ++j) cnt[j][in[i][j]]++;
    }

    for (int i = 0; i < m; ++i) {
        int mx = 0;
        for (int j = 0; j < 4; ++j) {
            if (cnt[i][c[j]] > mx) {
                mx = cnt[i][c[j]];
                ans[i] = c[j];
            }
        }
        s += (n - mx);
    }

    printf("%s\n%d\n", ans, s);
    return 0;
}