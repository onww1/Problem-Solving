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

const int MAX = 5e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, pa[MAX], mx[MAX], f[MAX];
ll s[MAX];
vector<pii> e;
vector<int> v;

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[u] = v;
        s[v] += s[u];
        mx[v] = max(mx[v], mx[u]);
        f[v] = f[v] && f[u];
    } 
    else f[u] = 0;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        v.push_back(a); 
        v.push_back(b);
        e.push_back({a, b});
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < v.size(); ++i) {
        pa[i] = i;
        s[i] = v[i];
        mx[i] = v[i];
        f[i] = 1;
    }

    ll sum = 0;
    for (pii& p: e) {
        sum += p.X + p.Y;
        p.X = lower_bound(v.begin(), v.end(), p.X) - v.begin();
        p.Y = lower_bound(v.begin(), v.end(), p.Y) - v.begin();
        _union(p.X, p.Y);
    }

    ll ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        int node = _find(i);
        if (f[node] == 2) continue;
        if (f[node] == 1) ans += s[node] - mx[node];
        else ans += s[node];
        f[node] = 2;
    }

    printf("%lld\n", sum - ans);

    close();
    return 0;
}
