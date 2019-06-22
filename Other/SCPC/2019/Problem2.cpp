#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef double db;

struct info {
    int l, r, h;
    bool operator< (const info& other) const {
        return l < other.l;
    }
} infos[1001];

const db PI = acos(-1);
int t, r, s, e, n;

db solve(int idx) {
    db ret = 0.0, theta = 0.0;
    if (infos[idx].h < r) theta = acos((db)(r - infos[idx].h)/r);
    else {
        theta = PI / 2.0;
        ret += (infos[idx].h - r) * 2;
    }
    ret += infos[idx].r - infos[idx].l;
    ret += 2 * r * (1.0 - sin(theta));
    ret += 2 * r * theta;
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d %d %d %d", &r, &s, &e, &n);

        db ans = 0.0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &infos[i].l, &infos[i].r, &infos[i].h);
            ans += solve(i);
            if (i) ans += infos[i].l - infos[i - 1].r - 2 * r;
            if (i == 0) ans += infos[0].l - s - r;
            if (i == n - 1) ans += e - infos[n - 1].r - r;
        }

        printf("Case #%d\n%.12lf\n", tc, ans);
    }

    return 0;
}