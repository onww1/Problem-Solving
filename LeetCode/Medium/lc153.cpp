#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] < nums[0]) hi = mid - 1;
            else lo = mid + 1;
        }
        return nums[lo % n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {3, 4, 5, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {11, 13, 15, 17}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.findMin(nums[i]));

    /* Answer */
    vector<int> answer = {1, 0, 11};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}