/*
 *  BOJ 14588. Line Friends (Small)
 *
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N)
 *
 *  각 캐릭터의 구간을 입력을 받은 다음, N^2 루프를 돌면서 구간이 겹치는 캐릭터끼리는 서로 연결된 것으로
 *  간주하여 edges에 추가해줍니다. 그렇게 모든 간선을 추가하고 난 뒤, 쿼리에 대하여 BFS를 돌려서 거리를
 *  출력해주도록 하였습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 300;
int N, Q, X[MAX + 1], Y[MAX + 1];
vector <int> edges[MAX + 1];

int BFS(int u, int v) {
    bool visited[MAX + 1]{};
    queue <int> q;
    q.push(u); visited[u] = true;
    int dist = 0, size = 0;
    while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
            int cur = q.front();
            q.pop();

            if (cur == v) return dist;

            for (int next : edges[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        dist++;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, L, R; i <= N; ++i) scanf("%d %d", X + i, Y + i);

    // 구간이 겹치면 i와 j를 연결된 것으로 생각하고 간선을 추가
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (Y[i] < X[j] || X[i] > Y[j]) continue;
            edges[i].push_back(j);
            edges[j].push_back(i);
        }
    }

    scanf("%d", &Q);
    for (int i = 0, A, B; i < Q; ++i) {
        scanf("%d %d", &A, &B);
        printf("%d\n", BFS(A, B));
    }

    return 0;
}