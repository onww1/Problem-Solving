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

struct Edge {
	int v, c, f;
	Edge* dual;
	Edge() : Edge(-1, 0) {}
	Edge(int _v, int _c) : v(_v), c(_c), f(0), dual(nullptr) {}
	int spare() { return c - f; }
	void add_flow(int flow) {
		f += flow;
		dual->f -= flow;
	}
};

int t, n, m, a[51][51], prv[2502];
Edge* path[2502];
vector <Edge*> edges[2502];

int get_idx(int r, int c) {
	return (r - 1) * m + c;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
    	scanf("%d %d", &n, &m);  
    	for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= m; ++j) {
    			scanf("%d", a[i] + j);
    			int idx = get_idx(i, j);
    			if ((i + j) % 2 == 0) {
    				Edge *e1 = new Edge(idx, a[i][j]), *e2 = new Edge(0, 0);
    				e1->dual = e2, e2->dual = e1;
    				edges[0].push_back(e1);
    				edges[idx].push_back(e2);
    				for (int k = 0; k < 4; ++k) {
    					int dr = i + move_r[k];
    					int dc = j + move_c[k];
    					if (dr < 1 || dr > n || dc < 1 || dc > m) continue;
    					int other_idx = get_idx(dr, dc);
    					Edge *e1 = new Edge(other_idx, INF), *e2 = new Edge(idx, 0);
    					e1->dual = e2, e2->dual = e1;
    					edges[idx].push_back(e1);
    					edges[other_idx].push_back(e2);
    				}
    			}
    			else {
    				Edge *e1 = new Edge(n * m + 1, a[i][j]), *e2 = new Edge(idx, 0);
    				e1->dual = e2, e2->dual = e1;
    				edges[idx].push_back(e1);
    				edges[n * m + 1].push_back(e2);
    			}
    		}

    	int ans = 0, S = 0, T = n * m + 1;
    	while (1) {
    		memset(prv, -1, sizeof(prv));
    		queue <int> q; q.push(S);
    		while (!q.empty() && prv[T] == -1) {
    			int cur = q.front(); q.pop();
    			for (Edge* e : edges[cur]) {
    				int next = e->v;
    				if (e->spare() && prv[next] == -1) {
    					prv[next] = cur;
    					path[next] = e;
    					q.push(next);
    					if (next == T) break;
    				}
    			}
    		}
    		if (prv[T] == -1) break;

    		int flow = INF;
    		for (int i = T; i != S; i = prv[i])
    			flow = min(flow, path[i]->spare());
    		for (int i = T; i != S; i = prv[i])
    			path[i]->add_flow(flow);
    		ans += flow;
    	}
    	for (Edge *e : edges[0]) ans += e->spare(); edges[0].clear();
    	for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= m; ++j) {
    			int idx = get_idx(i, j);
    			if ((i + j) % 2) {
    				for (Edge* e : edges[idx])
    					if (e->v == n * m + 1) {
    						ans += e->spare();
    						break;
    					}
    			}
    			edges[idx].clear();
    		}
    	edges[n * m + 1].clear();
    	printf("%d\n", ans);
    }

    close();
    return 0;
}
