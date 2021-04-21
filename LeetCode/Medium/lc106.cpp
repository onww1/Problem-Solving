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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        unordered_map<int,int> inorderIndex;
        for (int idx = 0; idx < n; idx++)
            inorderIndex[inorder[idx]] = idx;

        return dfs(0, n - 1, 0, n - 1, inorderIndex, postorder);
    }

private:
    TreeNode* dfs(int postLeft, int postRight, int inLeft, int inRight, unordered_map<int,int>& inorderIndex, vector<int>& postorder) {
        if (postLeft > postRight) return NULL;
        TreeNode* root = new TreeNode(postorder[postRight]);
        int rootInorderIndex = inorderIndex[postorder[postRight]];
        int leftSubtreeSize = rootInorderIndex - inLeft;
        root->left = dfs(postLeft, postLeft + leftSubtreeSize - 1, inLeft, rootInorderIndex - 1, inorderIndex, postorder);
        root->right = dfs(postLeft + leftSubtreeSize, postRight - 1, rootInorderIndex + 1, inRight, inorderIndex, postorder);
        return root;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> inorder = {
        {9, 3, 15, 20, 7},
        {-1}
    };
    vector<vector<int>> postorder = {
        {9, 15, 7, 20, 3},
        {-1}
    };

    /* Output */
    vector<TreeNode*> ret;
    for (int i = 0; i < inorder.size(); i++)
        ret.push_back(solution.buildTree(inorder[i], postorder[i]));

    /* Answer */
    vector<vector<int>> treeNodes = {
        {3, 9, 20, EMPTY, EMPTY, 15, 7},
        {-1}
    };
    vector<TreeNode*> answer;
    for (vector<int>& nodes: treeNodes)
        answer.push_back(makeTree(nodes));

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++)
        match &= matchTree(ret[i], answer[i]);
    assert(match);

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