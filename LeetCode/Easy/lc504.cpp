#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string convertToBase7(int num) {
        string answer = "";
        if (num < 0) {
            answer += '-';
            num *= -1;
        }
        vector<int> v;
        while (num) {
            v.push_back(num % 7);
            num /= 7;
        }
        while (!v.empty()) {
            answer += to_string(v.back());
            v.pop_back();
        }
        if (answer.length() == 0) answer += '0';
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> num = {100, -7};

    /* Output */
    vector<string> ret;
    for (int i = 0; i < num.size(); i++)
        ret.push_back(solution.convertToBase7(num[i]));

    /* Answer */
    vector<string> answer = {"202", "-10"};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
