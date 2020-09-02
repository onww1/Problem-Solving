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

const int SZ = 1 << 19;
const int MAX = 5e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Node {
    Node *l, *r;
    int x;
} *r[MAX];

int n, m, q, x, y, z;

void init(Node *node, int p) {
    if (p < 0) return;
    node->l = new Node();
    node->r = new Node();
    init(node->l, p - 1);
    init(node->r, p - 1);
}

void _add(Node *node, Node *prev, int v, int p) {
    if (p < 0) {
        node->x = prev->x + 1;
        return;
    }
    if (v & (1 << p)) {
        node->r = new Node();
        node->l = prev->l;
        _add(node->r, prev->r, v, p - 1);
    } else {
        node->l = new Node();
        node->r = prev->r;
        _add(node->l, prev->l, v, p - 1);
    }
    node->x = node->l->x + node->r->x;
}

int _xor(Node *l, Node *r, int v, int p) {
    if (p < 0) return 0;
    if (v & (1 << p)) {
        if (r->l->x - l->l->x > 0) return (1 << p) | _xor(l->l, r->l, v, p - 1);
        else return _xor(l->r, r->r, v, p - 1);
    } else {
        if (r->r->x - l->r->x > 0) return (1 << p) | _xor(l->r, r->r, v, p - 1);
        else return _xor(l->l, r->l, v, p - 1);
    }
}

int _sum(Node *l, Node *r, int v, int p) {
    if (p < 0) return 0;
    if (v & (1 << p)) return r->l->x - l->l->x + _sum(l->r, r->r, v, p - 1);
    else return _sum(l->l, r->l, v, p - 1);
}

int _kth(Node *l, Node *r, int k, int p) {
    if (p < 0) return 0;
    int sum = r->l->x - l->l->x;
    if (sum < k) return (1 << p) | _kth(l->r, r->r, k - sum, p - 1);
    else return _kth(l->l, r->l, k, p - 1);
}

int main(int argc, char *argv[]) {
    open();

    r[0] = new Node();
    init(r[0], 18);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d", &x);
            r[++n] = new Node();
            _add(r[n], r[n - 1], x, 18);
        } else if (q == 2) {
            scanf("%d %d %d", &y, &z, &x);
            printf("%d\n", _xor(r[y - 1], r[z], x, 18) ^ x);
        } else if (q == 3) {
            scanf("%d", &x);
            n -= x;
        } else if (q == 4) {
            scanf("%d %d %d", &y, &z, &x);
            printf("%d\n", _sum(r[y - 1], r[z], x + 1, 18));
        } else if (q == 5) {
            scanf("%d %d %d", &y, &z, &x);
            printf("%d\n", _kth(r[y - 1], r[z], x, 18));
        }
    }

    close();
    return 0;
}
