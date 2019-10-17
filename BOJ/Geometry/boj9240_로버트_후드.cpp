#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, pii> piii;
typedef tuple <int, int, int> ti3;

clock_t start_time, end_time;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
    TEST(start_time = clock());
}

void close() {
    TEST(end_time = clock());
    TEST(printf("Total time : %Lf seconds\n", (long double)(end_time - start_time) / CLOCKS_PER_SEC));
}

const int SZ = 1 << 17;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, csz;
pii p[MAX];
vector <int> convex_hull;

bool compare_angle(pii &a, pii &b) {
    return (a.Y - p[1].Y) * (b.X - p[1].X) < (b.Y - p[1].Y) * (a.X - p[1].X);
}

ll CCW(pii &a, pii &abase, pii &b, pii &bbase) {
    ll dx_a = a.X - abase.X, dy_a = a.Y - abase.Y;
    ll dx_b = b.X - bbase.X, dy_b = b.Y - bbase.Y;
    ll temp = dx_a * dy_b - dx_b * dy_a;
    return temp < 0 ? -1 : temp > 0 ? 1 : 0;
}

ll convex_CCW(int lo, int hi) {
    int nlo = (lo + 1) % csz;
    int nhi = (hi + 1) % csz;
    return CCW(p[convex_hull[nlo]], p[convex_hull[lo]], p[convex_hull[nhi]], p[convex_hull[hi]]);
}

ldb distance(pii& a, pii &b) {
    return (ldb)sqrt((b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y));
}

void make_convex_hull() {
    sort(p + 1, p + n + 1);
    sort(p + 2, p + n + 1, compare_angle);
    
    convex_hull.push_back(1);
    convex_hull.push_back(2);

    for (int i = 3; i <= n; ++i) {
        while (convex_hull.size() > 1) {
            int se = convex_hull.back(); convex_hull.pop_back();
            int fi = convex_hull.back();
            if (CCW(p[se], p[fi], p[i], p[se]) > 0) {
                convex_hull.push_back(se);
                break;
            }
        }
        convex_hull.push_back(i);
    }
    csz = convex_hull.size();
}

ldb rotating_calipers() {
    int right = 1;
    ldb ret = 0;
    for (int left = 0; left < csz; ++left) {
        while (convex_CCW(left, right) > 0) right = (right + 1) % csz;
        ret = max(ret, distance(p[convex_hull[left]], p[convex_hull[right]]));
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &p[i].X, &p[i].Y);
    if (n == 2) return !printf("%.12Lf\n", distance(p[1], p[2]));

    make_convex_hull();
    printf("%.12Lf\n", rotating_calipers());

    close();
    return 0;
}