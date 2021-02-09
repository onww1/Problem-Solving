#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    const int OFFSET = 1e4 + 1;
    const int TSIZE = 2e4 + 2;
    vector<int> tree;

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        tree.resize(TSIZE);
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            answer[i] = query(nums[i] - 1 + OFFSET);
            update(nums[i] + OFFSET, 1);
        }
        return answer;
    }

    void update(int node, int val) {
        while (node < TSIZE) {
            tree[node] += val;
            node += node & -node;
        }
    }

    int query(int node) {
        int ret = 0;
        while (node) {
            ret += tree[node];
            node -= node & -node;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {5, 2, 6, 1},
        {-1},
        {-1, -1}
    };

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.countSmaller(nums[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {2, 1, 1, 0},
        {0},
        {0, 0}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
