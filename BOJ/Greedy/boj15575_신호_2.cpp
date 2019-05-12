#include <algorithm>
#include <cmath>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair <ll, ll> pll;

const int MAX = 1e6;
const int INF = 0x3f3f3f3f;
int N;
pll P[MAX]; 

ldb dist(pll &a, pll &b) {
    return (ldb)sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%lld %lld", &P[i].X, &P[i].Y);
    sort(P, P + N);

    ldb V[2][4]{};
    auto lower = lower_bound(P, P + N, pll(P[0].X, -INF));
    auto upper = upper_bound(P, P + N, pll(P[0].X, INF));
    --upper;
    pll pre[2] = { *lower, *upper };

    for (int i = upper - P + 1; i < N;) {
        lower = lower_bound(P, P + N, pll(P[i].X, -INF));
        upper = upper_bound(P, P + N, pll(P[i].X, INF));
        i += (upper - lower);
        --upper;

        ldb lu = dist(pre[0], *upper);
        ldb ld = dist(pre[0], *lower);
        ldb ru = dist(pre[1], *upper);
        ldb rd = dist(pre[1], *lower);

        pre[0] = *lower;
        pre[1] = *upper;

        V[1][0] = max(V[0][0], V[0][2]) + ld;
        V[1][1] = max(V[0][0], V[0][2]) + lu;
        V[1][2] = max(V[0][1], V[0][3]) + rd;
        V[1][3] = max(V[0][1], V[0][3]) + ru;

        for (int j = 0; j < 4; ++j) V[0][j] = V[1][j];
    }
  
    printf("%.12Lf\n", max({V[0][0], V[0][1], V[0][2], V[0][3]}));
    return 0;
}