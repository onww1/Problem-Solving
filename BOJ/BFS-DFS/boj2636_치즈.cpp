/*
 *  BOJ 2636. 치즈
 *
 *  시간 복잡도 : O(RC)
 *  공간 복잡도 : O(RC)
 *
 *  테두리에 공기를 추가하고, (0, 0)에서부터 시작해서 BFS를 합니다.
 *  이때 큐를 2개 두고, 0인 부분은 현재 큐에 넣고, 1인 부분은 다른 큐에 넣어서 시간이 지남에 따라
 *  치즈가 녹는 것을 구현합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 100;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int R, C, _count, _prev;
bool MAP[MAX + 2][MAX + 2], visited[MAX + 2][MAX + 2];

int main(int argc, char *argv[]) {
    scanf("%d %d", &R, &C);
    for (int i = 1, A; i <= R; ++i) for (int j = 1; j <= C; ++j) {
        scanf("%d", &A);
        MAP[i][j] = A;
        if (A) _count++;    // 치즈의 갯수를 세준다.
    }

    queue <pii> Q[2];
    Q[0].push({0, 0});
    visited[0][0] = true;
    _prev = _count; // 녹기 전의 값을 저장

    int T = 0;
    while (1) {

        // 현재 상태에서 0인 부분은 모두 그대로 이동하고, 1인 부분만 반대 큐에 저장
        while (!Q[T % 2].empty()) {
            int r = Q[T % 2].front().X;
            int c = Q[T % 2].front().Y;
            Q[T % 2].pop();

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr > R + 1 || dc < 0 || dc > C + 1) continue;
                if (!visited[dr][dc]) {
                    visited[dr][dc] = true;

                    // 치즈인 경우 녹기 전이므로 반대 큐에 저장
                    if (MAP[dr][dc]) Q[1 - T % 2].push({dr, dc});
                    // 공기인 경우 현재 큐에 넣어 계속 탐색
                    else Q[T % 2].push({dr, dc});
                }
            }
        }

        // 반대 큐에 값이 없으면 녹을 치즈가 없는 것이므로 현재 결과를 출력하고 끝낸다.
        if (Q[1 - T % 2].empty()) {
            printf("%d\n%d\n", T, _prev);
            break;
        }

        // 녹인 후의 수를 얻기 전에 현재 값을 이전이라고 저장한다.
        _prev = _count;

        // 현재 치즈의 수를 줄인다.
        _count -= Q[1 - T % 2].size();

        // 시간을 증가시킨다.
        T++;
    }
    
    return 0;
}