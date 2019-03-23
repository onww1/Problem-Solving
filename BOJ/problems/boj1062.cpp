#include <algorithm>
#include <cstdio>
using namespace std;

int N, K, ans;
char words[50][16];
bool alpha[26];

void solve(int T, int P) {
    if (T == K) {
        int cnt = 0;
        for (int i = 0, j; i < N; ++i) {
            for (j = 4; words[i][j]; ++j) 
                if (!alpha[words[i][j] - 'a']) break;
            if (!words[i][j]) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    for (int i = P + 1; i < 26; ++i) 
        if (!alpha[i]) {
            alpha[i] = true;
            solve(T + 1, i);
            alpha[i] = false;
        }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) scanf(" %s", words[i]);
    alpha[0] = alpha[2] = alpha[8] = alpha[13] = alpha[19] = true;

    if (K < 5) return !printf("0\n");
    solve(5, 0);

    printf("%d\n", ans);
    return 0;
}