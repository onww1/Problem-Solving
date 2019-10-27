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

const int MAX = 1e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Edge {
	int v, c, f;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int _v, int _c) : v(_v), c(_c), f(0), dual(nullptr) {}
	int spare() { return c - f; }
	void add_flow(int flow) {
		f += flow;
		dual->f -= flow;
	}
};

char buf[50001];
int k, n, prv[MAX];
Edge* path[MAX];
vector <Edge*> edges[MAX];

void add_edge(int u, int v, int c) {
	Edge *e1 = new Edge(v, c), *e2 = new Edge(u, 0);
	e1->dual = e2, e2->dual = e1;
	edges[u].push_back(e1);
	edges[v].push_back(e2);
}

int main(int argc, char *argv[]) {
    open();

    for (int tc = 1; 1; ++tc) {
    	scanf("%d %d", &k, &n);
    	if (!k && !n) break;
    	getchar();

    	for (int i = 1; i <= n; ++i) 
    		add_edge(2 * i - 1, 2 * i, 1);

    	for (int i = 1, idx, sum; i <= n; ++i) {
    		fgets(buf, sizeof(buf), stdin); 
    		for (idx = 0, sum = 0; buf[idx]; idx++) {
    			if ('0' <= buf[idx] && buf[idx] <= '9') sum = sum * 10 + buf[idx] - '0';
    			else {
    				add_edge(i * 2, sum * 2 - 1, 1);
    				add_edge(sum * 2, i * 2 - 1, 1);
    				sum = 0;
    			}
    		}
    		if (sum) {
    			add_edge(i * 2, sum * 2 - 1, 1);
    			add_edge(sum * 2, i * 2 - 1, 1);
    		}
    	}

    	int ans = 0, S = 2, T = 3;
    	while (ans < k) {
    		memset(prv, -1, sizeof(prv));
    		queue <int> q; q.push(S);
    		while (!q.empty() && prv[T] == -1) {
    			int cur = q.front(); q.pop();
    			for (Edge *e : edges[cur]) {
    				int next = e->v;
    				if (e->spare() && prv[next] == -1) {
    					q.push(next);
    					prv[next] = cur;
    					path[next] = e;
    					if (next == T) break;
    				}
    			}
    		}
    		if (prv[T] == -1) break;

    		for (int i = T; i != S; i = prv[i]) 
    			path[i]->add_flow(1);
    		ans++;
    	}

    	printf("Case %d:\n", tc);
    	if (ans < k) puts("Impossible");
    	else {
    		for (Edge *e1 : edges[S]) {
    			if (e1->spare() || e1->v == 1) continue;
    			printf("%d", 1);
    			int pos = e1->v, pv = 1;
    			while (pos != T) {
    				if ((pos + 1) / 2 != pv) {
    					printf(" %d", (pos + 1) / 2);
    					pv = (pos + 1) / 2;
    				}
    				for (Edge *e2 : edges[pos]) {
    					if (e2->spare()) continue;
    					pos = e2->v; break;
    				}
    			}
    			printf(" %d\n", 2);
    		}
    	}
    	puts("");

    	n *= 2;
    	for (int i = 1; i <= n; ++i) edges[i].clear();
    }

    close();
    return 0;
}
