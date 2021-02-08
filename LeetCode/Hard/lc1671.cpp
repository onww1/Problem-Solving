#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 1));

        // left->right
        for (int i = 1; i < n; i++) 
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] < nums[i])
                    dp[0][i] = max(dp[0][i], dp[0][j] + 1);

        // right->left
        for (int i = n - 2; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    dp[1][i] = max(dp[1][i], dp[1][j] + 1);

        int answer = n;
        for (int i = 1; i + 1 < n; i++) 
            if (dp[0][i] > 1 && dp[1][i] > 1)
                answer = min(answer, n - dp[0][i] - dp[1][i] + 1);

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 3, 1},
        {2, 1, 1, 5, 6, 2, 3, 1},
        {4, 3, 2, 1, 1, 2, 3, 1},
        {1, 2, 3, 4, 4, 3, 2, 1}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.minimumMountainRemovals(nums[i]));

    /* Answer */
    vector<int> answer = {0, 3, 4, 1};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
