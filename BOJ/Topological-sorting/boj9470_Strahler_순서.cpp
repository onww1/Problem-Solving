/*
 *  BOJ 9470. Strahler 순서 
 *
 *  시간 복잡도 : O(E + VlogV)
 *  공간 복잡도 : O(E)
 *
 *  각 노드별로 들어오는 간선, 나가는 간선, 순서를 저장할 공간을 만들고, 
 *  들어오는 인풋에 대하여 들어오는 간선, 나가는 간선을 저장해줍니다. 
 *  그리고 들어오는 간선이 0인 노드들을 큐에 넣으면서 위상정렬과 같은 방식으로 진행하고, 
 *  그 과정에서 인접한 노드에 자신의 순서를 저장합니다. 
 *  그렇게 자신의 차례가 되었을 때, 저장된 인접한 노드들의 순서를 보고 자신의 순서를 정합니다.
 */

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

const int MAX = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int t, k, n, m, in[MAX], d[MAX], c[MAX];
vector<int> edges[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &k, &n, &m);
        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            edges[u].push_back(v);
            in[v]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) if (!in[i]) {
            d[i] = c[i] = 1;
            q.push(i);
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (c[node] > 1) d[node]++;
            for (int next: edges[node]) {
                if (--in[next] == 0) q.push(next);
                if (d[next] < d[node]) {
                    d[next] = d[node];
                    c[next] = 1;
                } else if (d[next] == d[node]) c[next]++;
            }
        }
        printf("%d %d\n", k, d[n]);
        for (int i = 1; i <= n; ++i) {
            edges[i].clear();
            in[i] = d[i] = c[i] = 0;
        }
    }
    return 0;
    close();
}

