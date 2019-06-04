#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1e3 + 1;
int N, M, visitCnt, aM[MAX], bM[MAX], V[MAX];
vector <int> edges[MAX];

bool dfs(int node) {
    if (V[node] == visitCnt) return false;
    V[node] = visitCnt;

    for (int i = aM[node]; i < edges[node].size(); ++i) {
        int next = edges[node][i];
        if (!bM[next] || dfs(bM[next])) {
            aM[node] = i + 1;
            bM[next] = node;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        visitCnt++;
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
        }
    }

    printf("%d\n", bipartite_matching());
    return 0;
}