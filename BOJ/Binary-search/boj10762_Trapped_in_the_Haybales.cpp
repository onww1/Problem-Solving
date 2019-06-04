#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5 + 1;
int N, B;
pii P[MAX];

bool solve1(int pos, int extra) {
    int l = pos, r = pos + 1;
    int len = P[r].X - P[l].X;
    while (l >= 0 && r < N) {
        if ((P[l].Y + extra >= len && P[r].Y >= len) ||
            (P[l].Y >= len && P[r].Y + extra >= len)) 
            return true;
        if (P[l].Y < len) {
            l--;
            if (l >= 0) len = P[r].X - P[l].X;
        }
        else if (P[r].Y < len) {
            r++;
            if (r < N) len = P[r].X - P[l].X;
        }
    }
    return false;
}

bool solve2(int pos, int extra) {
    int l = pos, r = pos + 1;
    int len = P[r].X - P[l].X;
    while (l >= 0 && r < N) {
        if ((P[l].Y + extra >= len && P[r].Y >= len) ||
            (P[l].Y >= len && P[r].Y + extra >= len)) 
            return true;
        if (P[r].Y < len) {
            r++;
            if (r < N) len = P[r].X - P[l].X;
        }
        else if (P[l].Y < len) {
            l--;
            if (l >= 0) len = P[r].X - P[l].X;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &B);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].Y, &P[i].X);
    sort(P, P + N);

    int pos = lower_bound(P, P + N, pii(B, 0)) - P - 1;
    int l = 0, r = 1e9, ans = r;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (solve1(pos, m) || solve2(pos, m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    printf("%d\n", ans == 1e9 ? -1 : ans);
    return 0;
}