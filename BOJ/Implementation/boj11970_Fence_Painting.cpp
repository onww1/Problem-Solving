#include <cstdio>
int main(int argc, char *argv[]) {
    int a, b, c, d, ans = 0, V[101]{};
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i < b; ++i) V[i] = 1;
    for (int i = c; i < d; ++i) V[i] = 1;
    for (int i = 0; i <= 100; ++i) ans += V[i];
    printf("%d\n", ans);
    return 0;
}