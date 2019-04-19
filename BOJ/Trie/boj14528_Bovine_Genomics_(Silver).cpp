#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
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
typedef pair<int, pii> piii;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
}

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int idx[128];

class Trie {
public:
    Trie* child[4];
    Trie() { for (int i = 0; i < 4; ++i) child[i] = 0; }
    ~Trie() { for (int i = 0; i < 4; ++i) if (child[i]) delete child[i]; }
    void insert(const char* key) {
        if (*key == 0) return;
        int next = idx[*key];
        if (!child[next]) child[next] = new Trie;
        child[next]->insert(key + 1);
    }
    bool query(const char* key) {
        if (*key == 0) return false;
        int next = idx[*key];
        if (!child[next]) return true;
        return child[next]->query(key + 1);
    }
};

int N, M, P[3], ans;
char in[1005][55], Q[4];

void solve(int T, int prev) {
    if (T == 3) { 
        Trie *t = new Trie;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 3; ++j) Q[j] = in[i][P[j]];
            t->insert(Q);
        }

        bool ok = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 3; ++j) Q[j] = in[i + N][P[j]];
            if (!(t->query(Q))) { ok = false; break; }
        }

        if (ok) ans++;
        delete t;
        return;
    }

    for (int i = prev + 1; i < M - 2 + T; ++i) {
        P[T] = i;
        solve(T + 1, i);
    }
}

int main(int argc, char *argv[]) {
    open();

    idx['A'] = 0, idx['G'] = 1, idx['T'] = 2, idx['C'] = 3;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < 2 * N; ++i) scanf(" %s", in[i]);
    solve(0, -1);

    printf("%d\n", ans);
    return 0;
}