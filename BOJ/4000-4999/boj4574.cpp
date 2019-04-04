/*
 *  BOJ 4574. 스도미노쿠
 *
 *  시간 복잡도 : O(9^(72 - 2 * N))   (겹치는거 제외하면 엄청 줄어듬)
 *  공간 복잡도 : O(9^2)
 *
 *  백트래킹!!
 *  먼저 스도쿠 로직으로만 수들을 배열한 다음, 마지막에 스도미노쿠가 되는지를 확인하는 식으로 했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, MAP[9][9], A, B;
bool visited[27][10], pchk[10][10], chk[9][9];
char PA[3], PB[3];

// 방문체크를 해주는 함수
void visit(int r, int c, bool v, int a) {
    MAP[r][c] = v ? a : 0;
    visited[r][a] = v;
    visited[c + 9][a] = v;
    visited[r / 3 * 3 + c / 3 + 18][a] = v;
}

// (r, c)에 v라는 수를 놓을 수 있는지 확인하는 함수
bool isPossible(int r, int c, int v) {
    return !(visited[r][v] || visited[c + 9][v] || visited[r / 3 * 3 + c / 3 + 18][v]);
}

// 전체적으로 숫자들을 배열했을 때, 스도미노쿠가 되는지 확인하는 함수
bool check(int r, int c) {
    // r이 9까지 도달하면 전체를 다 확인한 것이므로 true 리턴
    if (r == 9) return true;

    // 다음 행, 열을 계산
    int next_r = r, next_c = c + 1;
    if (next_c == 9) next_r++, next_c = 0;

    // 이미 확인된 곳이면 다음 것 호출
    if (chk[r][c]) return check(next_r, next_c);

    // 상하좌우에 체크 안된 것들 중에서 선택해서 재귀호출
    for (int k = 0; k < 4; ++k) {
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (dr < 0 || dr >= 9 || dc < 0 || dc >= 9) continue;
        if (chk[dr][dc] || pchk[MAP[r][c]][MAP[dr][dc]]) continue;
        pchk[MAP[r][c]][MAP[dr][dc]] = pchk[MAP[dr][dc]][MAP[r][c]] = true;
        chk[r][c] = chk[dr][dc] = true;
        if (check(next_r, next_c)) return true;
        pchk[MAP[r][c]][MAP[dr][dc]] = pchk[MAP[dr][dc]][MAP[r][c]] = false;
        chk[r][c] = chk[dr][dc] = false;
    }

    return false;
}

// 스도쿠 숫자들을 배열하는 함수
bool solve(int r, int c) {
    // 끝까지 도달했으면 스도미노쿠가 되는지 확인하고 결과 리턴
    if (r == 9) return check(0, 0);

    // 다음 행, 열을 계산
    int next_r = r, next_c = c + 1;
    if (next_c == 9) next_r++, next_c = 0;

    // 이미 숫자가 있으면 다음 칸 호출
    if (MAP[r][c]) return solve(next_r, next_c);

    // 놓을 수 있는 숫자에 대해서 넣고서 다음 칸 호출
    for (int i = 1; i <= 9; ++i) {
        if (isPossible(r, c, i)) {
            visit(r, c, true, i);
            if (solve(next_r, next_c)) return true;
            visit(r, c, false, i);
        }
    }

    // 이 칸에 대해서 가능한 것들을 모두 봤는데 모두 안됐으면 false 리턴
    return false;
}

int main(int argc, char *argv[]) {
    for (int T = 1; 1; ++T) {
        scanf("%d", &N);
        if (!N) break;  // N이 0이면 종료

        // 초기화
        memset(MAP, 0, sizeof(MAP));
        memset(visited, 0, sizeof(visited));
        memset(pchk, 0, sizeof(pchk));
        memset(chk, 0, sizeof(chk));

        // 도미노 입력
        for (int i = 0; i < N; ++i) {
            scanf("%d %s %d %s", &A, PA, &B, PB);
            pchk[A][B] = pchk[B][A] = true;
            MAP[PA[0] - 'A'][PA[1] - '1'] = A;
            MAP[PB[0] - 'A'][PB[1] - '1'] = B;
            visit(PA[0] - 'A', PA[1] - '1', true, A);
            visit(PB[0] - 'A', PB[1] - '1', true, B);
            chk[PA[0] - 'A'][PA[1] - '1'] = chk[PB[0] - 'A'][PB[1] - '1'] = true;
        }

        // 숫자 입력
        for (int i = 1; i <= 9; ++i) {
            scanf(" %s", PA);
            MAP[PA[0] - 'A'][PA[1] - '1'] = i;
            visit(PA[0] - 'A', PA[1] - '1', true, i);
            chk[PA[0] - 'A'][PA[1] - '1'] = true;
            pchk[i][i] = true;
        }

        // 문제 해결
        solve(0, 0);

        // 결과 출력
        printf("Puzzle %d\n", T);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf("%d", MAP[i][j]);
            }
            puts("");
        }
    }

    return 0;
}