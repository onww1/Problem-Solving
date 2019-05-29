#include <cstdio>

int p[4], n[4], ps, ns;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 4; ++i) {
        scanf("%d %d", p + i, n + i);
        ps += p[i];
        ns += n[i];
    }

    p[0] += (ns - ps);
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", p[i] - n[i]);
        p[i + 1] += p[i] - n[i];
    }

    return 0;
}