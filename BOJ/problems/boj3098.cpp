/*
 *  BOJ 3098. 소셜네트워크
 *
 *  시간 복잡도 : O(N^3 * logN)
 *  공간 복잡도 : O(N^2)
 *
 *  플로이드 워셜 알고리즘을 이용하였습니다. 
 *  무한루프를 돌면서 새로 생기는 친구 관계를 카운트해주는데, i와 j가 친구관계가 아니었으면
 *  그 둘이 동시에 친구인 사람을 찾았을 때 서로 친구로 이어줍니다. 이게 이전에 구했던 친구관계를 통해서
 *  그것을 확인해야 했기 때문에 친구관계에 대한 그래프를 2개를 두고, 스위핑(?)같이 해주었습니다.
 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 50;
int N, M;
bool MAP[2][MAX + 1][MAX + 1];
vector <int> F;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, u, v; i < M; ++i) {
        scanf("%d %d", &u, &v);
        MAP[0][u][v] = MAP[0][v][u] = true; // 양방향 표시
    }

    while (1) {
        int cnt = 0;   // 새로 생기는 친구 관계 카운트 
        for (int i = 1; i <= N; ++i) { 
            for (int j = i + 1; j <= N; ++j) {
                // 친구관계가 아니었으면 동시에 친구인 친구를 찾음.
                if (i != j && !MAP[0][i][j]) {
                    for (int k = 1; k <= N; ++k) {
                        if (MAP[0][i][k] && MAP[0][k][j]) {
                            cnt++;
                            MAP[1][i][j] = MAP[1][j][i] =true;
                            break;
                        }
                    }
                }
                // 원래 친구관계이면 그냥 옮겨줌.
                else MAP[1][i][j] = MAP[1][j][i] = MAP[0][i][j];
            }
        }

        // 새로 생긴 친구 관계가 있으면 벡터에 넣고 없으면 무한루프를 종료시킴.
        if (cnt) F.push_back(cnt);
        else break;

        // 새로 만들어진 친구관계를 0으로 옮김
        for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) {
            MAP[0][i][j] = MAP[1][i][j];
            MAP[1][i][j] = false;
        }
    }

    printf("%lu\n", F.size());
    for (int num : F) printf("%d\n", num);
    return 0;
}