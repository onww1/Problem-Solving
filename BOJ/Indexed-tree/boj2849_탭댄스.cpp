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

const int SZ = 1 << 18;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Node {
    int ls, rs, mx, len;
    char lv, rv;
    Node(): Node(1, 1, 1, 1, 'L', 'L'){}
    Node(int _ls, int _rs, int _mx, int _len, char _lv, char _rv): ls(_ls), rs(_rs), mx(_mx), len(_len), lv(_lv), rv(_rv){}
    Node operator+ (const Node &other) const {
        int nls = ls, nrs = other.rs, nmx = max(mx, other.mx);
        if (rv != other.lv) {
            nmx = max(nmx, rs + other.ls);
            if (ls == len) nls = rs + other.ls;
            if (other.rs == other.len) nrs = rs + other.ls;
        }
        return Node(nls, nrs, nmx, len + other.len, lv, other.rv);
    }
} tree[SZ << 1];

int n, q, p;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = Node(1, 1, 1, 1, 'L', 'L');
        return;
    }
    int mid = (start + end) >> 1;
    init(node << 1, start, mid);
    init(node << 1 | 1, mid + 1, end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int node, int start, int end, int idx) {
    if (idx < start || end < idx) return;
    if (start == end) {
        char nval = tree[node].lv == 'L' ? 'R' : 'L';
        tree[node].lv = tree[node].rv = nval;
        return;
    }
    int mid = (start + end) >> 1;
    update(node << 1, start, mid, idx);
    update(node << 1 | 1, mid + 1, end, idx);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    init(1, 1, n);
    while (q--) {
        scanf("%d", &p);
        update(1, 1, n, p);
        printf("%d\n", tree[1].mx);
    }

    close();
    return 0;
}
