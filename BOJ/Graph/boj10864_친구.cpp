#include <cstdio>
int n, m, a[1001];
int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        a[u]++, a[v]++;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", a[i]);
    return 0;
}