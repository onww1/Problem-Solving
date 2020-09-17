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
#include <list>
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
typedef pair <pii, int> piii;
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

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, sqn, lo, hi, a[MAX], ans[MAX];
vector<int> b, c;
vector<piii> q;
list<int> li[2 * MAX];

bool cmp(piii a, piii b) {
    int ga = a.X.Y / sqn, gb = b.X.Y / sqn;
    if (ga == gb) return a.X.X < b.X.X;
    return ga < gb;
}

void add(int idx) {
    int x = a[idx];
    if (li[x].size() > 1) {
        int val = li[x].back() - li[x].front();
        c[val]--;
        b[val / sqn]--;
    }
    if (li[x].empty() || li[x].back() < idx) li[x].push_back(idx);
    else li[x].push_front(idx);
    if (li[x].size() > 1) {
        int val = li[x].back() - li[x].front();
        c[val]++;
        b[val / sqn]++;
    }
}

void remove(int idx) {
    int x = a[idx];
    if (li[x].size() > 1) {
        int val = li[x].back() - li[x].front();
        c[val]--;
        b[val / sqn]--;
    }
    if (li[x].back() == idx) li[x].pop_back();
    else li[x].pop_front();
    if (li[x].size() > 1) {
        int val = li[x].back() - li[x].front();
        c[val]++;
        b[val / sqn]++;
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] += a[i - 1];
    }
    for (int i = 0; i <= n; ++i) a[i] += n;
    sqn = 1; while (sqn * sqn < n) sqn++;
    c.resize(n + 1, 0), b.resize(sqn + 1, 0);

    scanf("%d", &m);
    for (int i = 1, l, r; i <= m; ++i) {
        scanf("%d %d", &l, &r);
        q.push_back({{--l, r}, i});
    }
    sort(q.begin(), q.end(), cmp);

    lo = hi = 0; add(0);
    c[0] = b[0] = 3 * MAX;
    for (int i = 0; i < q.size(); ++i) {
        while (q[i].X.X < lo) add(--lo);
        while (hi < q[i].X.Y) add(++hi);
        while (lo < q[i].X.X) remove(lo++);
        while (q[i].X.Y < hi) remove(hi--);
        int mxb = sqn;
        while (b[mxb] == 0) mxb--;
        int mxc = min((mxb + 1) * sqn, n);
        while (c[mxc] == 0) mxc--;
        ans[q[i].Y] = mxc;
    }

    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);

    close();
    return 0;
}
