#include <cstdio>
int n, m, ans[5];
char in[505][505];
int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 5 * n + 1; ++i) scanf(" %s", in[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int s = 0;
            for (int k = 0; k < 4; ++k) 
                if (in[5 * i + 1 + k][5 * j + 1] == '*')
                    s++;
            ans[s]++;
        }
    }
    for (int i = 0; i < 5; ++i) printf("%d ", ans[i]); puts("");
    return 0;
}