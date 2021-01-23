#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> ord(256, 0);
        for (int i = 0; i < 26; i++)
            ord[order[i]] = i;
        for (int i = 1, j, len; i < words.size(); i++) {
            len = min(words[i - 1].length(), words[i].length());
            bool sorted = true;
            for (j = 0; j < len; j++) {
                if (ord[words[i - 1][j]] < ord[words[i][j]]) break;
                if (ord[words[i - 1][j]] > ord[words[i][j]]) {
                    sorted = false;
                    break;
                }
            }
            if (j == len) sorted &= (words[i - 1].length() <= words[i].length());
            if (!sorted) return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<string>> words = {
        {"hello", "leetcode"},
        {"word","world","row"},
        {"apple","app"}
    };
    vector<string> order = {
        "hlabcdefgijkmnopqrstuvwxyz",
        "worldabcefghijkmnpqstuvxyz",
        "abcdefghijklmnopqrstuvwxyz"
    };

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < order.size(); i++)
        ret.push_back(solution.isAlienSorted(words[i], order[i]));

    /* Answer */
    vector<bool> answer = {true, false, false};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}