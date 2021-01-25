#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int p = -1e9;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i - p <= k) return false;
                p = i;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1}
    };
    vector<int> k = {2, 2, 0, 1};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.kLengthApart(nums[i], k[i]));

    /* Answer */
    vector<bool> answer = {true, false, true, true};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
