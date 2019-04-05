/*
 *  BOJ 2573. 빙산
 *  
 *  시간 복잡도 : O(TNM)
 *  공간 복잡도 : O(NM)
 *
 *  입력을 받을 때, 빙하의 수를 카운트해서 가지고 있습니다.
 *  이후 전체를 확인하면서 아직 방문안한 빙하가 있으면 그 지점에서 BFS를 시작합니다.
 *  이때 전체 빙하의 갯수를 알고 있는 상태이므로 BFS를 할 떄 빙하의 수를 카운트하고,
 *  이게 전체보다 작으면 두 덩이라고 생각하고 거기까지만 출력을 합니다.
 *  근데 만약 전체와 같다면 BFS를 돌면서 체크했던 녹여야 하는 빙하들을 적용시켜주고, 
 *  전체 빙하의 갯수가 0이 되면 전체가 동시에 녹았다고 판단하고 0을 출력합니다.
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
typedef pair<int, pii> piii;

const int MAX = 300;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int N, M, R, T, MAP[MAX][MAX];
bool visited[MAX][MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        scanf("%d", &MAP[i][j]);
        if (MAP[i][j]) R++; // 빙하의 수를 카운트
    }

    bool main_loop = true;
    while (main_loop) {
        memset(visited, 0, sizeof(visited));

        bool loop = true;
        for (int i = 0; loop && i < N; ++i) {
            for (int j = 0; loop && j < M; ++j) {
                if (!visited[i][j] && MAP[i][j]) {
                    loop = false;

                    queue <pii> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    int cnt = 0; // 빙하의 수 카운트
                    vector <piii> v; // 녹일 것 저장
                    while (!q.empty()) {
                        int r = q.front().X;
                        int c = q.front().Y;
                        q.pop();

                        cnt++;
                        int zeros = 0;
                        for (int k = 0; k < 4; ++k) {
                            int dr = r + move_r[k];
                            int dc = c + move_c[k];
                            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
                            if (!MAP[dr][dc]) zeros++;  // 바다의 수 카운트
                            else if (!visited[dr][dc] && MAP[dr][dc]) {
                                q.push({dr, dc});
                                visited[dr][dc] = true;
                            }
                        }

                        // 주변에 바다가 있으면 v 벡터에 추가시킨다.
                        if (zeros) v.push_back({zeros, {r, c}});
                    }

                    // 덩어리가 두 개인 경우
                    if (cnt < R) {
                        printf("%d\n", T);
                        main_loop = false;
                        break;
                    }

                    // 녹여야 할 곳을 다 녹여준다.
                    for (piii node : v) {
                        MAP[node.Y.X][node.Y.Y] -= node.X;
                        if (MAP[node.Y.X][node.Y.Y] <= 0) {
                            MAP[node.Y.X][node.Y.Y] = 0;
                            R--;
                        }
                    }

                    // 한 번에 다같이 녹은 경우
                    if (R == 0) {
                        printf("%d\n", 0);
                        main_loop = false;
                    }
                }
            }
        }

        // 시간을 증가시킨다.
        T++;
    }

    return 0;
}