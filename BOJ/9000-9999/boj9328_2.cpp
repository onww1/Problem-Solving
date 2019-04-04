/*
 *  BOJ 9328. 열쇠
 *
 *  시간 복잡도 : O(TRC)
 *  공간 복잡도 : O(RC)
 *
 *  테두리에 갈 수 있는 공간들을 만들어두고, (0, 0)에서 시작해서 탐색합니다.
 *  key가 없는 문의 경우 door라는 벡터에 넣어놨다가 나중에 key를 발견하면 그 지점들을 큐에 넣음으로써
 *  이어서 바로 탐색할 수 있도록 합니다.
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

const int MAX = 100;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int T, R, C, ans;
char MAP[MAX + 2][MAX + 2], in[MAX + 1];
bool visited[MAX + 2][MAX + 2], key[26];
vector <pii> doors[26];

void init() {
    memset(visited, 0, sizeof(visited));
    memset(key, 0, sizeof(key));
    for (int i = 0; i < 26; ++i) doors[i].clear();
    ans = 0;

    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; ++i) scanf(" %s", MAP[i] + 1);
    R += 2, C += 2;

    // 테두리를 모두 갈 수 있는 곳으로 설정
    for (int i = 0; i < R; ++i) MAP[i][0] = MAP[i][C - 1] = '.';
    for (int j = 0; j < C; ++j) MAP[0][j] = MAP[R - 1][j] = '.';

    // 이미 있는 key들을 체크
    scanf(" %s", in);
    if (in[0] != '0') 
        for (int i = 0; in[i]; ++i) 
            key[in[i] - 'a'] = true;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    while (T--) {
        init();

        queue <pii> q;
        q.push({0, 0}); visited[0][0] = true;

        // BFS를 통하여 탐색
        while (!q.empty()) {
            int r = q.front().X;
            int c = q.front().Y;
            q.pop();

            // 현재 위치가 문서면 문서의 수를 1 증가시킴.
            if (MAP[r][c] == '$') ans++;

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;

                if (!visited[dr][dc] && MAP[dr][dc] != '*') {
                    // 인접한 곳이 문인 경우
                    if ('A' <= MAP[dr][dc] && MAP[dr][dc] <= 'Z') { 
                        if (key[MAP[dr][dc] - 'A']) {   // key가 있으면 이동
                            q.push({dr, dc});
                            visited[dr][dc] = true;
                        } 
                        else doors[MAP[dr][dc] - 'A'].push_back({dr, dc});    // key가 없으면 후보로 달아놓음.
                    } 
                    // 인접한 곳이 key인 경우
                    else if ('a' <= MAP[dr][dc] && MAP[dr][dc] <= 'z') {  
                        q.push({dr, dc});
                        visited[dr][dc] = true;
                        
                        if (!key[MAP[dr][dc] - 'a']) {  // 없었던 key이면 후보에 있는 문들을 모두 큐에 넣음
                            key[MAP[dr][dc] - 'a'] = true;
                            for (pii door : doors[MAP[dr][dc] - 'a']) {
                                q.push(door);
                                visited[door.X][door.Y] = true;
                            }
                        }
                    } 
                    // 인접한 곳이 문서이거나 빈 공간인 경우
                    else {    
                        q.push({dr, dc});
                        visited[dr][dc] = true;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}