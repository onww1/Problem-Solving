#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> front;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (cnt) {
                    cnt--;
                    front.push_back(s[i]);
                }
            }
            else {
                if (s[i] == '(') cnt++;
                front.push_back(s[i]);
            }
        }
        
        vector<char> back;
        cnt = 0;
        while (!front.empty()) {
            char c = front.back();
            front.pop_back();
            if (c == '(') {
                if (cnt) {
                    cnt--;
                    back.push_back(c);
                }
            }
            else {
                if (c == ')') cnt++;
                back.push_back(c);
            }
        }
        
        reverse(back.begin(), back.end());
        return string(back.begin(), back.end());
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "lee(t(c)o)de)",
        "a)b(c)d",
        "))((",
        "(a(b(c)d)"
    };

    /* Output */
    vector<string> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.minRemoveToMakeValid(s[i]));

    /* Answer */
    vector<string> answer = {
        "lee(t(c)o)de",
        "ab(c)d",
        "",
        "a(b(c)d)"
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
