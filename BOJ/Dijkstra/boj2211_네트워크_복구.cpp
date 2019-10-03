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

int n, m, p[1005], dist[1005];
vector <pii> edges[1005];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    memset(dist, 0x3f, sizeof(dist));
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1}); dist[1] = 0;

    while (!pq.empty()) {
        int d = pq.top().X;
        int cur = pq.top().Y;
        pq.pop();

        if (d > dist[cur]) continue;

        for (pii edge : edges[cur]) {
            if (dist[edge.X] > d + edge.Y) {
                dist[edge.X] = d + edge.Y;
                pq.push({dist[edge.X], edge.X});
                p[edge.X] = cur;
            }
        }
    }

    set <pii> s;
    for (int i = 2; i <= n; ++i) {
        int pos = i;
        while (p[pos] > 0) {
            s.insert({pos, p[pos]});
            pos = p[pos];
        }
    }

    printf("%lu\n", s.size());
    for (auto it = s.begin(); it != s.end(); ++it) printf("%d %d\n", it->X, it->Y);
    
    close();
    return 0;
}