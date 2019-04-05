/*
 *  BOJ 3109. 빵집
 *
 *  시간 복잡도 : O(RC)
 *  공간 복잡도 : O(RC)
 *
 *  첫 번째 열에서 첫 번째 행부터 시작해서 마지막 행까지 순서대로 출발을 하는데 위에 있는 행일수록
 *  최대한 위쪽 길을 타고 가는게 유리하다는 것을 알 수 있습니다. 그래서 DFS를 할 때, 최대한 위쪽부터
 *  타고 들어가게 한 다음, 만약 그 길이 유효하지 않다면 다음 행에 대한 시도를 할 때도 그 길로 가면 안된다는
 *  것을 알기 때문에 그냥 방문했던 점들을 모두 갈 수 없는 곳으로 바꿨습니다.
 *
 *  그렇게 모든 행에 대해서 시도를 해보고 경로가 있을 때만 ans의 값을 증가시켜서 최종적인 길의 수를 출력했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int move_r[] = {-1, 0, 1};
int R, C, ans = 0;
char MAP[10001][501];

bool DFS(int r, int c) {
    MAP[r][c] = 'x';    // 방문했을 때, 그 점은 다신 못오게 만든다.
    if (c == C - 1) return true;    // 끝까지 갔으면 true를 리턴한다.

    for (int k = 0; k < 3; ++k) {
        int dr = r + move_r[k];
        if (dr < 0 || dr >= R) continue;
        // 다음 점이 갈 수 있는 점이고, DFS를 했을때 끝까지 도달했으면 true를 리턴
        if (MAP[dr][c + 1] == '.' && DFS(dr, c + 1)) return true;
    }
    // 끝까지 못가면 false를 리턴
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) scanf(" %s", MAP[i]);
    
    for (int i = 0; i < R; ++i) 
        if (DFS(i, 0)) ++ans;
    
    printf("%d\n", ans);
    return 0;
}