#include <cstdio>

int T, K, L;
char S[1001];

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int tc = 1, ans; tc <= T; ++tc) {
        scanf(" %s %d", S, &K);
        for (L = 0; S[L]; ++L);
        ans = 0;
        for (int i = 0; i <= L - K; ++i) {
            if (S[i] == '-') {
                ans++;
                for (int j = i; j < i + K; ++j) 
                    S[j] = (S[j] == '-' ? '+' : '-');
            }
        }

        bool flag = 1;
        for (int i = L - K + 1; i < L; ++i) if (S[i] == '-') flag = 0;
        if (flag) printf("Case #%d: %d\n", tc, ans);
        else printf("Case #%d: IMPOSSIBLE\n", tc);
    }
    return 0;
}