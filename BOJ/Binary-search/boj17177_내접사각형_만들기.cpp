#include <cstdio>
int a, b, c;
int main(int argc, char *argv[]) {
    scanf("%d %d %d", &a, &b, &c);
    int d = (a * a - b * b) * (a * a - c * c);
    int e = b * c;

    int l = 1, r = 1e4, m = r, f = 0;
    while (l <= r) {
        m = (l + r) >> 1;
        if (m * m == d) {
            f = 1;
            break;
        } 
        else if (m * m > d) r = m - 1;
        else l = m + 1;
    }   

    if (!f || (m - e) % a) return !printf("-1\n");
    printf("%d\n", (m - e) / a);

    return 0;
}