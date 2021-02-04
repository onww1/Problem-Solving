#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
using namespace std;

/* Solution Class */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> solve(TreeNode* node) {
        if (!node) return {0, 0};

        vector<int> left = solve(node->left);
        vector<int> right = solve(node->right);
        vector<int> ret(2, 0);

        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ret[1] = node->val + left[0] + right[0];
        return ret;
    }

    int rob(TreeNode* root) {
        vector<int> ret = solve(root);
        return max({ret[0], ret[1]});
    }
};

TreeNode* make_tree(vector<int>& nodes);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {3, 2, 3, -1, 3, -1, 1},
        {3, 4, 5, 1, 3, -1, 1}
    };

    vector<TreeNode*> root;
    for (int i = 0; i < nodes.size(); i++)
        root.push_back(make_tree(nodes[i]));

    /* Output */
    vector<int> ret;
    for (int i = 0; i < root.size(); i++)
        ret.push_back(solution.rob(root[i]));

    /* Answer */
    vector<int> answer = {7, 9};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

TreeNode* make_tree(vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q; q.push(root);
    int idx = 1;
    while (!q.empty() && idx < nodes.size()) {
        TreeNode* node = q.front(); q.pop();
        if (nodes[idx] != -1) {
            node->left = new TreeNode(nodes[idx]);
            q.push(node->left);
        }
        idx++;
        if (nodes[idx] != -1) {
            node->right = new TreeNode(nodes[idx]);
            q.push(node->right);
        }
        idx++;
    }
    return root;
}