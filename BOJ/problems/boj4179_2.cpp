/*
 *  BOJ 4179. 불!
 *
 *  시간 복잡도 : O(RC)
 *  공간 복잡도 : O(RC)
 *
 *  BOJ 5427 문제와 똑같기 때문에 5427번을 풀고서 조금만 바꿔서 제출했습니다 ㅋㅋ
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<char, pii> pcii;

const int MAX = 1000;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int R, C;
char MAP[MAX][MAX + 1];
pii src; 

int main(int argc, char *argv[]) {
    queue <pcii> Q;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; MAP[i][j]; ++j) {
            // 불이면 큐에 넣는다.
            if (MAP[i][j] == 'F') Q.push({'F', {i, j}});
            // 지훈이의 위치는 따로 저장해준다.
            else if (MAP[i][j] == 'J') src = {i, j};
        }
    }

    // 지훈이의 위치는 마지막에 넣어준다.
    Q.push({'J', src});

    int _time = -1, _size = 0;
    bool valid = false;
    while (!valid && !Q.empty()) {

        // time을 카운트하기 위한 방법
        if (_size == 0) {
            _size = Q.size();
            _time++;
        }

        char what = Q.front().X;
        int r = Q.front().Y.X;
        int c = Q.front().Y.Y;
        Q.pop();

        if (what == 'J' && (r == 0 || r == R - 1 || c == 0 || c == C - 1)) {
            valid = true;
            _time++;
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;

            if (MAP[dr][dc] == '.' || MAP[dr][dc] == 'J') {
                if (what == 'F') {  // 불이면 두 가지 모두에 대해서 이동
                    MAP[dr][dc] = 'F';
                    Q.push({what, {dr, dc}});    
                } else if (what == 'J' && MAP[dr][dc] == '.') {   // 상근이면 갈 수 있는 곳일 때만 이동
                    MAP[dr][dc] = 'J';
                    Q.push({what, {dr, dc}});
                }
            }
        }

        _size--;
    }

    if (valid) printf("%d\n", _time);
    else puts("IMPOSSIBLE");

    return 0;
}