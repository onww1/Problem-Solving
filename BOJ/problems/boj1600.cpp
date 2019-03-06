/*
 *	BOJ 1600. 말이 되고픈 원숭이 
 *
 *	시간 복잡도 : O(N^2 * K)
 *	공간 복잡도 : O(N^2 * K)
 *
 *	일반적인 BFS에서 K가 제한되어 있으니 K에 대한 차원도 추가하여 K까지 고려한 visited를 적용했습니다.
 *	그러한 상황에 대해서 그저 똑같이 BFS를 하다가 도착점을 만나면 그 값을 출력하도록 했습니다.
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

const int MAX = 200;
const int move_r[] = {-1, 0, 1, 0, -2, -2, -1, -1, 1, 1, 2, 2};
const int move_c[] = {0, -1, 0, 1, -1, 1, -2, 2, -2, 2, -1, 1};

int K, R, C, MAP[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1][31];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &K, &C, &R);
    for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) scanf("%d", &MAP[i][j]);

    queue <piii> Q;
    Q.push({0, {0, 0}});
    visited[0][0][0] = true;

    int T = 0, size = 0;
    while (!Q.empty()) {
        size = Q.size();	// 한 타임에 대해서만 해야하므로 그 상황에서의 size를 저장
        for (int i = 0; i < size; ++i) {
            int current_K = Q.front().X;
            int r = Q.front().Y.X;
            int c = Q.front().Y.Y;
            Q.pop();

            if (r == R - 1 && c == C - 1) 	// 도착점을 만나면 바로 현재 시간 출력
                return !printf("%d\n", T);

            // 인접한 곳으로 이동하는 Case
            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
                if (!visited[dr][dc][current_K] && !MAP[dr][dc]) {
                    Q.push({current_K, {dr, dc}});
                    visited[dr][dc][current_K] = true;
                }
            }

            // 아직 K를 다 사용하지 않았으면 말의 이동 방향으로도 이동한다.
            if (current_K < K) {
                for (int k = 4; k < 12; ++k) {
                    int dr = r + move_r[k];
                    int dc = c + move_c[k];
                    if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
                    if (!visited[dr][dc][current_K + 1] && !MAP[dr][dc]) {
                        Q.push({current_K + 1, {dr, dc}});
                        visited[dr][dc][current_K + 1] = true;
                    }
                }
            }
        }
        T++;
    }

    puts("-1");
    return 0;
}