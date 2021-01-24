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
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* node, vector<vector<int>> &level, int depth) {
        if (node == nullptr) return;
        if (level.size() <= depth) level.resize(depth + 1);
        level[depth].push_back(node->val);
        dfs(node->left, level, depth + 1);
        dfs(node->right, level, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        dfs(root, level, 0);
        return level;
    }
};

TreeNode* make_tree(vector<int> nodes);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *tree = make_tree(nodes);

    /* Output */
    vector<vector<int>> ret = solution.levelOrder(tree);

    /* Answer */
    vector<vector<int>> answer = {
        {3}, 
        {9, 20}, 
        {15, 7}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

TreeNode* make_tree(vector<int> nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    int idx = 1;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        
        if (idx >= nodes.size()) break;

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