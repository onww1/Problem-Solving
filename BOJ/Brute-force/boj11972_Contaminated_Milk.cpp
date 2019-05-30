#include <algorithm>
#include <cstdio>
using namespace std;

int N, M, D, S, DD[51][51], SS[51];

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d", &N, &M, &D, &S);
    for (int i = 0, p, m, t; i < D; ++i) {
        scanf("%d %d %d", &p, &m, &t);
        if (DD[p][m]) DD[p][m] = min(t, DD[p][m]);
        else DD[p][m] = t;
    }
    for (int i = 0, p, t; i < S; ++i) {
        scanf("%d %d", &p, &t);
        SS[p] = t;
    }

    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        int cnt = 0, flag = 1;
        for (int j = 1; j <= N; ++j) {
            if (SS[j] && (!DD[j][i] || SS[j] <= DD[j][i])) { flag = 0; break; }
            if (!DD[j][i]) continue;
            cnt++;
        }
        if (flag) ans = max(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}