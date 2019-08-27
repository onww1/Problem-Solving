#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;
int n, m, a[305][305], v[305][305];
int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", a[i] + j);
    queue <piii> q;
    q.push({0, {0, 0}});
    v[0][0] = 1;
    while (!q.empty()) {
        int r = q.front().Y.X;
        int c = q.front().Y.Y;
        int t = q.front().X;
        q.pop();
        if (r == n - 1 && c == m - 1)
            return !printf("%d\n", t);
        for (int i = r + 1; i <= r + a[r][c] && i < n; ++i)
            if (!v[i][c]) {
                q.push({t + 1, {i, c}});
                v[i][c] = 1;
            }
        for (int i = c + 1; i <= c + a[r][c] && i < m; ++i)
            if (!v[r][i]) {
                q.push({t + 1, {r, i}});
                v[r][i] = 1;
            }
    }
    return 0;
}