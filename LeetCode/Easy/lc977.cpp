#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mn = abs(nums[0]), idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i]) < mn) {
                mn = abs(nums[i]);
                idx = i;
            }
        }

        vector<int> answer;
        int lo = idx - 1, hi = idx;
        while (lo >= 0 && hi < nums.size()) {
            if (abs(nums[lo]) < abs(nums[hi])) {
                answer.push_back(nums[lo] * nums[lo]);
                lo--;
            } else {
                answer.push_back(nums[hi] * nums[hi]);
                hi++;
            }
        }
        while (lo >= 0) {
            answer.push_back(nums[lo] * nums[lo]);
            lo--;
        }
        while (hi < nums.size()) {
            answer.push_back(nums[hi] * nums[hi]);
            hi++;
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {-4, -1, 0, 3, 10},
        {-7, -3, 2, 3, 11}
    };

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.sortedSquares(nums[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {0, 1, 9, 16, 100},
        {4, 9, 9, 49, 121}
    };
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
