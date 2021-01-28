#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer = "";
        while (n) {
            int val = k - 26 * (n - 1);
            if (val <= 1) {
                answer += 'a';
                k--;
            } else {
                answer += (char)('a' + val - 1);
                k -= val;
            }
            n--;
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> n = {3, 5};
    vector<int> k = {27, 73};

    /* Output */
    vector<string> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.getSmallestString(n[i], k[i]));

    /* Answer */
    vector<string> answer = {"aay", "aaszz"};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

