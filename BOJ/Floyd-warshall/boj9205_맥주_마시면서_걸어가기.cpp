#include <algorithm>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int t, n;
bool d[102][102];
pii p[102];

int main(int argc, char *argv[]) {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n + 2; ++i) {
            scanf("%d %d", &p[i].X, &p[i].Y);
            for (int j = 0; j < i; ++j) {
                int dist = abs(p[i].X - p[j].X) + abs(p[i].Y - p[j].Y);
                if (dist <= 1000) d[i][j] = d[j][i] = 1;
            }
        }

        for (int k = 0; k < n + 2; ++k)
            for (int i = 0; i < n + 2; ++i)
                for (int j = 0; j < n + 2; ++j)
                    d[i][j] |= (d[i][k] && d[k][j]);

        puts(d[0][n + 1] ? "happy" : "sad");
    }

    return 0;
}