#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
const int S = 2001, T = 2002;

struct MCMF { 
	struct edge {
		int u, v, c, op, cost;
	};
	int dist[T + 1], p[T + 1];
	bool inQ[T + 1];
	vector <edge> edges;
	vector <int> vec[T + 1];

	void init() {
		edges.clear();
		for (int i = 0; i <= T; ++i) vec[i].clear();
	}

	void addEdge(int u, int v, int c, int cost) {
		int sz = edges.size();
		edge e1 = { u, v, c, sz + 1, cost };
		edge e2 = { v, u, 0, sz, -cost };
		edges.push_back(e1);
		edges.push_back(e2);
		vec[u].push_back(sz);
		vec[v].push_back(sz + 1);
	}

	bool SPFA() {
		memset(inQ, false, sizeof(inQ));
		memset(p, -1, sizeof(p));
		memset(dist, 0x3f, sizeof(dist));
		queue <int> q; q.push(S);
		inQ[S] = true; dist[S] = 0;
		while (!q.empty()) {
			int here = q.front(); q.pop();
			inQ[here] = false;
			for (int idx : vec[here]) {
				edge &eg = edges[idx];
				if (eg.c > 0 && dist[eg.v] > dist[here] + eg.cost) {
					dist[eg.v] = dist[here] + eg.cost;
					p[eg.v] = idx;
					if (!inQ[eg.v]) {
						inQ[eg.v] = true;
						q.push(eg.v);
					}
				}
			}
		}
		return p[T] != -1;
	}

	pii solve() {
		pii ret = { 0, 0 };
		while (SPFA()) {
			int flow = INF;
			for (int i = T; i != S; i = edges[p[i]].u)
				flow = min(flow, edges[p[i]].c);
			ret.X += flow;
			for (int i = T; i != S; i = edges[p[i]].u) {
				ret.Y += flow * edges[p[i]].cost;
				edges[p[i]].c -= flow;
				edges[edges[p[i]].op].c += flow;
			}
		}
		return ret;
	}
} mcmf;


int main(int argc, char *argv[]) {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
    	mcmf.init();
    	mcmf.addEdge(S, 1, 2, 0);
    	mcmf.addEdge(2 * n, T, 2, 0);
    	for (int i = 2; i < n; ++i) mcmf.addEdge(i, i + n, 1, 0);
    	mcmf.addEdge(n, n + n, 2, 0);
    	mcmf.addEdge(1, 1 + n, 2, 0);
    	for (int i = 0, u, v, w; i < m; ++i) {
    		scanf("%d %d %d", &u, &v, &w);
    		mcmf.addEdge(u + n, v, 1, w);
    	}
    	printf("%d\n", mcmf.solve().Y);
    }
    return 0;
}
