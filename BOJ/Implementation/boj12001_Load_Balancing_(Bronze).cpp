#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
int N, B, x[100], y[100], psum[101][101];
pii P[100];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &B);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", x + i, y + i);
        P[i] = {x[i], y[i]};
    }

    sort(x, x + N); 
    int nx = unique(x, x + N) - x;
    sort(y, y + N);
    int ny = unique(y, y + N) - y;

    for (int i = 0; i < N; ++i) {
        P[i].X = lower_bound(x, x + nx, P[i].X) - x + 1;
        P[i].Y = lower_bound(y, y + ny, P[i].Y) - y + 1;
        psum[P[i].X][P[i].Y]++;
    }

    for (int i = 1; i <= nx; ++i) 
        for (int j = 1; j <= ny; ++j) 
            psum[i][j] = psum[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];

    int ans = INF;
    for (int i = 1; i <= nx; ++i) {
        for (int j = 1; j <= ny; ++j) {
            int lu = psum[i][j];
            int ld = psum[nx][j] - lu;
            int ru = psum[i][ny] - lu;
            int rd = psum[nx][ny] - lu - ld - ru;
            ans = min(ans, max({lu, ld, ru, rd}));
        }
    }

    printf("%d\n", ans);
    return 0;
}