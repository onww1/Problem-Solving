#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, M, VC, aM[2001], bM[1001], V[2001];
vector <int> edges[2001];

int dfs(int node) {
    V[node] = VC;
    for (int i = aM[node]; i < edges[node].size(); ++i) {
        int next = edges[node][i];
        if (!bM[next] || (V[bM[next]] != VC && dfs(bM[next]))) {
            aM[node] = i + 1;
            bM[next] = node;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int ret = 0;
    for (int i = 1; i <= 2 * N; ++i) {
        VC++;
        if (dfs(i)) ret++;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 1, len; i <= N; ++i) {
        scanf("%d", &len);
        for (int j = 0, v; j < len; ++j) {
            scanf("%d", &v);
            edges[i].push_back(v);
            edges[i + N].push_back(v);
        }
    }

    printf("%d\n", bipartite_matching());
    return 0;
}