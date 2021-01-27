#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        int ret = 0;
        int len = 1, pow = 2, num = 1;
        while (num <= n) {
            while (num <= n && num < pow) {
                ret = (((1LL * ret) << len) + num) % MOD;
                num++;
            }
            len++; pow <<= 1;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> n = {1, 3, 12};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.concatenatedBinary(n[i]));

    /* Answer */
    vector<int> answer = {1, 27, 505379714};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
