#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 2e2 + 1;
bool V[MAX];
int N, M, bM[MAX];
vector <int> edges[MAX];

bool dfs(int node) {
    if (V[node]) return false;
    V[node] = true;
    for (int next : edges[node]) {
        if (!bM[next] || dfs(bM[next])) {
            bM[next] = node;
            return true;
        }
    }
    return false;
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

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        memset(V, 0, sizeof(V));
        if (dfs(i)) ans++;
    }

    printf("%d\n", ans);
    return 0;
}