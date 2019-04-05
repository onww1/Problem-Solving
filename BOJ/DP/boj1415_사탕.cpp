#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

int N, A[50], mx;
ll DP[500001];
bool noPrime[500001] = {1, 1, };

int main(int argc, char *argv[]) {
    for (int i = 2; i <= 500000; ++i) 
        if (!noPrime[i]) 
            for (ll j = (ll)i * i; j <= 500000; j += i) 
                noPrime[j] = 1;
        
    scanf("%d", &N); 
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    sort(A, A + N);

    DP[0] = 1;
    for (int i = 0, V, cnt; i < N; ++i) {
        V = A[i], cnt = 0;
        while (i < N && A[i] == V) i++, cnt++;
        --i;

        for (int j = mx; j >= 0; --j) {
            if (DP[j]) {
                if (V > 0) {
                    for (int k = 1; k <= cnt; ++k) 
                        DP[j + k * V] += DP[j];
                    mx = max(mx, j + V * cnt);
                } else DP[j] *= (cnt + 1);
            }
        }
    }

    ll ans = 0;
    for (int i = mx; i >= 2; --i) 
        if (DP[i] && !noPrime[i]) ans += DP[i];

    printf("%lld\n", ans);
    return 0;
}