#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

const int MAX = 1e5;
const int INF = 0x3f3f3f3f;
int N;
Point P[MAX];

int solve(int s, int e) {
    if (e - s <= 2) {
        int ret = INF;
        for (int i = 0; i <= e - s; ++i) 
            ret = min(ret, dist(P[s + i % (e - s + 1)], P[s + (i + 1) % (e - s + 1)]));
        return ret;
    }

    int m = (s + e) >> 1; 
    int line = (P[m].x + P[m + 1].x) >> 1;
    int d = min(solve(s, m), solve(m + 1, e));

    vector <Point> mid;
    Point lo, hi;
    int sq = (int)sqrt((double)d) + 1;
    lo.x = line - sq, lo.y = -INF;
    hi.x = line + sq, lo.y = INF;
    auto lower = lower_bound(P + s, P + e + 1, lo, [](const Point &a, const Point &b) { return a.x < b.x; });
    auto upper = upper_bound(P + s, P + e + 1, hi, [](const Point &a, const Point &b) { return a.x < b.x; });
    for (auto it = lower; it != upper; ++it) 
        mid.push_back(*it);
    sort(mid.begin(), mid.end(), [](const Point& a, const Point& b) { return a.y < b.y; });

    int mid_size = mid.size();
    for (int i = 0; i < mid_size - 1; ++i) 
        for (int j = i + 1; j < mid_size && mid[j].y - mid[i].y < d; ++j) 
            d = min(d, dist(mid[i], mid[j]));
    return d;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].x, &P[i].y);
    sort(P, P + N, [](const Point &a, const Point &b) { return a.x < b.x; });
    printf("%d\n", solve(0, N - 1));
    return 0;
}