#include <algorithm>
#include <cstdio>
using namespace std;

char str1[41], str2[41], ans[41];
int L1, L2, DP[41][41];

int main(int argc, char *argv[]) {
    scanf(" %s %s", str1, str2);
    for (; str1[L1]; ++L1);
    for (; str2[L2]; ++L2);

    for (int i = 1; i <= L1; ++i) {
        for (int j = 1; j <= L2; ++j) {
            if (str1[i - 1] == str2[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    int cur = DP[L1][L2], i = L1, j = L2;
    while (cur && i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1] && DP[i][j] == cur) {
            ans[--cur] = str1[i - 1];
            --i, --j;
        }
        else if (DP[i][j] == DP[i - 1][j]) --i;
        else --j;
    }

    printf("%s\n", ans);
    return 0;
}