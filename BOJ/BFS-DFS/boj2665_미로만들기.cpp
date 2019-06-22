#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int n, v[50][50][100];
char a[50][51];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf(" %s", a[i]);

    queue <piii> q;
    v[0][0][0] = 1;
    q.push({0, {0, 0}});

    while (!q.empty()) {
        int p = q.front().X;
        int r = q.front().Y.X;
        int c = q.front().Y.Y;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
            if (a[dr][dc] == '0' && p < 99 && !v[dr][dc][p + 1]) {
                q.push({p + 1, {dr, dc}});
                v[dr][dc][p + 1] = 1;
            }
            if (a[dr][dc] == '1' && !v[dr][dc][p]) {
                q.push({p, {dr, dc}});
                v[dr][dc][p] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        if (v[n - 1][n - 1][i]) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}