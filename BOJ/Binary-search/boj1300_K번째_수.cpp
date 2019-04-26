#include <cstdio>
typedef long long ll;
int N, K; 
int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    int l = 1, r = 1e9, m;
    while (l <= r) {
        m = (l + r) >> 1;
        ll lower = 0, cnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (m / i > N) lower += N;
            else {
                lower += (m / i);
                if (m % i == 0) {
                    lower--;
                    cnt++;
                }    
            }
        }
        if (lower < K && K <= lower + cnt) return !printf("%d\n", m);
        if (lower + cnt < K) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
