#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(256, 0);
        int alphabet_num = 0;
        for (int i = 0; i < t.length(); i++) {
            if (!cnt[t[i]]--) {
                alphabet_num++;
            }
        }

        string answer = "";
        int lo = 0, hi = 0;
        while (hi < s.length()) {
            while (hi < s.length() && alphabet_num > 0) {
                if (!++cnt[s[hi]]) alphabet_num--;
                hi++;
            }
            while (lo < hi && alphabet_num == 0) {
                if (!alphabet_num && (answer.empty() || answer.length() > hi - lo))
                    answer = s.substr(lo, hi - lo);
                if (!cnt[s[lo]]--) alphabet_num++;
                lo++;
            }
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {"ADOBECODEBANC", "a"};
    vector<string> t = {"ABC", "a"};

    /* Output */
    vector<string> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.minWindow(s[i], t[i]));

    /* Answer */
    vector<string> answer = {"BANC", "a"};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
