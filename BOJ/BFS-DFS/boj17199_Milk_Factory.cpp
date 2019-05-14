#include <cstdio>
#include <vector>
using namespace std;

int N, cnt;
vector <int> edges[101];

void dfs(int node, int pa) {
    cnt++;
    for (int next : edges[node]) 
        if (next != pa) 
            dfs(next, node);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, u, v; i < N; ++i) {
        scanf("%d %d", &u, &v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        cnt = 0;
        dfs(i, 0);
        if (cnt == N) 
            return !printf("%d\n", i);
    }
  
    puts("-1");
    return 0;
}