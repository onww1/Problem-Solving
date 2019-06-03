#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;
int N, M, C, in[MAX], V[MAX], SCC[MAX];
vector <int> edges[MAX], inv[MAX];
vector <int> st;

void dfs1(int node) {
    V[node] = true;
    for (int next : edges[node]) {
        if (V[next]) continue;
        dfs1(next);
    }
    st.push_back(node);
}

void dfs2(int node, int scc) {
    V[node] = true; SCC[node] = scc;
    for (int next : inv[node]) {
        if (V[next]) continue;
        dfs2(next, scc);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, u, v; i < M; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        inv[v].push_back(u);
    }
  
    for (int i = 0; i < N; ++i) 
        if (!V[i]) dfs1(i);
    
    memset(V, 0, sizeof(V));
    while (!st.empty()) {
        int node = st.back(); st.pop_back();
        if (!V[node]) dfs2(node, ++C);
    }

    for (int i = 0; i < N; ++i) 
        for (int edge : edges[i]) 
            if (SCC[i] != SCC[edge]) 
                in[SCC[edge]]++;

    int ans = 0;
    for (int i = 1; i <= C; ++i) if (!in[i]) ++ans;
    printf("%d\n", ans);
    return 0;
}