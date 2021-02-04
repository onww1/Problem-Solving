#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 0;
        int pcnt = -1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) cnt++;
            else {
                if (pcnt != -1) answer = max(answer, pcnt + cnt);
                if (nums[i - 1] + 1 == nums[i]) pcnt = cnt;
                else pcnt = -1;
                cnt = 1;
            }
        }
        if (pcnt != -1) answer = max(answer, pcnt + cnt);
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 3, 2, 2, 5, 2, 3, 7},
        {1, 2, 3, 4},
        {1, 1, 1, 1}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.findLHS(nums[i]));

    /* Answer */
    vector<int> answer = {5, 2, 0};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
