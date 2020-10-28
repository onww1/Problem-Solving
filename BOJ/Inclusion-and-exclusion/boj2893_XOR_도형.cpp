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

struct tri {
    int x, y, r;
    tri(): tri(0, 0, 0) {}
    tri(int _x, int _y, int _r): x(_x), y(_y), r(_r) {}
    ll area() { return 1LL * r * r; }
    tri operator+ (const tri& other) const {
        tri ret;
        if (x <= other.x && y <= other.y && r > other.x + other.y - x - y) 
            ret = tri(other.x, other.y, min(y + r - other.x + x - other.y, other.r));
        else if (other.x <= x && other.y <= y && other.r > x + y - other.x - other.y)
            ret = tri(x, y, min(other.y + other.r - x + other.x - y, r));
        else if (other.x < x && other.y > y && other.r > x - other.x && r > other.y - y) 
            ret = tri(x, other.y, min(other.r - x + other.x, y + r - other.y));
        else if (x < other.x && y > other.y && r > other.x - x && other.r > y - other.y)
            ret = tri(other.x, y, min(r - other.x + x, other.y + other.r - y));
        return ret;
    }
    void describe() {
        printf("(x, y, r) : (%d, %d, %d) | area : %lld.%lld\n", x, y, r, 1LL * r * r / 2LL, 1LL * r * r % 2LL * 5LL);
    }
};

int n, x, y, r;
tri t[10];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &r);
        t[i] = tri(x, y, r);
        t[i].describe();
    }
    puts("");
    
    int lim = 1 << n;
    ll ans = 0;
    for (int i = 1; i < lim; i++) {
        int cnt = 0;
        tri p(1, 1, INF);
        for (int j = 0; j < n; j++) 
            if (i & (1 << j)) { 
                p = p + t[j];
                cnt++;
                p.describe();
            }
        puts("");
        if (cnt & 1) ans += p.area() * (1LL << (cnt - 1));
        else ans -= p.area() * (1LL << (cnt - 1));
    }
    printf("%lld.%lld\n", ans / 2LL, ans % 2LL * 5);

    close();
    return 0;
}
