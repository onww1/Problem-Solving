#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
bool v[2000];
vector <int> edges[2000];

bool dfs(int node, int cnt) {
    if (cnt == 5) return true;
    v[node] = true;
    for (int next : edges[node]) 
        if (!v[next] && dfs(next, cnt + 1)) {
            v[node] = false;
            return true;
        }
    v[node] = false;
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) 
        if (dfs(i, 1)) {
            ans = 1;
            break;
        }

    printf("%d\n", ans);
    return 0;
}