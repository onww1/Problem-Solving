#include <cstdio>
#include <vector>
using namespace std;

int N, M, VC, bM[101], V[101];
vector <int> edges[101];

bool dfs(int node) {
    V[node] = VC;
    for (int next : edges[node]) {
        if (!bM[next] || (V[bM[next]] != VC && dfs(bM[next]))) {
            bM[next] = node;
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, a, b; i < M; ++i) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
    } 

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        VC++;
        if (dfs(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}