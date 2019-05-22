#include <cstdio>

int N, P[20];

bool solve(int n, int idx) {
    if (n == 0) return true;
    if (idx == 20 || n < 0) return false;

    if (solve(n - P[idx], idx + 1)) return true;
    return solve(n, idx + 1);
}

int main(int argc, char *argv[]) {
    P[0] = 1;
    for (int i = 1; i < 20; ++i) P[i] = 3 * P[i - 1];
    scanf("%d", &N);
    puts(N > 0 && solve(N, 0) ? "YES" : "NO");
    return 0;
}