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

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, p = -1, a[10001], tmp[10001];
vector <pii> c;

int _abs(int a) { return a < 0 ? -a : a; }

pii check(pii& p1) {
    for (int i = 1; i <= n; ++i) tmp[i] = a[i];
    for (int i = 0, len = p1.Y - p1.X + 1; i < len / 2; ++i) swap(tmp[p1.X + i], tmp[p1.Y - i]);

    vector <pii> cc; p = -1;
    for (int i = 1; i <= n; ++i) {
        if (p != -1) {
            if (_abs(tmp[i - 1] - tmp[i]) == 1) continue;
            if (!cc.empty() && cc.back().Y == p) cc.push_back({max(1, p - 1), i - 1});
            cc.push_back({p, i - 1});
            if (i != tmp[i]) {
                cc.push_back({p, i});
                p = i;
            }
            else p = -1;
        }
        else if (i != tmp[i]) p = i;
    }
    if (cc.size() != 1) return {INF, INF};
    return cc[0];
}

void print(pii &p1, pii& p2) {
    printf("%d %d\n%d %d\n", p1.X, p1.Y, p2.X, p2.Y);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (p != -1) {
            if (_abs(a[i - 1] - a[i]) == 1) continue;
            if (!c.empty() && c.back().Y == p) c.push_back({max(1, p - 1), i - 1});
            c.push_back({p, i - 1});
            if (i != a[i]) {
                c.push_back({p, i});
                p = i;
            }
            else p = -1;
        }
        else if (i != a[i]) p = i;
    }
    if (p != -1) {
        if (!c.empty() && c.back().Y == p) c.push_back({max(1, p - 1), n});
        c.push_back({p, n});
    }

    if (c.size() < 2) {
        while (c.size() < 2) c.push_back({1, 1});
        print(c[0], c[1]);
    } 
    else {
        pii ans;
        for (int i = 0; i < c.size(); ++i) {
            for (int j = i; j < c.size(); ++j) {
                pii ppp = { c[i].X, c[j].Y };
                ans = check(ppp);
                if (ans.X != INF) {
                    print(ppp, ans);
                    break;
                }
            }
            if (ans.X != INF) break;
        }
    }
        
    close();
    return 0;
}