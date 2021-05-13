#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* makeList(vector<int>& nodes);
TreeNode* makeTree(vector<int>& nodes);
bool matchList(ListNode* anode, ListNode* bnode);
bool matchTree(TreeNode* anode, TreeNode* bnode);

const int EMPTY = 0x7f7f7f7f;

/* Solution Class */
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> combinations = getCombinations(n);
        vector<vector<int>> counts = getCounts(n, nums);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%3d", counts[i][j]);
            }
            puts("");
        }
        puts("");

        int answer = 1;
        function<void(int,int,int)> solve = [&](int idx, int lo, int hi) {
            int root = nums[idx - 1];
            int numTotal = counts[idx][hi] - counts[idx][lo - 1];
            int numSmaller = counts[idx][root - 1] - counts[idx][lo - 1];
            answer = 1LL * answer * combinations[numTotal - 1][numSmaller] % MOD;
            bool smaller = false, larger = false;
            while (idx <= n) {
                if (smaller && larger) break;
                if (lo <= nums[idx - 1] && nums[idx - 1] <= hi) {
                    if (nums[idx - 1] > root && !larger) {
                        larger = true;
                        solve(idx, root + 1, hi);
                    }
                    if (nums[idx - 1] < root && !smaller) {
                        smaller = true;
                        solve(idx, lo, root - 1);
                    }
                }
                idx++;
            }
        };

        solve(1, 1, n);
        return answer - 1;
    }

private:
    const int MOD = 1e9 + 7;

    vector<vector<int>> getCombinations(int n) {
        vector<vector<int>> combinations(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) combinations[i][i] = combinations[i][0] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
                combinations[i][j] = (combinations[i - 1][j] + combinations[i - 1][j - 1]) % MOD;
        return combinations;
    }

    vector<vector<int>> getCounts(int n, vector<int>& nums) {
        vector<vector<int>> counts(n + 1, vector<int>(n + 1, 0));
        for (int i = n; i > 0; i--) {
            counts[i][nums[i - 1]] = 1;
            for (int j = n; j > 0; j--) {
                counts[i][j] = counts[i][j - 1];
                if (i < n) counts[i][j] += counts[i + 1][j];
            }
        }
        return counts;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> numsVec = {
        {2, 1, 3},
        {3, 4, 5, 1, 2},
        {1, 2, 3},
        {3, 1, 2, 5, 4, 6},
        {9, 4, 2, 1, 3, 6, 5, 7, 8, 14, 11, 10, 12, 13, 16, 15, 17, 18}
    };

    /* Output */
    vector<int> ret;
    for (vector<int>& nums: numsVec)
        ret.push_back(solution.numOfWays(nums));

    /* Answer */
    vector<int> answer = {1, 5, 0, 19, 216212978};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

ListNode* makeList(vector<int>& nodes) {
    if (nodes.empty())
        return nullptr;

    ListNode* head = new ListNode(nodes[0]);
    ListNode* ptr = head;
    for (int i = 1; i < nodes.size(); i++) {
        ptr->next = new ListNode(nodes[i]);
        ptr = ptr->next;
    }

    return head;
}

TreeNode* makeTree(vector<int>& nodes) {
    if (nodes.empty())
        return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);

    int idx = 1;
    while (!que.empty() && idx < nodes.size()) {
        TreeNode* node = que.front();
        que.pop();

        if (nodes[idx] != EMPTY) {
            node->left = new TreeNode(nodes[idx]);
            que.push(node->left);
        }
        idx++;

        if (nodes[idx] != EMPTY) {
            node->right = new TreeNode(nodes[idx]);
            que.push(node->right);
        }
        idx++;
    }

    return root;
}

bool matchList(ListNode* anode, ListNode* bnode) {
    while (anode && bnode) {
        if (anode->val != bnode->val)
            return false;
        anode = anode->next;
        bnode = bnode->next;
    }
    return !anode && !bnode;
}

bool matchTree(TreeNode* anode, TreeNode* bnode) {
    if (!anode && !bnode) 
        return true;
    if (!anode || !bnode)
        return false;
    if (anode->val != bnode->val)
        return false;
    return matchTree(anode->left, bnode->left) && matchTree(anode->right, bnode->right);
}