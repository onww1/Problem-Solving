#include <cstdio>

int N, L;

int solve(int n, int p) {
    if (p == 1) return 1;
    int l = n / 10;
    int r = n % p;
    if (l == r) return solve(l, p / 10);
    return solve(l, p / 10) + solve(r, p / 10);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    if (!N) return !printf("1\n");

    for (L = 1; 1; L *= 10) 
        if (N / L < 10) break;
    
    printf("%d\n", solve(N, L));
    return 0;
}
