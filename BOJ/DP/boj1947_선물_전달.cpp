#include <cstdio>
typedef long long ll;

const int MOD = 1e9;
ll N, a, b, c;

int main(int argc, char *argv[]) {
    scanf("%lld", &N);
    a = 0, b = 1, c = 0;
    if (N == 1) return !printf("0\n");
    if (N == 2) return !printf("1\n");
    for (ll i = 3; i <= N; ++i) {
        c = (i - 1) * (a + b) % MOD;
        a = b;
        b = c;
    }
    
    printf("%lld\n", c);
    return 0;
}