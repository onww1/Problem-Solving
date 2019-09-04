#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, ans, t1, t2, pre, tmp, res;
pll a[100050];

int main(int argc, char *argv[]) {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].X);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].Y);
    sort(a + 1, a + n + 1, [](const pll u, const pll v){
        if (u.Y == v.Y) return u.X < v.X;
        return u.Y < v.Y;
    });
    
    for (int i = 1; i <= n; ++i) {
        if (a[i].Y != a[i - 1].Y) pre = tmp, tmp = 0;
        t1 = a[i].Y > a[i].X ? (a[i].Y - a[i].X + 29) / 30 : 0;
        t2 = a[i].X < pre ? (pre - a[i].X + 29) / 30 : 0;
        res = max(t1, t2);
        a[i].X += res * 30LL;
        tmp = max(tmp, a[i].X);
        ans += res;
    }

    printf("%lld\n", ans);
    return 0;
}