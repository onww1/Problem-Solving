#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int left = i, right = i + len - 1;
                if (s[left] == s[right]) dp[left][right] = dp[left + 1][right - 1] + 2;
                else dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "bbbab",
        "cbbd"
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.longestPalindromeSubseq(s[i]));

    /* Answer */
    vector<int> answer = {4, 2};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
