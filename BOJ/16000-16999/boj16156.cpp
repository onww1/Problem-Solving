/*
 *  BOJ 16156. 장애물 달리기
 *
 *  시간 복잡도 : O(NMlogNM)
 *  공간 복잡도 : O(NM)
 *
 *  처음에 우선순위 큐에 도착점을 모두 집어넣은 다음, 다익스트라를 돌립니다. 이때 이 거리가 어느 도착점으로부터
 *  온 것인지를 저장합니다. 이후 어떤 시작점에 도달하게 되면 이게 어느 도착점에서 온 것인지를 보고, 그 도착점에 
 *  카운트를 해줍니다. 그렇게 모든 시작점에 대해서 끝내고 나서 모두 출력하면 됩니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair<ll, pii> plii;

const int MAX = 500;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int N, M, MAP[MAX + 1][MAX + 1], C[MAX + 1];
ll dist[MAX + 1][MAX + 1];
priority_queue <plii, vector<plii>, greater<plii>> pq;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf("%d", &MAP[i][j]);
    
    // M이 1이면 시작과 동시에 도착이므로 모두 1이다. (예외 처리)    
    if (M == 1) {
        for (int i = 0; i < N; ++i) puts("1");
        return 0;
    }

    // dist 배열을 초기화하고, 도착점을 우선순위 큐에 넣어준다.
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < N; ++i) {
        dist[i][M - 1] = MAP[i][M - 1];
        pq.push({dist[i][M - 1], {i * M + M - 1, i}});
    }

    while (!pq.empty()) {
        ll weight = pq.top().X;
        int r = pq.top().Y.X / M;
        int c = pq.top().Y.X % M;
        int root = pq.top().Y.Y;
        pq.pop();

        if (dist[r][c] < weight) continue;
        if (c == 0) C[root]++;  // 시작점에 도달했을 때 어느 루트로부터 온 것인지 확인하고 카운트

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
            if (dist[dr][dc] > dist[r][c] + MAP[dr][dc]) {
                dist[dr][dc] = dist[r][c] + MAP[dr][dc];
                pq.push({dist[dr][dc], {dr * M + dc, root}});
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) printf("%d\n", C[i]);
    return 0;
}