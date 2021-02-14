#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int _find(vector<int>& pa, int u) {
        if (pa[u] == u) return u;
        return pa[u] = _find(pa, pa[u]);
    }

    void _union(vector<int>& pa, int u, int v) {
        u = _find(pa, u); 
        v = _find(pa, v);
        pa[u] = v;
    }

    void make_enemy(vector<int>& pa, int u, int v, int n) {
        _union(pa, u + n, v);
        _union(pa, u, v + n);
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> pa(2 * n);
        for (int i = 0; i < 2 * n; i++) 
            pa[i] = i;
        for (int from = 0; from < n; from++) 
            for (int to: graph[from]) 
                make_enemy(pa, from, to, n);
         bool bipartite = true;
         for (int i = 0; i < n; i++) 
             if (_find(pa, i) == _find(pa, i + n)) {
                 bipartite = false;
                 break;
             }
         return bipartite;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> graph = {
        {{1, 3}, {0, 2}, {1, 3}, {0, 2}},
        {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}
    };

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < graph.size(); i++)
        ret.push_back(solution.isBipartite(graph[i]));

    /* Answer */
    vector<bool> answer = {true, false};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
