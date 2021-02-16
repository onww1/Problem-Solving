#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    char toggle(char c) {
        if ('a' <= c && c <= 'z') return c - 'a' + 'A';
        else if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
        return c;
    }

    void dfs(int idx, string& S, vector<string>& answer) {
        if (idx == S.length()) {
            answer.emplace_back(S);
            return;
        }
        if ('0' <= S[idx] && S[idx] <= '9') {
            dfs(idx + 1, S, answer);
        } else {
            S[idx] = toggle(S[idx]);
            dfs(idx + 1, S, answer);
            S[idx] = toggle(S[idx]);
            dfs(idx + 1, S, answer);
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> answer;
        dfs(0, S, answer);
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> S = {
        "a1b2",
        "3z4",
        "12345",
        "0"
    };

    /* Output */
    vector<vector<string>> ret;
    for (int i = 0; i < S.size(); i++) {
        ret.push_back(solution.letterCasePermutation(S[i]));
        sort(ret.back().begin(), ret.back().end(), greater<string>());
    }

    /* Answer */
    vector<vector<string>> answer = {
        {"a1b2", "a1B2", "A1b2", "A1B2"},
        {"3z4", "3Z4"},
        {"12345"},
        {"0"}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
