#include <algorithm>
#include <cmath>
#include <cstdio>
#define X first
#define Y second
#define POW2(x) ((x) * (x))
using namespace std;
typedef long double ldb;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
int p[3] = {1, 2, 3}, ans = INF;
pii pos[4];

int dist(int a, int b) {
    return POW2(pos[a].X - pos[b].X) + POW2(pos[a].Y - pos[b].Y);
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 4; ++i) scanf("%d %d", &pos[i].X, &pos[i].Y);
    do {
        int cur = 0;
        ldb d = 0;
        for (int i = 0; i < 3; ++i) {
            d += sqrt(dist(cur, p[i]));
            cur = p[i];
        }
        ans = min(ans, (int)d);
    } while (next_permutation(p, p + 3));
    printf("%d\n", ans);
    return 0;
}