#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int MAX = 20;
const int move_r[] = {-1, 0, 0, 1};
const int move_c[] = {0, -1, 1, 0};
int N, MAP[MAX][MAX];
bool visited[MAX][MAX];
queue <pii> Q;
vector <pii> targets;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", MAP[i] + j);
            if (MAP[i][j] == 9) {
                Q.push({i, j});
                visited[i][j] = true;
                MAP[i][j] = 0;
            }
        }
    }
  
    int _time = 0, _size = 2, _eat = 0;
    while (true) {
        targets.clear();
        int qsize = 0, lo_time = 0;
        while (!Q.empty()) {
            if (!qsize) {
                if (targets.empty()) qsize = Q.size(), lo_time++;
                else break;
            }

            int r = Q.front().X;
            int c = Q.front().Y;
            Q.pop(); qsize--;

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                if (!visited[dr][dc] && MAP[dr][dc] <= _size) {
                    visited[dr][dc] = true;
                    if (MAP[dr][dc] && MAP[dr][dc] < _size) targets.push_back({dr, dc});
                    else Q.push({dr, dc});
                }
            }
        }

        if (targets.empty()) break;
        while (!Q.empty()) Q.pop();
        memset(visited, 0, sizeof(visited));

        sort(targets.begin(), targets.end());
        Q.push(targets[0]);
        visited[targets[0].X][targets[0].Y] = true;
        MAP[targets[0].X][targets[0].Y] = 0;
        _time += lo_time; _eat++;
        if (_eat == _size) _size++, _eat = 0;
    }  

    printf("%d\n", _time);
    return 0;
}