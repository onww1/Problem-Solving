#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;

int N, A, C[300002];
set <int> S;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    C[0] = C[300001] = -1;
    S.insert(0); S.insert(300001);

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A);
        auto upper = S.upper_bound(A);
        int mx = C[*upper];
        mx = max(mx, C[*(--upper)]);
        C[A] = mx + 1;
        ans += C[A];

        printf("%lld\n", ans);
        S.insert(A);
    }

    return 0;
}