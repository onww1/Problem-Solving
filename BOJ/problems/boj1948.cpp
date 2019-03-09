/*
 *  BOJ 1948. 임계경로
 *
 *  시간 복잡도 : O(V + E)
 *  공간 복잡도 : O(E)
 *
 *  위상 정렬을 통해서 출발지로부터 각 노드의 최장 거리를 구하면서 그 때의 직전 노드도 저장합니다.
 *  그렇게 도착지까지의 최장거리를 구하고, 도착지부터 시작해서 이전에 저장했던 노드들을 타고 역으로 가면서
 *  쉬지 않고 달려야 하는 경로의 수를 세어주었습니다.
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

const int MAX = 1e4;
int N, M, S, D, C, dist[MAX + 1], indegree[MAX + 1];
bool visited[MAX + 1];
vector <int> pa[MAX + 1];
vector <pii> edges[MAX + 1];

// 쉬지 않고 달려야 하는 도로를 카운트
void DFS(int node) {
    // 방문 했었으면 리턴
    if (visited[node]) return;
    visited[node] = true;

    for (int prev : pa[node]) {
        ++C; // 연결되는건 다 카운트.
        DFS(prev);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, U, V, W; i < M; ++i) {
        scanf("%d %d %d", &U, &V, &W);
        edges[U].push_back({V, W});
        indegree[V]++;
    }
    scanf("%d %d", &S, &D);

    // 시작점을 큐에 넣어준다.
    queue <int> Q;
    Q.push(S);

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        // 인접한 노드에 대해서 거리를 갱신하고, 나가는 간선을 제거한다.
        for (pii next : edges[current]) {
            if (dist[current] + next.Y > dist[next.X]) {
                dist[next.X] = dist[current] + next.Y;
                // 최장 거리로 만든 노드를 pa에 달아준다.
                pa[next.X].clear();
                pa[next.X].push_back(current);
            } 
            else if (dist[current] + next.Y == dist[next.X])
                pa[next.X].push_back(current);  // 길이가 같으므로 pa에 달아준다.

            indegree[next.X]--;
            if (!indegree[next.X]) Q.push(next.X);
        }
    }

    DFS(D); // 쉬지 않고 달려야 하는 거리를 카운트
    printf("%d\n%d\n", dist[D], C);
    return 0;
}