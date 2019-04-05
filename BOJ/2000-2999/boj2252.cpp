/*
 *  BOJ 2252. 줄 세우기
 *
 *  시간 복잡도 : O(E)
 *  공간 복잡도 : O(V + E)
 *
 *  전체적으로 위상정렬을 하면서 노드를 방문하는대로 노드의 번호를 출력하면 원하는 답을 구할 수 있습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 32000;
int V, E, indegree[MAX + 1];
vector <int> edges[MAX + 1];

int main(int argc, char *argv[]) {
  scanf("%d %d", &V, &E);
  for (int i = 0; i < E; ++i) {
    int hi, lo;
    scanf("%d %d", &hi, &lo);
    edges[hi].push_back(lo);  // hi가 lo의 앞에 서야 한다.
    indegree[lo]++; 
  } 

  queue <int> Q;  // 위상정렬을 위한 큐
  for (int node = 1; node <= V; ++node) {
    // 앞에 서야 한다는게 확실한 친구가 없으면 큐에 넣는다.
    if (!indegree[node]) Q.push(node);
  }

  // Q를 돌면서 한 노드를 방문하면 바로 출력하고, 연결된 노드의 indegree를 줄인다.
  // 이 때, 그 노드의 indegree가 0이 되면 큐에 넣는다.
  while (!Q.empty()) {
    int current = Q.front();
    Q.pop();

    printf("%d ", current);
    for (int next : edges[current]) 
      if (--indegree[next] == 0) Q.push(next);
  }

  return 0;
}