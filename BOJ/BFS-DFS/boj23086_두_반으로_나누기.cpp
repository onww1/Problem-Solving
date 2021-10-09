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

int n, m, k, p[MAX];
bool isCut[2 * MAX];
vector<pii> edges;
vector<int> graph[MAX];
vector<int> cut;

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        edges.push_back({u, v});
    }
    for (int i = 0, p; i < k; i++) {
        scanf("%d", &p);
        p--;
        cut.push_back(p);
        isCut[p] = true;
    }

    for (int i = 0; i < edges.size(); i++) {
        if (isCut[i]) continue;
        graph[edges[i].X].push_back(edges[i].Y);
        graph[edges[i].Y].push_back(edges[i].X);       
    }

    bool isOK = true;

    int cnt[3]{};
    queue<int> q;
    q.push(1);
    p[1] = 1;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cnt[p[node]]++;
        for (int next : graph[node]) {
            if (p[next]) {
                if (p[node] == p[next]) isOK = false;
                continue;
            }
            p[next] = 3 - p[node];
            q.push(next);
        }
    }

    if (!isOK) puts("-1");
    else {
        int answer = 0;
        for (int i = (int)cut.size() - 1; i >= 0; i--) {
            if (p[edges[cut[i]].X] == p[edges[cut[i]].Y]) {
                answer = i + 1;
                break;
            }
        }
        printf("%d\n%d %d\n", answer, min(cnt[1], cnt[2]), max(cnt[1], cnt[2]));
    }

    close();
    return 0;
}