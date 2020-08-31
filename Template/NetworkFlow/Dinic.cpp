#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int S = 100, T = 101;

struct Dinic {
    struct Edge {
        int v, c, f;
        Edge* op;
        Edge(): Edge(-1, 0){}
        Edge(int _v, int _c): v(_v), c(_c), f(0), op(nullptr){}
        int spare() { return c - f; }
        void addFlow(int flow) {
            f += flow;
            op->f -= flow;
        }
    };
    vector<Edge*> edges[T + 1];
    int level[T + 1], work[T + 1];

    void init() {
        for (int i = 0; i <= T; ++i) {
            for (auto &it: edges[i]) delete it;
            edges[i].clear();
        }
    }

    void addEdge(int u, int v, int c) {
        Edge* e1 = new Edge(v, c);
        Edge* e2 = new Edge(u, 0);
        e1->op = e2, e2->op = e1;
        edges[u].push_back(e1);
        edges[v].push_back(e2);
    }

    bool bfs() {
        memset(level, -1, sizeof(level));
        queue<int> q; q.push(S); level[S] = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto &it: edges[node]) {
                if (level[it->v] == -1 && it->spare()) {
                    level[it->v] = level[node] + 1;
                    q.push(it->v);
                }
            }
        }
        return level[T] != -1;
    }

    int dfs(int node, int flow) {
        if (node == T) return flow;
        for (int &i = work[node]; i < edges[node].size(); ++i) {
            Edge *e = edges[node][i];
            if (level[e->v] == level[node] + 1 && e->spare()) {
                int res = dfs(e->v, min(flow, e->spare()));
                if (res) {
                    e->addFlow(res);
                    return res;
                }
            }
        }
        return 0;
    }

    int maximumFlow() {
        int ret = 0, res;
        while (bfs()) {
            memset(work, 0, sizeof(work));
            while (res = dfs(S, INF)) ret += res;
        }
        return ret;
    }
} DINIC;