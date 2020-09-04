struct SCC_Kosaraju {
    int size, scc_count;
    vector<vector<int>> edges, redges, scc;
    vector<int> _stack, visit, group;

    void init(int _size) {
        this->size = _size;
        edges.resize(this->size + 1);
        redges.resize(this->size + 1);
        visit.resize(this->size + 1, 0);
        group.resize(this->size + 1, -1);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        redges[v].push_back(u);
    }

    void dfs(int node) {
        visit[node] = 1;
        for (int next: edges[node]) 
            if (!visit[next])
                dfs(next);
        _stack.push_back(node);
    }

    void rdfs(int node, int group_number) {
        visit[node] = 0;
        group[node] = group_number;
        scc[group_number].push_back(node);
        for (int next: redges[node])
            if (visit[next])
                rdfs(next, group_number);
    }

    void strongly_connected_component() {
        for (int node = 1; node <= this->size; ++node) 
            if (!visit[node])
                dfs(node);
        while (!_stack.empty()) {
            int node = _stack.back();
            _stack.pop_back();
            if (visit[node]) {
                scc.push_back(vector<int>());
                rdfs(node, scc_count++);
            }
        }
    }
};