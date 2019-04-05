#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1e4;
int V, E, C;
bool visited[MAX + 1];
vector <int> edges[MAX + 1], redges[MAX + 1], stack, SCC[MAX + 1];

void DFS1(int node) {
    visited[node] = true;
    for (int next : edges[node]) 
        if (!visited[next]) DFS1(next);
    stack.push_back(node);
}

void DFS2(int node, int color) {
    visited[node] = true;
    SCC[color].push_back(node);
    for (int next : redges[node]) 
        if (!visited[next]) DFS2(next, color);
}

bool cmp(vector <int> A, vector <int> B) {
    return A[0] < B[0];
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &V, &E);
    for (int i = 0, A, B; i < E; ++i) {
        scanf("%d %d", &A, &B);
        edges[A].push_back(B);
        redges[B].push_back(A);
    }

    for (int i = 1; i <= V; ++i) 
        if (!visited[i]) DFS1(i);
    
    memset(visited, false, sizeof(visited));
    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();

        if (!visited[node]) 
            DFS2(node, C++);
    }

    for (int i = 0; i < C; ++i) sort(SCC[i].begin(), SCC[i].end());
    sort(SCC, SCC + C, cmp);

    printf("%d\n", C);
    for (int i = 0; i < C; ++i) {
        for (int node : SCC[i]) printf("%d ", node);
        puts("-1");
    }
  
    return 0;
}