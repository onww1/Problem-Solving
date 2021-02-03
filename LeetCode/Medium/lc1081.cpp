#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string solve(int idx, int p, vector<vector<int>>& next, vector<int>& rest) {
        if (!p) return "";
        for (int i = 0; i < 26; i++) {
            if (p & (1 << i)) {
                int nextp = p ^ (1 << i);
                int index = next[idx][i];
                if ((rest[index + 1] & nextp) == nextp)
                    return (char)('a' + i) + solve(index + 1, nextp, next, rest);
            }
        }
        return "";
    }

    string smallestSubsequence(string s) {
        int n = s.length();
        vector<vector<int>> next(n + 1, vector<int>(26, n));
        vector<int> rest(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            rest[i] = rest[i + 1] | (1 << (s[i] - 'a'));
            for (int j = 0; j < 26; j++) {
                if (s[i] == 'a' + j) next[i][j] = i;
                else next[i][j] = next[i + 1][j];
            }
        }
        return solve(0, rest[0], next, rest);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "bcabc",
        "cbacdcbc"
    };

    /* Output */
    vector<string> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.smallestSubsequence(s[i]));

    /* Answer */
    vector<string> answer = {
        "abc",
        "acdb"
    };
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
