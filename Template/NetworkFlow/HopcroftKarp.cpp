const int MAX = 2e5 + 1;

struct HopcroftKarp {
    int size, a[MAX], b[2 * MAX], lv[MAX];
    bool used[MAX];
    vector<int> edges[MAX];    

    void init(int n) {
        size = n;
        for (int i = 1; i <= n; ++i) {
            a[i] = b[i] = b[i + n] = -1;
            used[i] = false;
            edges[i].clear();
        }
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
    }

    void bfs() {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                lv[i] = 0;
                q.push(i);
            }
            else lv[i] = INF;
        }
        while (!q.empty()) {
            int an = q.front(); q.pop();
            for (int bn: edges[an]) {
                if (b[bn] != -1 && lv[b[bn]] == INF) {
                    lv[b[bn]] = lv[an] + 1;
                    q.push(b[bn]);
                }
            }
        }
    }

    bool dfs(int an) {
        for (int bn: edges[an]) {
            if (b[bn] == -1 || lv[b[bn]] == lv[an] + 1 && dfs(b[bn])) {
                used[an] = true;
                a[an] = bn; b[bn] = an;
                return true;
            }
        }
        return false;
    }

    int maximum_matching() {
        int match = 0;
        while (1) {
            bfs();

            int flow = 0;
            for (int i = 1; i <= size; ++i) 
                if (!used[i] && dfs(i)) 
                    flow++;
            
            if (!flow) break;
            match += flow;
        }
        return match;
    }
} HK;