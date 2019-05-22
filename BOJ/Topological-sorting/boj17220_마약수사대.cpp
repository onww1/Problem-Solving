#include <cstdio>
#include <vector>
using namespace std;

int N, M, K, ans, in[26], V[26];
vector <int> edges[26];

void dfs(int node) {
    if (V[node]) return;
    V[node] = 1; ans++;

    for (int next : edges[node]) 
        if (!V[next]) dfs(next);
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        char u, v;
        scanf(" %c %c", &u, &v);
        edges[u - 'A'].push_back(v - 'A');
        in[v - 'A']++;
    }

    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        char u;
        scanf(" %c", &u);
        V[u - 'A'] = 1;
    }

    for (int i = 0; i < 26; ++i) 
        if (!V[i] && !in[i]) {
            dfs(i);
            ans--;
        }
    
    printf("%d\n", ans);
    return 0;
}