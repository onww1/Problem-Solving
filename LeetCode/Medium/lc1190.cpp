#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string reverseParentheses(string s) {
        string answer = "";
        int pn = 0;
        vector<int> idx;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                idx.push_back(i - pn);
                pn++;
            } else if (s[i] == ')') {
                int sidx = i - pn;
                reverse(answer.begin() + idx.back(), answer.begin() + sidx);
                idx.pop_back();
                pn++;
            } else {
                answer += s[i];
            }
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {"(abcd)", "(u(love)i)", "(ed(et(oc))el)", "a(bcdefghijkl(mno)p)q"};

    /* Output */
    vector<string> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.reverseParentheses(s[i]));

    /* Answer */
    vector<string> answer = {"dcba", "iloveu", "leetcode", "apmnolkjihgfedcbq"};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
