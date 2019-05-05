#include <cstdio>
int N, M, L, S[1005], Q;

bool check(int len) {
    int s = 0, cnt = 0;
    for (int i = 0; i <= M; ++i) {
        if (S[i] - s >= len) {
            cnt++;
            s = S[i];
        }
    }
    return cnt >= Q + 1;
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &L);
    for (int i = 0; i < M; ++i) scanf("%d", S + i); S[M] = L;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &Q);
        int s = 0, e = 4000000, m = e, ans = e;
        while (s <= e) {
            m = (s + e) >> 1;
            if (check(m)) {
                ans = m;
                s = m + 1;
            } else e = m - 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}