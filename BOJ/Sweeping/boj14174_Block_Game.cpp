#include <algorithm>
#include <cstdio>
using namespace std;

int N, ans[26];
char words[2][11];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int cnt[2][26]{};
        scanf(" %s %s", words[0], words[1]);
        for (int j = 0; j < words[0][j]; ++j) cnt[0][words[0][j] - 'a']++;
        for (int j = 0; j < words[1][j]; ++j) cnt[1][words[1][j] - 'a']++;
        for (int j = 0; j < 26; ++j) ans[j] += max(cnt[0][j], cnt[1][j]);
    }
    for (int i = 0; i < 26; ++i) printf("%d\n", ans[i]);
    return 0;
}