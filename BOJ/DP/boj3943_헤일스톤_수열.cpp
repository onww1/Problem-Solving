#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 1;
int t, n, dp[MAX];

int solve(int nn) {
    if (nn < MAX && dp[nn]) return dp[nn];
    int ret = max(nn, solve(nn % 2 ? 3 * nn + 1 : nn / 2));
    if (nn < MAX) dp[nn] = ret;
    return ret;
}

int main() {
    scanf("%d", &t); 
    dp[1] = 1;
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}