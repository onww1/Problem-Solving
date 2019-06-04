#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int N, M, K, VC, aM[2001], bM[1001], V[2001];
vector <int> edges[2001];

bool dfs(int node) {
    V[node] = VC;
    for (int i = aM[node]; i < edges[node].size(); ++i) {
        int next = edges[node][i];
        if (!bM[next] || (V[bM[next]] != VC && dfs(bM[next]))) {
            aM[node] = i + 1;
            bM[next] = node;
            return 1;
        }
    }
    return 0;
}

int bipartite_matching() {
    int ret = 0; 
    for (int i = 1; i <= N; ++i) {
        VC++;
        if (dfs(i)) ret++;
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        VC++;
        if (dfs(i + N)) cnt++;
    }
    cnt = min(K, cnt);
    return ret + cnt;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
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