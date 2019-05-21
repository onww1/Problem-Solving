#include <cstdio>

char in[15];
int a, b, f, i, j;

int main(int argc, char *argv[]) {
    scanf(" %s", in);
    for (i = 0; in[i]; ++i) if (in[i] == 'x') break;
    if (!in[i]) a = 0, i = -1;
    else if (i == 0) a = 1;

    for (j = 0, f = 0; j < i; ++j) {
        if (in[j] == '-') f = 1;
        else a = 10 * a + in[j] - '0';
    }
    if (f) a = !a ? -1 : -a;

    for (j = i + 1, f = 0; in[j]; ++j) {
        if (in[j] == '-') f = 1;
        else if (in[j] == '+') continue;
        else b = 10 * b + in[j] - '0';
    }
    if (f) b *= -1;

    if (a / 2 == 1) printf("xx");
    else if (a / 2 == -1) printf("-xx");
    else if (a / 2) printf("%dxx", a / 2);

    if (b == 1) printf(a ? "+x" : "x");
    else if (b == -1) printf("-x");
    else if (a && b > 0) printf("+%dx", b);
    else if (b) printf("%dx", b);

    if (!a && !b) printf("W\n");
    else printf("+W\n");
    return 0;
}