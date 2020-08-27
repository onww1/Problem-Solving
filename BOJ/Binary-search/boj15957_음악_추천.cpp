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

int n, k, j, chs, singers[MAX], lo[MAX], hi[MAX], ch[MAX][2];
ll tree[MAX];
vector<int> edges[MAX], songs[MAX], mid[MAX];
vector<piii> qs;

void preprocess(int node) {
    ch[node][0] = ++chs;
    for (int next: edges[node])
        preprocess(next);
    ch[node][1] = chs;
}

void update(int node, ll v) {
    while (node <= n) {
        tree[node] += v;
        node += node & -node;
    }
}

ll sum(int node) {
    ll ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &k, &j);
    for (int i = 2, p; i <= n; ++i) {
        scanf("%d", &p);
        edges[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", singers + i);
        songs[singers[i]].push_back(i);
        lo[i] = 0, hi[i] = k - 1;
    }
    for (int i = 0, a, b, c; i < k; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        qs.push_back({a, {b, c}});
    }
    sort(qs.begin(), qs.end());
    preprocess(1);

    bool updated = true;
    while (updated) {
        updated = false;
        for (int i = 1; i <= n; ++i) {
            if (lo[i] <= hi[i]) mid[(lo[i] + hi[i]) >> 1].push_back(i);
            tree[i] = 0;
        }
        for (int i = 0; i < k; ++i) {
            int rt = qs[i].Y.X;
            ll v = qs[i].Y.Y / (ch[rt][1] - ch[rt][0] + 1);
            update(ch[rt][0], v);
            update(ch[rt][1] + 1, -v);
            while (!mid[i].empty()) {
                updated = true;
                int singer = mid[i].back(); mid[i].pop_back();
                ll s = 0;
                for (int song: songs[singer]) 
                    s += sum(ch[song][0]);
                if (s > 1LL * j * (int)songs[singer].size()) hi[singer] = i - 1;
                else lo[singer] = i + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) 
        printf("%d\n", lo[singers[i]] == k ? -1 : qs[lo[singers[i]]].X);

    close();
    return 0;
}