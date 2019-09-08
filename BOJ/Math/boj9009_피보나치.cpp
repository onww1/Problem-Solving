#include <cstdio>

int t, n, fibo[45]{0, 1};

void solve(int num, int idx) {
    if (num == 0 || idx < 0) return;
    if (num >= fibo[idx]) {
        solve(num - fibo[idx], idx - 1);
        printf("%d ", fibo[idx]);
    }
    else solve(num, idx - 1);
}

int main(int argc, char *argv[]) {
    for (int i = 2; i < 45; ++i) 
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        solve(n, 44);
        puts("");
    }
    return 0;
}