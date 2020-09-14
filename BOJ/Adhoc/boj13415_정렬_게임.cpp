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

int n, k, a[MAX];
vector<piii> p;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    scanf("%d", &k);
    int mx = 0;
    for (int i = 1, A, B; i <= k; ++i) {
        scanf("%d %d", &A, &B);
        p.push_back({{A, B}, i});
        mx = max({mx, A, B});
    }
    sort(p.begin(), p.end(), [&](piii a, piii b) {
        int amx = max(a.X.X, a.X.Y);
        int bmx = max(b.X.X, b.X.Y);
        return amx == bmx ? a.Y > b.Y : amx > bmx;
    });

    deque<int> dq(a + 1, a + mx + 1);
    sort(dq.begin(), dq.end());
    
    int prv = p[0].Y, prvA = p[0].X.X, prvB = p[0].X.Y;
    for (int i = 1; i < p.size(); ++i) {
        if (p[i].Y > prv) {
            mx = max(p[i].X.X, p[i].X.Y);
            for (int j = prvA; j > max(mx, prvB); --j) a[j] = dq.back(), dq.pop_back();
            for (int j = prvB; j > mx; --j) a[j] = dq.front(), dq.pop_front();
            prvA = p[i].X.X;
            prvB = p[i].X.Y;
            prv = p[i].Y;
        }
    }
    for (int j = prvA; j > prvB; --j) a[j] = dq.back(), dq.pop_back();
    for (int j = prvB; j > 0; --j) a[j] = dq.front(), dq.pop_front();
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");

    close();
    return 0;
}
