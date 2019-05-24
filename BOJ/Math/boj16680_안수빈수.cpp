#include <cstdio>
typedef long long ll;

const ll LL_INF = 1e18;
ll T, N;

bool check(ll N) {
    ll sum = 0;
    while (N) {
        sum += N % 10;
        N /= 10;
    }
    return sum % 2;
}

int main(int argc, char *argv[]) {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &N);
        bool flag = false;
        for (ll tmp = N; tmp <= LL_INF; tmp += N * N)
            if (check(tmp)) {
                flag = true;
                N = tmp;
                break;
            }
        printf("%lld\n", flag ? N : -1);
    }  
    return 0;
}