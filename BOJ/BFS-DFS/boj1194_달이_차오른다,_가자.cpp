#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int n, m, v[50][50][64];
char in[50][51];
pii s;

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", in[i]);
        for (int j = 0; j < m; ++j) {
            if (in[i][j] == '0') s = {i, j}, in[i][j] = '.';
        }
    }

    queue <piii> q;
    q.push({0, {s.X, s.Y}});
    v[s.X][s.Y][0] = 1;

    while (!q.empty()) {
        int key = q.front().X;
        int r = q.front().Y.X;
        int c = q.front().Y.Y;
        q.pop();

        if (in[r][c] == '1') 
            return !printf("%d\n", v[r][c][key] - 1);
        
        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
            if ('a' <= in[dr][dc] && in[dr][dc] <= 'f') {
                int nkey = (key | (1 << (in[dr][dc] - 'a')));
                if (!v[dr][dc][nkey]) {
                    q.push({nkey, {dr, dc}});
                    v[dr][dc][nkey] = v[r][c][key] + 1;
                }
            }
            else if ('A' <= in[dr][dc] && in[dr][dc] <= 'F') {
                if (key & (1 << (in[dr][dc] - 'A'))) {
                    if (!v[dr][dc][key]) {
                        q.push({key, {dr, dc}});
                        v[dr][dc][key] = v[r][c][key] + 1;
                    }
                }
            }
            else if (in[dr][dc] != '#' && !v[dr][dc][key]) {
                q.push({key, {dr, dc}});
                v[dr][dc][key] = v[r][c][key] + 1;
            } 
        }   
    }
    puts("-1");
    return 0;
}