/*
 *  BOJ 1753. 최단경로 
 *  
 *  시간 복잡도 : O(VlogE)
 *  공간 복잡도 : O(E)
 *
 *  다익스트라 알고리즘 기본 문제였습니다.
 *  간선에 대한 정보를 모두 입력받고, 거리 배열의 값을 모두 무한대로 초기화 해줍니다.
 *  그리고 시작점에 대해서만 거리를 0으로 바꾼 다음 우선순위큐에 넣어줍니다.
 *  그 상황에서 방문한 점을 기준으로 거리를 모두 갱신해나가면서 쭉 돕니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 2e4;
const int INF = 0x3f3f3f3f;
int V, E, K, dist[MAX + 1];
vector <pii> edges[MAX + 1];
priority_queue <pii, vector<pii>, greater<pii>> pq;

int main(int argc, char *argv[]) {
  scanf("%d %d %d", &V, &E, &K);
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges[u].push_back({v, w});
  }

  // 거리 배열의 값을 모두 무한대로 초기화하고, 시작점만 0으로 만든다.
  memset(dist, 0x3f, sizeof(dist));
  dist[K] = 0;
  pq.push({0, K});

  // 우선순위 큐에서 가장 작은 가중치를 뽑아서 다른 거리들도 계속 갱신해 나갑니다.
  while (!pq.empty()) {
    int node = pq.top().Y;
    int weight = pq.top().X;
    pq.pop();

    if (dist[node] < weight) continue;

    for (pii next : edges[node]) {
      if (dist[next.X] > weight + next.Y) {
        dist[next.X] = weight + next.Y;
        pq.push({dist[next.X], next.X});
      }
    }
  }

  // 값들을 모두 출력
  for (int i = 1; i <= V; ++i) {
    if (dist[i] == INF) puts("INF");
    else printf("%d\n", dist[i]);
  }

  return 0;
}