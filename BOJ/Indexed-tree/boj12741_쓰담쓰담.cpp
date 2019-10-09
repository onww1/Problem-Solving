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

int n, qq, q, l, r, a[MAX];
bool tree[SZ << 1];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = true;
        return;
    }
    int mid = (start + end) >> 1;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] && tree[node * 2 + 1] && a[mid] <= a[mid + 1];
}

void update(int idx, int node = 1, int start = 1, int end = n) {
    if (end < idx || idx < start) return;
    if (start == end && start == idx) {
        tree[node] = true;
        return;
    }

    int mid = (start + end) >> 1;
    update(idx, node * 2, start, mid);
    update(idx, node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] && tree[node * 2 + 1] && a[mid] <= a[mid + 1];
}

int query(int left, int right, int node = 1, int start = 1, int end = n) {
    if (end < left || right < start) return -1;
    if (left <= start && end <= right) return tree[node] ? 1 : 0;
    int mid = (start + end) >> 1;
    int lc = query(left, right, node * 2, start, mid);
    int rc = query(left, right, node * 2 + 1, mid + 1, end);
    if (lc == -1) return rc;
    else if (rc == -1) return lc;
    return lc && rc && a[mid] <= a[mid + 1];
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &qq);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    init();

    while (qq--) {
        scanf("%d %d %d", &q, &l, &r);
        if (q == 1) puts(query(l, r) ? "CS204" : "HSS090");
        else {
            swap(a[l], a[r]);
            update(l);
            update(r);
        }
    }

    close();
    return 0;
}
