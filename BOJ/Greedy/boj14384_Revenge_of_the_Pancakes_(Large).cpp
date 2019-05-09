#include <cstdio>

int T;
char S[101];

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf(" %s", S);
        bool flag = (S[0] == '-');
        int ans = (S[0] == '-');
        for (int i = 1; S[i]; ++i) {
            if (S[i] == '+') {
                flag = false;
            } else if (!flag) {
                flag = true;
                ans += 2;
            }
        }
        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}