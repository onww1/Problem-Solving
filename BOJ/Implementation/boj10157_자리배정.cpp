#include <cstdio>
int main(int argc, char *argv[]) {
    int R, C, K;
    scanf("%d %d %d", &C, &R, &K);
    if (K > R * C) return !printf("0\n");
    int x = 1, y = 1, f = 0;
    while (R > 2 && C > 2 && 2 * (R + C) - 4 < K) {
        K -= 2 * (R + C - 2);
        R -= 2, C -= 2;
        f++;
    }
    if (K <= R) y = K, x = 1;
    else if (K <= R + C - 1) y = R, x = K - R + 1;
    else if (K <= 2 * R + C - 2) x = C, y = R + 1 - (K - R - C + 2);
    else y = 1, x = C + 1 - (K - 2 * R - C + 3);
    x += f, y += f;
    printf("%d %d\n", x, y);
    return 0;
}