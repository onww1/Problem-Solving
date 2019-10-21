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
	Edge(): Edge(-1, 0) {}
	Edge(int _v, int _c): v(_v), c(_c), f(0), dual(nullptr) {}
	int spare() { return c - f; }
	void add_flow(int flow) {
		f += flow;
		dual->f -= flow;
	}
};

int t, n, m, prv[305];
Edge* path[305];
vector <Edge*> edges[305];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
    	scanf("%d %d", &n, &m);
    	for (int i = 0, a, b, c; i < m; ++i) {
    		scanf("%d %d %d", &a, &b, &c);
    		Edge *e1 = new Edge(b, c), *e2 = new Edge(a, 0);
    		e1->dual = e2, e2->dual = e1;
    		edges[a].push_back(e1);
    		edges[b].push_back(e2);
    	}

    	int S = 1, T = n;
    	while (1) {
    		memset(prv, -1, sizeof(prv));
    		queue <int> q; q.push(S);
    		while (!q.empty() && prv[T] == -1) {
    			int cur = q.front(); q.pop();
    			for (Edge* e : edges[cur]) {
    				int next = e->v;
    				if (e->spare() > 0 && prv[next] == -1) {
    					q.push(next);
    					prv[next] = cur;
    					path[next] = e;
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
    	}

    	int ans = 0;
    	for (int i = 1; i <= n; ++i) 
    		for (Edge *e : edges[i]) 
    			if (e->c && !e->spare()) {
    				int uu = i, vv = e->v;
    				memset(prv, -1, sizeof(prv));
    				queue <int> q; q.push(uu);
    				while (!q.empty() && prv[vv] == -1) {
    					int cur = q.front(); q.pop();
    					for (Edge* e : edges[cur]) {
    						int next = e->v;
    						if (e->spare() && prv[next] == -1) {
    							q.push(next);
    							prv[next] = cur;
    							if (next == vv) break;
    						}
    					}
    				}
    				if (prv[vv] == -1) ans++;
    			}
    		
    	printf("%d\n", ans);

    	for (int i = 1; i <= n; ++i) edges[i].clear();
    }

    close();
    return 0;
}
