#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int n, m, ans = INF, o1[2] = {-1, -1}, o2[2];
char in[20][21];

void solve(int t) {
    if (t >= 10) return;

    for (int k = 0; k < 4; ++k) {
        int dr1 = o1[0] + move_r[k];
        int dc1 = o1[1] + move_c[k];
        int dr2 = o2[0] + move_r[k];
        int dc2 = o2[1] + move_c[k];
        bool out1 = (dr1 < 0 || dr1 >= n || dc1 < 0 || dc1 >= m);
        bool out2 = (dr2 < 0 || dr2 >= n || dc2 < 0 || dc2 >= m);
        if (out1 && out2) continue;
        if (out1 ^ out2) {
            ans = min(ans, t + 1);
            return;
        }
        if (in[dr1][dc1] == '.') o1[0] = dr1, o1[1] = dc1;
        if (in[dr2][dc2] == '.') o2[0] = dr2, o2[1] = dc2;
        solve(t + 1);
        if (in[dr1][dc1] == '.') o1[0] -= move_r[k], o1[1] -= move_c[k];
        if (in[dr2][dc2] == '.') o2[0] -= move_r[k], o2[1] -= move_c[k];
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", in[i]);
        for (int j = 0; j < m; ++j)
            if (in[i][j] == 'o') {
                if (o1[0] == -1) o1[0] = i, o1[1] = j;
                else o2[0] = i, o2[1] = j;
                in[i][j] = '.';
            }
    }

    solve(0);
    printf("%d\n", ans == INF ? -1 : ans);

    return 0;
}