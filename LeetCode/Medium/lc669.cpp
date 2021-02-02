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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

TreeNode* make_tree(vector<int>& nodes);
bool is_equal(TreeNode* nodeA, TreeNode* nodeB);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {1, 0, 2},
        {3, 0, 4, -1, 2, -1, -1, 1},
        {1},
        {1, -1, 2},
        {1, -1, 2}
    };
    vector<int> low = {1, 1, 1, 1, 2};
    vector<int> high = {2, 3, 2, 3, 4};
    
    vector<TreeNode*> root;
    for (int i = 0; i < nodes.size(); i++)
        root.push_back(make_tree(nodes[i]));

    /* Output */
    vector<TreeNode*> ret;
    for (int i = 0; i < root.size(); i++)
        ret.push_back(solution.trimBST(root[i], low[i], high[i]));

    /* Answer */
    vector<vector<int>> answer_nodes = {
        {1, -1, 2},
        {3, 2, -1, 1},
        {1},
        {1, -1, 2},
        {2}
    };

    vector<TreeNode*> answer;
    for (int i = 0; i < answer_nodes.size(); i++)
        answer.push_back(make_tree(answer_nodes[i]));

    /* Check */
    bool pass = true;
    for (int i = 0; i < ret.size(); i++)
        pass &= is_equal(ret[i], answer[i]);

    assert(pass);

    puts("PASS!");
    return 0;
}

TreeNode* make_tree(vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

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

bool is_equal(TreeNode* nodeA, TreeNode* nodeB) {
    if (nodeA == nullptr && nodeB == nullptr) return true;
    if (nodeA == nullptr || nodeB == nullptr) return false;
    bool ret = true;
    ret &= is_equal(nodeA->left, nodeB->left);
    ret &= is_equal(nodeA->right, nodeB->right);
    ret &= (nodeA->val == nodeB->val);
    return ret;
}