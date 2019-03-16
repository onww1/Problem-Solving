/*
 *  BOJ 8068. Water
 *
 *  시간 복잡도 : O(NMlog(NM))
 *  공간 복잡도 : O(NM)
 *
 *  입력받은 전체 MAP에 대해서 테두리를 미리 벽이라고 표시를 해두고, 이것들을 높이와 함께 우선순위 큐에 모두
 *  넣어 주었습니다. 그런 다음 가장 작은 값부터 뽑아서 그 지점에 인접한 점들을 확인하고, 인접한 지점이 이미 벽이면
 *  무시하고, 벽이 아닌데 자신보다 높거나 같으면 벽으로 만든 후 우선순위 큐에 넣어주고, 자신보다 높이가 낮으면 
 *  높이 차이만큼 ans에 더해주고 시작한 벽의 높이를 높이로 지정해서 우선순위큐에 넣어줍니다. 이때 방문처리를 그냥
 *  벽이랑 같이 해서 다시 접근 못하도록 만들었습니다. 이렇게 쭉 모두 돌면 답이 나옵니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 100;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int R, C, ans, MAP[MAX][MAX];
bool wall[MAX][MAX];
priority_queue <piii, vector<piii>, greater<piii>> pq;

int main(int argc, char *argv[]) {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
        scanf("%d", &MAP[i][j]);
        // 테투리에 있는 지점들은 모두 벽이라고 표시하고, 우선순위 큐에 넣어줍니다.
        if (i == 0 || j == 0 || i == R - 1 || j == C - 1) {
            wall[i][j] = true;  
            pq.push({MAP[i][j], {i, j}});
        }
    }

    while (!pq.empty()) {
        int h = pq.top().X;
        int r = pq.top().Y.X;
        int c = pq.top().Y.Y;
        pq.pop();

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
            if (wall[dr][dc]) continue; // 벽이라면 무시

            wall[dr][dc] = true; // 방문처리
            if (MAP[dr][dc] >= h) { // 이 탐색을 시작했던 높이보다 크거나 같으면 그냥 벽으로 처리
                pq.push({MAP[dr][dc], {dr, dc}});
            } else {    // 탐색을 시작했던 높이보다 작으면 그 차이만큼 답에 더해주고 벽으로 처리
                pq.push({h, {dr, dc}});
                ans += (h - MAP[dr][dc]);
            }
        }
    }

    // 정답을 출력
    printf("%d\n", ans);
    return 0;
}