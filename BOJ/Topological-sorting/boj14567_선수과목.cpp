#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX = 1e3 + 1;
int n, m, in[MAX], d[MAX];
vector<int> edges[MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!in[i]) {
        d[i] = 1;
        q.push(i);
    }
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next: edges[node])
            if (--in[next] == 0) {
                q.push(next);
                d[next] = d[node] + 1;
            }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", d[i]); puts("");
    return 0;
}