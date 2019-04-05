/*
 *  BOJ 5719. 거의 최단 경로 
 *
 *  시간 복잡도 : O(VlogE)
 *  공간 복잡도 : O(V^2)
 *
 *  다익스트라 알고리즘을 통해서 시작점부터 도착점까지의 최단경로를 찾으면 바로 종료하는 식으로 했고,
 *  이때 그 최단경로를 이루는 경로를 저장해뒀다가, 앞서서 했던 다익스트라가 끝나고 나면 재귀적으로 
 *  그 경로를 역추적하면서 그 간선은 지워진 것이라는 표시를 rm 배열에 해놓고, 그 상태에서 다시 
 *  다익스트라를 돌려서 나온 값을 출력하도록 했습니다.
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

const int MAX = 5e2;
int N, M, S, D, dist[MAX + 1];
bool rm[MAX + 1][MAX + 1];
vector <pii> edges[MAX + 1];
vector <int> path[MAX + 1];

void dijkstra();
void remove_path(int D);

int main(int argc, char *argv[]) {
  while (true) {
    scanf("%d %d", &N, &M);
    if (!N && !M) break;
    scanf("%d %d", &S, &D);

    // 초기화
    memset(rm, false, sizeof(rm));
    for (int i = 0; i < N; ++i) {
      edges[i].clear();
      path[i].clear();
    }

    // 간선 정보 저장
    for (int i = 0, u, v, w; i < M; ++i) {
      scanf("%d %d %d", &u, &v, &w);
      edges[u].push_back({v, w});
    }

    // 최단 경로 구하기 (해당 경로도 함께)
    dijkstra();

    // 최단 경로를 지우기 (재귀적으로)
    remove_path(D);

    // 최단 경로를 지운 상태에서 최단 경로 구하기
    dijkstra();

    // 최단 경로 출력
    printf("%d\n", dist[D] == INF ? -1 : dist[D]);
  }

  return 0;
}

void dijkstra() {
  memset(dist, 0x3f, sizeof(dist));
  priority_queue <pii, vector<pii>, greater<pii>> pq;
  dist[S] = 0;
  pq.push({0, S});

  while (!pq.empty()) {
    int weight = pq.top().X;
    int current = pq.top().Y;
    pq.pop();

    if (current == D) return;

    for (pii next : edges[current]) {
      // 지워진 간선이라면 무시한다.
      if (rm[current][next.X]) continue;

      if (dist[next.X] > weight + next.Y) {
        dist[next.X] = weight + next.Y;
        pq.push({dist[next.X], next.X});

        // 더 짧은 경로라면 이전까지 저장했던 path를 지우고 현재 경로만 저장한다.
        path[next.X].clear();
        path[next.X].push_back(current);
      } else if (dist[next.X] == weight + next.Y) 
        // 이전에 있던 길이와 같으면 이 경로도 추가만 해준다.
        path[next.X].push_back(current);
    }
  }
}

void remove_path(int D) {
  for (int prev : path[D]) {
    rm[prev][D] = true;
    remove_path(prev);
  }
}