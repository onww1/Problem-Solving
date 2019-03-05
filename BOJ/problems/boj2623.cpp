/*
 *  BOJ 2623. 음악프로그램 
 *
 *  시간 복잡도 : O(E)
 *  공간 복잡도 : O(V + E) 
 *
 *  주어진 인풋을 적절히 잘 정리해 놓고, 위상정렬을 통해서 방문한 애들을 순서대로 저장해둡니다.
 *  만약 방문한 노드의 수가 N보다 작다면 전체 방문이 되지 않은 것이므로 0을 출력하고, 
 *  방문한 노드의 수가 N이라면 전체 방문한 것이므로 순서대로 출력합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000;
int N, M, indegree[MAX + 1];
vector <int> edges[MAX + 1], ans;

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &M);
  for (int i = 0, len = 0, u = 0, v = 0; i < M; ++i) {
    scanf("%d %d", &len, &v);
    // 인접한 애들에 대해서 추가해줌.
    while (--len) {
      u = v;
      scanf("%d", &v);  
      edges[u].push_back(v);  
      indegree[v]++;
    }
  }

  queue <int> Q;
  for (int node = 1; node <= N; ++node) 
    if (!indegree[node]) Q.push(node); // 반드시 앞에 해야 하는 가수가 없다면 큐에 추가

  while (!Q.empty()) {
    int current = Q.front();
    Q.pop();

    // 방문한 노드를 ans 벡터에 넣어줌.
    ans.push_back(current);
    for (int next : edges[current]) 
      if (--indegree[next] == 0) Q.push(next);
  }

  if (ans.size() < N) puts("0");
  else for (int node : ans) printf("%d\n", node);

  return 0;
}