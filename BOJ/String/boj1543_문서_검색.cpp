#include <cstdio>

int main(int argc, char *argv[]) {
    char t[2502]{}, p[52]{};
    fgets(t, sizeof(t), stdin);
    fgets(p, sizeof(p), stdin);
    
    int f[50]{}, lt = 0, lp = 0;
    for (lp = 0; p[lp]; ++lp) if (p[lp] == '\n') { p[lp] = 0; break; }
    for (lt = 0; t[lt]; ++lt) if (t[lt] == '\n') { t[lt] = 0; break; }
    
    for (int i = 1, j = 0; i < lp; ++i) {
        while (j && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    int ans = 0;
    for (int i = 0, j = 0; i < lt; ++i) {
        while (j && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == lp - 1) {
                ans++;
                j = 0;
            }
            else j++;
        }
    }

    printf("%d\n", ans);
    return 0;
}