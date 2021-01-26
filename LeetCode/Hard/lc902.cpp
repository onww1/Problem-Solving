#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string n_str = to_string(n);
        int ndigit = digits.size();
        int nlen = n_str.length();
        
        vector<int> p(nlen);
        p[0] = 1;
        for (int i = 1; i < nlen; i++) 
            p[i] = p[i - 1] * ndigit;

        int answer = 0;
        if (ndigit > 1) answer = 1LL * ndigit * (p[nlen - 1] - 1) / (ndigit - 1);
        else answer = nlen - 1;

        for (int i = 0; i < nlen; i++) {
            bool has_boundary = false;
            for (int j = 0; j < digits.size(); j++) {
                if (digits[j][0] < n_str[i]) answer += p[nlen - 1 - i];
                else if (digits[j][0] == n_str[i]) has_boundary = true;
                else break;
            }
            if (!has_boundary) break;
            if (i == nlen - 1) answer++;
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<string>> digits = {
        {"1", "3", "5", "7"},
        {"1", "4", "9"},
        {"7"}
    };
    vector<int> n = {100, 1000000000, 8};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < digits.size(); i++)
        ret.push_back(solution.atMostNGivenDigitSet(digits[i], n[i]));

    /* Answer */
    vector<int> answer = {20, 29523, 1};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
