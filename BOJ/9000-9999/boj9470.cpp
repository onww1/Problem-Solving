/*
 *  BOJ 9470. Strahler 순서 
 *
 *  시간 복잡도 : O(E + VlogV)
 *  공간 복잡도 : O(E)
 *
 *  각 노드별로 들어오는 간선, 나가는 간선, 순서를 저장할 공간을 만들고, 
 *  들어오는 인풋에 대하여 들어오는 간선, 나가는 간선을 저장해줍니다. 
 *  그리고 들어오는 간선이 0인 노드들을 큐에 넣으면서 위상정렬과 같은 방식으로 진행하고, 
 *  그 과정에서 인접한 노드에 자신의 순서를 저장합니다. 
 *  그렇게 자신의 차례가 되었을 때, 저장된 인접한 노드들의 순서를 보고 자신의 순서를 정합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

const int MAX = 1000;
int T, K, M, P, S, A[MAX + 1], indegree[MAX + 1];
vector <int> edges[MAX + 1];
vector <int> in[MAX + 1];

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &K, &M, &P);

    // 초기화
    for (int node = 1; node <= M; ++node) {
      edges[node].clear();
      in[node].clear();
      indegree[node] = A[node] = 0;
    }

    // 간선을 저장하고, 들어오는 간선의 수를 세어줍니다.
    for (int i = 0; i < P; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      edges[u].push_back(v);
      indegree[v]++;
    }

    // 들어오는 간선이 없는 노드들을 큐에 넣고, 순서를 1로 놓습니다.
    queue <int> Q;
    for (int node = 1; node <= M; ++node) {
      if (!indegree[node]) {
        Q.push(node);
        A[node] = 1;
      }
    }

    S = 1;
    while (!Q.empty()) {
      int current = Q.front();
      Q.pop();

      // 자신에게 들어오는 간선이 존재하는 노드의 순서들을 정렬합니다.
      sort(in[current].begin(), in[current].end(), greater<int>());

      // 하나밖에 없으면 그것과 같고, 2개 이상이면서 가장 큰 수가 2개 이상이면 그 수보다 하나 큰 값, 
      // 아니면 그 값과 같은 값이 됩니다.
      if (in[current].size() == 1) A[current] = in[current][0];
      else if (in[current].size() > 1) {
        if (in[current][0] == in[current][1]) A[current] = in[current][0] + 1;
        else A[current] = in[current][0];
      } 
      S = max(S, A[current]);

      // 인접한 노드들에 대해서 indegree를 줄이고, 자신으 순서를 추가시킵니다.
      for (int next : edges[current]) {
        in[next].push_back(A[current]);
        indegree[next]--;
        if (!indegree[next]) Q.push(next);
      }
    }

    printf("%d %d\n", K, S);
  }

  return 0;
}