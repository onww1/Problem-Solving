/*
 *  BOJ 1848. 동굴탐험 
 *
 *  시간 복잡도 : O(ElogV)
 *  공간 복잡도 : O(V + E)
 *
 *  도저히 어떻게 풀지 모르겠어서 결국 rdd6584님의 풀이를 보고 했습니다.
 *  
 *  맨 처음에 시작점과 인접한 노드들을 모두 우선순위 큐에 넣은 다음 다익스트라를 돌립니다.
 *  이때, 각 노드의 최단거리를 구하고 이게 어느 노드에서부터 온 최단거리인지를 저장해줍니다.
 *  그 다음 모든 간선을 뒤집어서 시작점과 인접한 노드들에 대해서 하나씩 다익스트라를 돌리고, 
 *  특정 점에 도달했을 때, 그 지점의 color가 현재 color와 다르면 두 거리의 합을 답의 후보로 사용합니다.
 *  그렇게 여러 후보중에서 가장 작은 값을 답으로 취합니다.
 *
 *  갓디디..
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

struct Node {
    int w, v, p;
    bool operator< (const Node &other) const {
        return w > other.w;
    }
};

const int MAX = 5000;
int N, M, dist[MAX + 1], dist2[MAX + 1], P[MAX + 1];
priority_queue <Node> pq;
vector <pii> edges1[MAX + 1], edges2[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, A, B, C, D; i < M; ++i) {
        scanf("%d %d %d %d", &A, &B, &C, &D);
        // 정방향 간선
        edges1[A].push_back({C, B});
        edges1[B].push_back({D, A});

        // 역방향 간선
        edges2[A].push_back({D, B});
        edges2[B].push_back({C, A});
    }

    memset(dist, 0x3f, sizeof(dist));
    memset(P, -1, sizeof(P));
    dist[1] = 0;
    for (pii next : edges1[1]) { // 시작점과 인접한 노드들을 모두 pq에 넣는다.
        pq.push({ next.X, next.Y, next.Y });
        dist[next.Y] = next.X;
    }

    // 정방향 간선으로 다익스트라를 돌려서 최단거리를 저장하는데, 이때 이게 어디서 온건지를 저장한다.
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (dist[current.v] < current.w) continue;
        P[current.v] = current.p;

        for (pii next : edges1[current.v]) {
            if (dist[next.Y] > next.X + current.w) {
                dist[next.Y] = next.X + current.w;
                pq.push({ dist[next.Y], next.Y, current.p });
            }
        }
    }

    int ans = INF;
    for (pii next : edges2[1]) {
        // 역방향 간선에 대해서 시작점과 인접한 노드 하나씩 확인한다.
        int color = next.Y;
        memset(dist2, 0x3f, sizeof(dist2));

        pq.push({ next.X, color, 1 });
        dist2[color] = next.X;
        dist2[1] = 0;   // 다익스트라 처음에 시작점으로 가지 못하게 0으로 초기화

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (dist2[current.v] < current.w) continue;
            if (P[current.v] != color) {
                // 어떤 점에 최단거리로 도착했을 때, 컬러가 다르면 둘의 합을 가지고 ans와 비교한다.
                ans = min(ans, current.w + dist[current.v]);
                continue;
            }

            for (pii next : edges2[current.v]) {
                if (dist2[next.Y] > next.X + current.w) {
                    dist2[next.Y] = next.X + current.w;
                    pq.push({ dist2[next.Y], next.Y, 1 });
                }
            }

            // 첫 점에 인접한 값을 다 확인하고서 시작점을 INF로 바꿔준다.
            if (current.v == color) dist2[1] = INF;
        }
    }

    printf("%d\n", ans);
    return 0;
}