#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1e5;
int N, R, Q, U, V, C[MAX + 1];
vector <int> edges[MAX + 1];

int dfs(int node, int parent) {
  C[node] = 1;
  for (int next : edges[node]) 
    if (next != parent) {
      C[node] += dfs(next, node);
    }
  return C[node];
}

int main(int argc, char *argv[]) {
  scanf("%d %d %d", &N, &R, &Q);
  for (int i = 1; i < N; ++i) {
    scanf("%d %d", &U, &V);
    edges[U].push_back(V);
    edges[V].push_back(U);
  }

  dfs(R, 0);

  while (Q--) {
    scanf("%d", &U);
    printf("%d\n", C[U]);
  }

  return 0;
}