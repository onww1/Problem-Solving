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
    void solve(TreeNode* node, int depth, vector<int>& answer) {
        if (!node) return;
        if (depth > answer.size()) answer.push_back(node->val);
        solve(node->right, depth + 1, answer);
        solve(node->left, depth + 1, answer);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        solve(root, 1, answer);
        return answer;
    }
};

TreeNode* make_tree(vector<int>& nodes);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> nodes = {1, 2, 3, -1, 5, -1, 4};
    TreeNode* root = make_tree(nodes);

    /* Output */
    vector<int> ret = solution.rightSideView(root);

    /* Answer */
    vector<int> answer = {1, 3, 4};

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
    while (!q.empty() && idx < nodes.size())  {
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