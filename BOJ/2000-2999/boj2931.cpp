/*
 *  BOJ 2931. 가스관
 *
 *  시간 복잡도 : O(RC)
 *  공간 복잡도 : O(RC)
 *
 *  그저 시뮬레이션 문제였던 것 같습니다. 
 *  Z에서 시작해서 이동할 수 있는 부분으로 계속 이동하다가 .을 만나면 일단 그 위치를 저장합니다.
 *  그리고 그 위치에서 이동할 수 있는 부분들에 대해서 다 체크하고 그것에 해당하는 블록을 답으로 정하는 것입니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
enum { EAST, SOUTH, WEST, NORTH };

const int MAX = 25;
const int move_r[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int move_c[] = {1, 0, -1, 0, -1, 1, -1, 1};
int R, C, dict2[128];
char MAP[MAX + 1][MAX + 1], dict[16];
pii M, Z, A;

// 블록에 대한 정보를 저장
void init() {
    dict[0b1010] = '|';     dict2['|'] = 0b1010;
    dict[0b0101] = '-';     dict2['-'] = 0b0101;
    dict[0b1111] = '+';     dict2['+'] = 0b1111;
    dict[0b0011] = '1';     dict2['1'] = 0b0011;
    dict[0b1001] = '2';     dict2['2'] = 0b1001;
    dict[0b1100] = '3';     dict2['3'] = 0b1100;
    dict[0b0110] = '4';     dict2['4'] = 0b0110;
    dict[0b0000] = '.';     dict2['.'] = 0b0000;
}

int main(int argc, char *argv[]) {
    init();    

    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j) {
            if (MAP[i][j] == 'Z') Z = {i, j};
            if (MAP[i][j] == 'M') M = {i, j};
        }
    }

    queue <piii> Q;
    for (int k = 0; k < 4; ++k) {
        int dr = Z.X + move_r[k];
        int dc = Z.Y + move_c[k];
        if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;

        // 시작점에서 인접한 애들 중에 갈 수 있는 애들을 Queue에 넣음. 하나밖에 없을것임.
        if (dict2[MAP[dr][dc]] & (1 << ((k + 2) % 4))) Q.push({(k + 2) % 4, {dr, dc}});
    }

    while (!Q.empty()) {
        int prev = Q.front().X;
        int r = Q.front().Y.X;
        int c = Q.front().Y.Y;
        Q.pop();

        // 이동하던 중에 .을 만나면 없어진 블록임.
        if (MAP[r][c] == '.') {
            A = {r, c};
            break;
        }

        int cur = dict2[MAP[r][c]];
        // + 모양 블록만 따로 처리함.
        if (cur == 0b1111) Q.push({prev, {r + move_r[(prev + 2) % 4], c + move_c[(prev + 2) % 4]}});
        else {
            // 그 블록으로 들어오게 만든 방향을 제외한 다른 방향을 찾아서 Queue에 넣음.
            for (int k = 0; k < 4; ++k) {
                if (k != prev && cur & (1 << k)) {
                    Q.push({(k + 2) % 4, {r + move_r[k], c + move_c[k]}});
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < 4; ++k) {
        int dr = A.X + move_r[k];
        int dc = A.Y + move_c[k];
        if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
        // 인접한 블록중에 갈수 있는 방향에 대해서 비트마스킹함.
        if (dict2[MAP[dr][dc]] & (1 << ((k + 2) % 4))) ans |= (1 << k);
    }

    printf("%d %d %c\n", A.X + 1, A.Y + 1, dict[ans]);
    return 0;
}