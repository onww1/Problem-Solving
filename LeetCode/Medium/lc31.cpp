#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) i--;
        if (i > 0) {
            for (int j = n - 1; j >= i; j--) {
                if (nums[i - 1] < nums[j]) {
                    swap(nums[i - 1], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 5},
        {1}
    };

    /* Output */
    for (int i = 0; i < nums.size(); i++)
        solution.nextPermutation(nums[i]);

    /* Answer */
    vector<vector<int>> answer = {
        {1, 3, 2},
        {1, 2, 3},
        {1, 5, 1},
        {1}
    };

    /* Check */
    assert(nums == answer);

    puts("PASS!");
    return 0;
}
