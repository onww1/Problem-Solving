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

const int SZ = 1 << 16;
const int MAX = 5e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, tree[SZ << 1], lazy[SZ << 1];
vector<ti3> p;

void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        tree[node] += lazy[node];
        if (start != end) {
            int mid = (start + end) >> 1;
            int need = end - mid - lazy[node * 2 + 1] - tree[node * 2 + 1];
            if (need > 0) {
                lazy[node * 2 + 1] += min(need, lazy[node]);
                lazy[node] -= min(need, lazy[node]);
            }
            lazy[node * 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int &c) {
    update_lazy(node, start, end);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        int need = min(end - start + 1 - lazy[node] - tree[node], c);
        lazy[node] += need;
        c -= need;
        update_lazy(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2 + 1, mid + 1, end, left, right, c);
    update(node * 2, start, mid, left, right, c);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0, a, b, c; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        p.push_back({a, b, c});
    }
    sort(p.begin(), p.end());
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for (int i = 0, idx = 0, a, b, c; i <= MAX; ++i) {
        while (!pq.empty() && pq.top().X <= i) {
            int cnt = query(1, 0, MAX, pq.top().Y.X, pq.top().X);
            if (pq.top().Y.Y > cnt) {
                int need = pq.top().Y.Y - cnt;
                update(1, 0, MAX, pq.top().Y.X, pq.top().X, need);
            }
            pq.pop();
        }
        while (idx < p.size()) {
            tie(a, b, c) = p[idx];
            if (a == i) {
                pq.push({b, {a, c}});
                idx++;
            }
            else break;
        }
    }
    printf("%d\n", query(1, 0, MAX, 0, MAX));

    close();
    return 0;
}

