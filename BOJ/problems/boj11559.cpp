/*
 *  BOJ 11559. Puyo Puyo
 *
 *  시간 복잡도 : O(TRC)    ( T : 연쇄의 수 )
 *  공간 복잡도 : O(RC)
 *
 *  단순하게 처음부터 끝까지 돌면서 덩어리를 BFS하는데 그 덩어리의 크기가 4 이상이면
 *  바로 빈칸으로 바꿔주고 true를 리턴함으로써 부숴진 적이 있다는 것을 알려줍니다. 
 *  그렇게 모두 돌았을 때, 부숴진 적이 있으면 떠있는 것들을 내려주고, 없다면 끝내서 연쇄의 수를
 *  출력하도록 했습니다.
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

const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int R = 12, C = 6;
char MAP[12][7];
bool visited[12][6];

bool BFS(int r, int c, char m) {
    queue <pii> q;  
    vector <pii> v; // 4개 이상일 때 지워야 하는 점들 저장 
    v.push_back({r, c});
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        int rr = q.front().X;
        int cc = q.front().Y;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int dr = rr + move_r[k];
            int dc = cc + move_c[k];
            if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
            if (!visited[dr][dc] && MAP[dr][dc] == m) {
                q.push({dr, dc});
                v.push_back({dr, dc});
                visited[dr][dc] = true;
            }
        }
    }

    // vector에 4개 이상이 들어있으면 부숴지는 케이스이므로 모두 빈칸으로 바꿔준다.
    if (v.size() >= 4) {
        for (pii p : v) MAP[p.X][p.Y] = '.';
        return true;    // 터졌음을 의미
    }

    return false;   // 안터졌음을 의미.
}

void update() {
    for (int c = 0; c < C; ++c) {
        // 맨 아래쪽에서부터 시작
        for (int r = R - 1, offset = 0; r >= 0; r--) {
            if (MAP[r][c] == '.') offset++; // 빈 칸을 만나면 offset을 증가시킨다.
            else if (offset) {  // offset이 0이 아니면 밑에 빈칸이 있는 것이므로 그만큼 내려준다.
                MAP[r + offset][c] = MAP[r][c];
                MAP[r][c] = '.';
            }
        }
    }
}

int main(int argc, char *argv[]) {
    open();
    
    // input
    for (int i = 0; i < 12; ++i) scanf(" %s", MAP[i]);

    int T = 0;  // 연쇄의 수
    for (; ; T++) {
        bool isChanged = false;  // 변화가 있는지 체크
        memset(visited, 0, sizeof(visited)); 
        
        // 전체를 돌면서 터지는 것들을 터뜨리기
        for (int i = 0; i < R; ++i) 
            for (int j = 0; j < C; ++j) 
                if (!visited[i][j] && MAP[i][j] != '.') 
                    isChanged |= BFS(i, j, MAP[i][j]);

        // 변화가 없으면 종료
        if (!isChanged) break;

        // 변화가 있었으면 떠있는 것들을 모두 바닥으로 내려줌.
        update();
    }

    // 연쇄의 수를 출력
    printf("%d\n", T);
    return 0;
}
