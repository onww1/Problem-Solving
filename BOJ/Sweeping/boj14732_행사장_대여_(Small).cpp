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

struct line {
    int x, y1, y2, f;
};

int n, tree[1 << 18], lazy[1 << 18];
vector <line> lines;

void update(int node, int start, int end, int left, int right, int val) {
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        lazy[node] += val;
    } else {
        int mid = (start + end) >> 1;
        update(node * 2, start, mid, left, right, val);
        update(node * 2 + 1, mid + 1, end, left, right, val);
    }

    if (lazy[node]) tree[node] = end - start + 1;
    else if (start != end) tree[node] = tree[node * 2] + tree[node * 2 + 1];
    else tree[node] = 0;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        y1 += 50001, y2 += 50001;
        lines.push_back({x1, y1, y2 - 1, 1});
        lines.push_back({x2, y1, y2 - 1, -1});
    }
    sort(lines.begin(), lines.end(), [](const line& a, const line& b) { 
        return a.x < b.x;
    });

    ll ans = 0;
    int pos = lines[0].x;
    for (line &L : lines) {
        ans += 1LL * (L.x - pos) * tree[1];
        update(1, 1, 100001, L.y1, L.y2, L.f);
        pos = L.x;
    }
    printf("%lld\n", ans);

    close();
    return 0;
}