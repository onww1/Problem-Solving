/*
 *  BOJ 5427. 불
 *
 *  시간 복잡도 : O(TRC)
 *  공간 복잡도 : O(RC)
 *
 *  처음에 큐에 불의 위치부터 넣어주고, 마지막에 상근이의 위치를 넣어줍니다. 
 *  저장을 할 때 이게 불인지 상근이인지도 함께 저장해줍니다.
 *  그렇게 BFS를 하면 자연스럽게 불이 먼저 이동하고, 마지막에 상근이가 불이 이동했던 곳은 못가므로 
 *  문제에서 요구하는 상황이 가능해집니다. 그렇게 BFS를 돌리다가 상근이가 경계에 이르면 한 칸만 더 이동하면
 *  탈출이므로 time을 하나 올려서 끝내고, 도달하지 못하면 valid가 false이므로 IMPOSSIBLE을 출력하게 됩니다.
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
int T, R, C;
char MAP[MAX][MAX + 1];
pii src; 

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &C, &R);

        queue <pcii> Q;
        for (int i = 0; i < R; ++i) {
            scanf(" %s", MAP[i]);
            for (int j = 0; MAP[i][j]; ++j) {
                // 불이면 큐에 넣는다.
                if (MAP[i][j] == '*') Q.push({'*', {i, j}});
                // 상근이의 위치는 따로 저장해준다.
                else if (MAP[i][j] == '@') src = {i, j};
            }
        }

        // 상근이의 위치는 마지막에 넣어준다.
        Q.push({'@', src});

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

            // 상근이가 경계에 있으면 끝낸다.
            if (what == '@' && (r == 0 || r == R - 1 || c == 0 || c == C - 1)) {
                valid = true;
                _time++;
                break;
            }

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;

                if (MAP[dr][dc] == '.' || MAP[dr][dc] == '@') {
                    if (what == '*') {  // 불이면 두 가지 모두에 대해서 이동
                        MAP[dr][dc] = '*';
                        Q.push({what, {dr, dc}});    
                    } else if (what == '@' && MAP[dr][dc] == '.') {   // 상근이면 갈 수 있는 곳일 때만 이동
                        MAP[dr][dc] = '@';
                        Q.push({what, {dr, dc}});
                    }
                }
            }

            _size--;
        }

        if (valid) printf("%d\n", _time);
        else puts("IMPOSSIBLE");
    }

    return 0;
}