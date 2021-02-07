#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> answer(n, 0);
        
        int p = -1;
        for (int i = 0; i < n; i++)
            if (s[i] == c) {
                p = i;
                break;
            }
        for (int i = p - 1; i >= 0; i--)
            answer[i] = p - i;
        for (int i = p + 1; i < n; i++) {
            if (s[i] == c) p = i;
            else answer[i] = i - p;
        }

        for (int i = n - 1; i >= 0; i--)
            if (s[i] == c) {
                p = i;
                break;
            }
        for (int i = p + 1; i < n; i++)
            answer[i] = min(answer[i], i - p);
        for (int i = p - 1; i >= 0; i--) {
            if (s[i] == c) p = i;
            else answer[i] = min(answer[i], p - i);
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "loveleetcode",
        "aaab"
    };
    vector<char> c = {'e', 'b'};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.shortestToChar(s[i], c[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0},
        {3, 2, 1, 0}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
