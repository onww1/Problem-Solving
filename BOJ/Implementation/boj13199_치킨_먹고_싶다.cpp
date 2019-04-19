#include <cstdio>
int T, P, M, F, C;
int main(int argc, char *argv[]) {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &P, &M, &F, &C);
        int coupon = M / P * C / F * C + (M / P * C % F);
        if (coupon <= F) printf("%d\n", coupon == F);
        else printf("%d\n", (coupon - F) / (F - C) + 1);
    }
    return 0;
}