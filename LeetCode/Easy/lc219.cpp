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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for (int i = 0; i < nums.size() && i <= k; i++) 
            if (++cnt[nums[i]] > 1)
                return true;
        for (int i = k + 1; i < nums.size(); i++) {
            --cnt[nums[i - k - 1]];
            if (++cnt[nums[i]] > 1)
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 2, 3, 1},
        {1, 0, 1, 1},
        {1, 2, 3, 1, 2, 3}
    };
    vector<int> k = {3, 1, 2};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.containsNearbyDuplicate(nums[i], k[i]));

    /* Answer */
    vector<bool> answer = {true, true, false};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
