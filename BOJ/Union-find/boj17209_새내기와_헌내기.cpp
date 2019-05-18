#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N, ans, pa[4000], cnt[4000];
char in[2001];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u == v) return;
    pa[v] = u;
}

void make_team(int u, int v) {
    _union(u, v);
    _union(u + N, v + N);
}

void make_enemy(int u, int v) {
    _union(u, v + N);
    _union(v, u + N);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    memset(pa, -1, sizeof(pa));
    
    for (int i = 0; i < N; ++i) {
        scanf(" %s", in);
        for (int j = 0; in[j]; ++j) 
            if (in[j] == '1') 
                make_enemy(i, j);
    }
    
    for (int i = 0; i < N; ++i) cnt[_find(i)]++;
    for (int i = 0; i < N; ++i) {
        if (cnt[i]) {
            int p_enemy = _find(i + N);
            ans += max(cnt[i], cnt[p_enemy]);
            cnt[i] = cnt[p_enemy] = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}