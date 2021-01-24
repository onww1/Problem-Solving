#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) st.pop_back();
            st.push_back(i);
        }
        int idx = 0, lo = 0, hi = (int)nums.size() - 1;
        while (idx < st.size() && st[idx] == lo) { idx++; lo++; }

        st.clear();
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] < nums[i]) st.pop_back();
            st.push_back(i);
        }
        idx = 0;
        while (idx < st.size() && st[idx] == hi) { idx++; hi--; }

        return lo < hi ? hi - lo + 1 : 0;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {2, 6, 4, 8, 10, 9, 15},
        {1, 2, 3, 4},
        {1},
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.findUnsortedSubarray(nums[i]));

    /* Answer */
    vector<int> answer = {5, 0, 0};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
