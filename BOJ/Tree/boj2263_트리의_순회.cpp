#include <cstdio>
const int MAX = 1e5 + 1;
int n, in[MAX], inix[MAX], post[MAX], postix[MAX];

void solve(int plo, int phi, int ilo, int ihi) {
    if (plo > phi) return;
    printf("%d ", post[phi]);
    if (plo == phi) return;

    int in_idx = inix[post[phi]];
    solve(plo, plo + in_idx - ilo - 1, ilo, in_idx - 1);
    solve(plo + in_idx - ilo, phi - 1, in_idx + 1, ihi); 
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", in + i), inix[in[i]] = i;
    for (int i = 0; i < n; ++i) scanf("%d", post + i), postix[post[i]] = i;
    solve(0, n - 1, 0, n - 1); puts("");
    return 0;
}