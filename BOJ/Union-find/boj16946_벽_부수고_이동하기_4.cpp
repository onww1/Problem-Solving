#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 1e6 + 1;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int n, m, pa[MAX], cnt[MAX];
char mp[1000][1001];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[v] = u;
        cnt[u] += cnt[v];
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf(" %s", mp[i]);

    memset(pa, -1, sizeof(pa));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '0') {
                cnt[i * m + j] = 1; 
                for (int k = 0; k < 2; ++k) {
                    int dr = i + move_r[k];
                    int dc = j + move_c[k];
                    if (dr < 0 || dc < 0) continue;
                    if (mp[dr][dc] == '0') _union(dr * m + dc, i * m + j);
                }
            }
            else cnt[i * m + j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '1') {
                set <int> adj;
                for (int k = 0; k < 4; ++k) {
                    int dr = i + move_r[k];
                    int dc = j + move_c[k];
                    if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                    if (mp[dr][dc] == '0') {
                        int pp = _find(dr * m + dc);
                        adj.insert(pp);
                    }
                }
                int sum = 1;
                for (int idx : adj) sum += cnt[idx];
                mp[i][j] = (sum % 10) + '0';
            }
        }
        printf("%s\n", mp[i]);
    }
    return 0;
}