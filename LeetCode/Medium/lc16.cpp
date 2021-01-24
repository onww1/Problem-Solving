#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <set>
using namespace std;

/* Solution Class */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        set<int> twoSum;
        twoSum.insert(nums[0] + nums[1]);

        int min_diff = 0x3f3f3f3f, answer = 0;
        for (int i = 2; i < nums.size(); i++) {
            int p = target - nums[i];
            auto lower = twoSum.lower_bound(p);
            if (twoSum.end() != lower) {
                int threeSum = *lower + nums[i];
                if (min_diff > abs(threeSum - target)) {
                    min_diff = abs(threeSum - target);
                    answer = threeSum;
                }
            }
            if (twoSum.begin() != lower) {
                lower--;
                int threeSum = *lower + nums[i];
                if (min_diff > abs(threeSum - target)) {
                    min_diff = abs(threeSum - target);
                    answer = threeSum;
                }   
            }

            for (int j = 0; j < i; j++)
                twoSum.insert(nums[j] + nums[i]);
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {-1, 2, 1, -4},
        {0, 0, 0}
    };
    vector<int> target = {1, 1};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.threeSumClosest(nums[i], target[i]));

    /* Answer */
    vector<int> answer = {2, 0};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
