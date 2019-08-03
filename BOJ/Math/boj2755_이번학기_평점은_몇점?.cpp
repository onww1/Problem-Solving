#include <cstdio>
int n, a, b, c, d;
char sc[3];
int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %*s %d %s", &c, sc);
        b += c;
        if (sc[0] <= 'D') d = 4 - (sc[0] - 'A');
        else d = 0;
        if (sc[1] == '+') d = d * 10 + 3;
        else if (sc[1] == '-') d = d * 10 - 3;
        else d *= 10;
        a += d * c;
    }
    b *= 10;
    printf("%d.", a / b);
    a = a % b * 10;
    printf("%d", a / b);
    a = a % b * 10;
    if (a % b * 2 >= b) a += b;
    printf("%d\n", a / b);
    return 0;
}