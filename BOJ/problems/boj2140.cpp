/*
 *  BOJ 2140. 지뢰찾기
 *
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(N^2)
 *
 *  꼭짓점부터 큐에 넣고서 테두리부분을 점차 넓혀갑니다.
 *  그렇게 하면 불확실한 점이 1개씩밖에 안나오는데 그것이 지뢰인지 아닌지 체크해서 테두리와 인접한
 *  부분에 대해서 확실하게 구해주고, 더 안쪽은 모두 지뢰라고 가정하고 최댓값을 구합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e2;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int N, ans, MAP[MAX][MAX];
bool visited[MAX][MAX];
char in[MAX + 1];
queue <pii> Q;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", in);
        for (int j = 0; in[j]; ++j) {
            if ('0' <= in[j] && in[j] <= '9') MAP[i][j] = in[j] - '0';
            else MAP[i][j] = -1;
        }
    }

    // N == 1이면 지뢰 없음
    if (N == 1) return !printf("0\n");

    // 꼭짓점을 큐에 넣어줌
    for (int i = 0; i < N; i += N - 1) for (int j = 0; j < N; j += N - 1) {
        Q.push({i, j});
        visited[i][j] = true;
    }
    
    while (!Q.empty()) {
        int r = Q.front().X;
        int c = Q.front().Y;
        Q.pop(); 

        // 불확실한 점을 저장할 변수
        pii V = {-1, -1};
        for (int k = 0; k < 8; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
            
            // 지뢰인지 아닌지 확실한 점을 만났을 때,
            if (MAP[dr][dc] >= 10) MAP[r][c] -= (MAP[dr][dc] - 10);
            // 아직 방문하지 않았던 점
            else if (!visited[dr][dc]) {
                visited[dr][dc] = true;
                if (MAP[dr][dc] == -1) {   // 지뢰인지 아닌지 확실하지 않은 점
                    V = {dr, dc};
                } else {    // 테두리 점
                    Q.push({dr, dc});
                }
            }
        }

        if (V.X != -1) {    // 지뢰인지 아닌지 확실하지 않은 점이 존재하는 경우
            if (MAP[r][c]) MAP[V.X][V.Y] = 11, ans++;   // 현재 점의 값이 1이면 지뢰
            else MAP[V.X][V.Y] = 10;    // 현재 점의 값이 0이면 지뢰 아님
            MAP[r][c] = 0;
        }
    }

    // 안쪽에 칸이 더 있는경우 그 넓이를 더해줌.
    if (N - 4 > 0) ans += (N - 4) * (N - 4);
    printf("%d\n", ans);

    return 0;
}

