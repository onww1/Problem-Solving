#include <cstdio>
typedef long long ll;

int main(int argc, char *argv[]) {
    ll N, A;
    scanf("%lld %lld", &N, &A);
    if (N > 5) return !printf("Love is open door\n");
    for (A ^= 1, N--; N--; A ^= 1) printf("%lld\n", A);
    return 0;
}