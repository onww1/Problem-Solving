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
#include <list>
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

int n, k, m, lo, hi, sqn, a[MAX], ans[MAX];
vector<int> b, c;
vector<piii> q;
list<int> li[MAX];

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

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sqn = 1; while (sqn * sqn < n) sqn++;
    c.resize(n + 1, 0); b.resize(sqn + 1, 0);
    scanf("%d", &m);
    for (int i = 1, l, r; i <= m; ++i) {
        scanf("%d %d", &l, &r);
        q.push_back({{l, r}, i});
    }
    sort(q.begin(), q.end(), cmp);
    lo = hi = 1; add(1);
    c[0] = b[0] = k + 1;
    for (int i = 0, l, r, idx; i < q.size(); ++i) {
        l = q[i].X.X, r = q[i].X.Y, idx = q[i].Y;
        while (l < lo) add(--lo);
        while (hi < r) add(++hi);
        while (lo < l) remove(lo++);
        while (r < hi) remove(hi--);
        int mxb = sqn;
        while (b[mxb] == 0) mxb--;
        int mxc = min((mxb + 1) * sqn, n - 1);
        while (c[mxc] == 0) mxc--;
        ans[idx] = mxc;
    }
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);

    close();
    return 0;
}
