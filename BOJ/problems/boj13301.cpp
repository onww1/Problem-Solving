#include <cstdio>
typedef long long ll;

int N;
ll fibo[85] = {1, 1, };

int main(int argc, char *argv[]) {
    for (int i = 2; i <= 80; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
    scanf("%d", &N);
    printf("%lld\n", 2LL * (fibo[N] + fibo[N - 1]));
    return 0;
}