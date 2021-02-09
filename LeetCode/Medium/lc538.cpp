#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

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
    void solve(TreeNode* node, int& sum) {
        if (!node)
            return;
        solve(node->right, sum);
        sum += node->val;
        node->val = sum;
        solve(node->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};

TreeNode* make_tree(vector<int>& nodes);
bool is_match(TreeNode* anode, TreeNode* bnode);

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {4, 1, 6, 0, 2, 5, 7, INF, INF, INF, 3, INF, INF, INF, 8},
        {0, INF, 1},
        {1, 0, 2},
        {3, 2, 4, 1}
    };

    vector<TreeNode*> root;
    for (int i = 0; i < nodes.size(); i++)
        root.push_back(make_tree(nodes[i]));

    /* Output */
    vector<TreeNode*> ret;
    for (int i = 0; i < root.size(); i++)
        ret.push_back(solution.convertBST(root[i]));

    /* Answer */
    vector<vector<int>> anodes = {
        {30, 36, 21, 36, 35, 26, 15, INF, INF, INF, 33, INF, INF, INF, 8},
        {1, INF, 1},
        {3, 3, 2},
        {7, 9, 4, 10}
    };

    vector<TreeNode*> answer;
    for (int i = 0; i < anodes.size(); i++)
        answer.push_back(make_tree(anodes[i]));

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++)
        match &= is_match(ret[i], answer[i]);

    assert(match);

    puts("PASS!");
    return 0;
}

TreeNode* make_tree(vector<int>& nodes) {
    if (nodes.empty()) 
        return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);

    queue<TreeNode*> q;
    q.push(root);

    int idx = 1;
    while (!q.empty() && idx < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (nodes[idx] != INF) {
            node->left = new TreeNode(nodes[idx]);
            q.push(node->left);
        }
        idx++;

        if (nodes[idx] != INF) {
            node->right = new TreeNode(nodes[idx]);
            q.push(node->right);
        }
        idx++;
    }

    return root;
}

bool is_match(TreeNode* anode, TreeNode* bnode) {
    if (!anode && !bnode) 
        return true;
    if (!anode || !bnode) 
        return false;
    bool match = (anode->val == bnode->val);
    match &= is_match(anode->left, bnode->left);
    match &= is_match(anode->right, bnode->right);
    return match;
}