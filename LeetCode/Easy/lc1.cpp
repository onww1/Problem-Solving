#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i]) > 0) 
                return {hash[target - nums[i]], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {3, 3}
    };
    vector<int> target = {9, 6, 6};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.twoSum(nums[i], target[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {0, 1},
        {1, 2},
        {0, 1}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
