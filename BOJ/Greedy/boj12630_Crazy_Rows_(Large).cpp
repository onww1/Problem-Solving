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

const int SZ = 1 << 6;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int t, n, tree[SZ << 1];
char in[SZ];
vector<pii> v;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) >> 1;
    update(node << 1, start, mid, idx, val);
    update(node << 1 | 1, mid + 1, end, idx, val);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return query(node << 1, start, mid, left, right) + query(node << 1 | 1, mid + 1, end, left, right);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf("%d", &n);
        memset(tree, 0, sizeof(tree));
        v.clear();
        for (int i = 1; i <= n; i++) {
            scanf(" %s", in + 1);
            bool flag = false;
            for (int j = n; j > 0; j--) 
                if (in[j] == '1') {
                    flag = true;
                    v.push_back({i, j});
                    break;
                }
            if (!flag) v.push_back({i, 0});
        }
        sort(v.begin(), v.end(), [&](pii a, pii b) {
            return a.Y < b.Y;
        });

        int ans = 0;
        for (int i = 1, j = 0; i <= n; i++) {
            while (j < n && v[j].Y <= i) pq.push(v[j++]);
            pii p = pq.top(); pq.pop();
            int num = query(1, 1, n, p.X, n);
            ans += p.X + num - i;
            update(1, 1, n, p.X, 1);
        }
        printf("Case #%d: %d\n", tc, ans);
    }

    close();
    return 0;
}
