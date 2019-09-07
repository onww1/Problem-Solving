#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n, m;
pii p[300050];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d %d", &p[i].Y, &p[i].X);
    sort(p, p + n);

    ll pos = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].X >= p[i].Y) continue;
        if (!pos) pos = p[i].X;
        if (p[i].X >= pos) ans += (p[i].Y - p[i].X), pos = p[i].Y;
        else if (p[i].Y > pos) ans += (p[i].Y - pos), pos = p[i].Y;
    }

    ans = ans * 2 + 1LL * m;
    printf("%lld\n", ans);
    return 0;
}