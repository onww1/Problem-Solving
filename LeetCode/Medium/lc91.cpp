#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int numDecodings(string s) {
        int dp[3]{};
        dp[0] = 1;
        int c = 1, p = 0, pp = 2;
        for (int i = 0; i < s.length(); i++) {
            dp[c] = 0;
            if (s[i] != '0') dp[c] += dp[p];
            if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && '0' <= s[i] && s[i] <= '6')))
                dp[c] += dp[pp];
            c = (c + 1) % 3;
            p = (p + 1) % 3;
            pp = (pp + 1) % 3;
        }
        return dp[p];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {"12", "226", "0", "06"};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.numDecodings(s[i]));

    /* Answer */
    vector<int> answer = {2, 3, 0, 0};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
