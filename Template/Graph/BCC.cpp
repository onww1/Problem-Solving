struct BCC {
    int size, group_count, bcc_count, visit_count;
    vector<vector<int>> edges;
    vector<vector<pii>> bcc;
    vector<pii> _stack;
    vector<int> visit;

    void init(int _size) {
        size = _size;
        group_count = bcc_count = visit_count = 0;
        edges.clear(); bcc.clear(); _stack.clear(); visit.clear(); 
        edges.resize(size + 1);
        visit.resize(size + 1, 0);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int dfs(int node, int parent) {
        int low = visit[node] = ++visit_count;
        for (int next: edges[node]) {
            if (next == parent) continue;
            if (visit[node] > visit[next]) _stack.push_back({node, next});
            if (visit[next]) low = min(low, visit[next]);
            else {
                int ret = dfs(next, node);
                low = min(low, ret);
                if (visit[node] <= ret) {
                    pii current_edge = {node, next};
                    bcc.push_back(vector<pii>());
                    while (!_stack.empty() && _stack.back() != current_edge) {
                        bcc[bcc_count].push_back(_stack.back());
                        _stack.pop_back();
                    }
                    bcc[bcc_count++].push_back(_stack.back());
                    _stack.pop_back();
                }
            }
        }
        return low;
    }

    void biconnected_component() {
        for (int node = 1; node <= size; ++node) 
            if (!visit[node]) {
                group_count++;
                dfs(node, node);
            }
    }
} BCC;