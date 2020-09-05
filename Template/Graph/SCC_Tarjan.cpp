struct SCC_Tarjan {
    int size, scc_count, visit_count;
    vector<vector<int>> edges, scc;
    vector<int> _stack, visit, group;

    void init(int _size) {
        this->size = _size;
        scc_count = visit_count = 0;
        edges.clear(); scc.clear();
        _stack.clear(); visit.clear(); group.clear();
        edges.resize(this->size + 1);
        visit.resize(this->size + 1, 0);
        group.resize(this->size + 1, -1);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
    }

    int dfs(int node) {
        visit[node] = ++visit_count;
        int low = visit[node];
        _stack.push_back(node);
        for (int next: edges[node]) {
            if (!visit[next]) 
                low = min(low, dfs(next));
            else if (group[next] == -1) 
                low = min(low, visit[next]);
        }
        if (low == visit[node]) {
            scc.push_back(vector<int>());
            while (!_stack.empty()) {
                int pop_node = _stack.back();
                _stack.pop_back();
                scc.back().push_back(pop_node);
                group[pop_node] = scc_count;
                if (node == pop_node) break;
            }
            scc_count++;
        }
        return low;
    }

    void strongly_connected_component() {
        for (int node = 1; node <= this->size; ++node) 
            if (!visit[node])
                dfs(node);
    }
};