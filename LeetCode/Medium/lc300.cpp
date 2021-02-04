#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(0x3f3f3f3f);
        for (int i = 0; i < nums.size(); i++) {
            if (lis.back() < nums[i]) lis.push_back(nums[i]);
            else *lower_bound(lis.begin(), lis.end(), nums[i]) = nums[i];
        }
        return (int)lis.size();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {10, 9, 2, 5, 3, 7, 101, 18},
        {0, 1, 0, 3, 2, 3},
        {7, 7, 7, 7, 7, 7, 7}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.lengthOfLIS(nums[i]));

    /* Answer */
    vector<int> answer = {4, 4, 1};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
