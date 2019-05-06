#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;

struct Point {
    int x, y;
    bool operator< (const Point& other) const {
        if (y == other.y) return x < other.x;
        return y < other.y;
    }
};

const int MAX = 1e5;
const int INF = 0x3f3f3f3f;
int N;
Point P[MAX];

int dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].x, &P[i].y);
    sort(P, P + N, [](const Point& a, const Point& b) { return a.x < b.x; });

    set <Point> S = {P[0], P[1]};
    int ans = dist(P[0], P[1]), start = 0;
    for (int i = 2; i < N; ++i) {
        while (start < i) {
            int x = P[i].x - P[start].x;
            if (x * x >= ans) {
                S.erase(P[start]);
                start++;
            }
            else break;
        }

        int d = (int)sqrt((double)ans) + 1;
        Point lp = {-INF, P[i].y - d};
        Point up = { INF, P[i].y + d};
        auto lower = S.lower_bound(lp);
        auto upper = S.upper_bound(up);
        for (auto it = lower; it != upper; ++it) 
            ans = min(ans, dist(P[i], *it));
        S.insert(P[i]);
    }

    printf("%d\n", ans);
    return 0;
}