#include <cstdio>
int main(int argc, char *argv[]) {
    int n; scanf("%d", &n);
    n = (n - 1) % 8 + 1;
    if (n > 5) n = 10 - n;
    printf("%d\n", n);
    return 0;
}