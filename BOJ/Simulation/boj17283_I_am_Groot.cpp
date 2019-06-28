#include <cstdio>
int main(int argc, char *argv[]) {
    int l, r, ans = 0, c = 2;
    scanf("%d %d", &l, &r);    
    while (l * r / 100 > 5) {
        l = l * r / 100;
        ans += l * c;
        c *= 2;
    }
    printf("%d\n", ans);
    return 0;
}