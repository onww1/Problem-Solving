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
    void flatten(TreeNode* root) {
        function<pair<TreeNode*,TreeNode*>(TreeNode*)> helper = [&](TreeNode* node) {
            if (!node) return pair<TreeNode*,TreeNode*>(node, node);

            pair<TreeNode*,TreeNode*> ret = {node, node};
            TreeNode* leftChild = node->left;
            TreeNode* rightChild = node->right;
            node->left = node->right = nullptr;

            pair<TreeNode*,TreeNode*> leftResult = helper(leftChild);
            if (leftResult.first) {
                ret.second->right = leftResult.first;
                ret.second = leftResult.second;
            }

            pair<TreeNode*,TreeNode*> rightResult = helper(rightChild);
            if (rightResult.first) {
                ret.second->right = rightResult.first;
                ret.second = rightResult.second;
            }

            return ret;
        };

        pair<TreeNode*,TreeNode*> result = helper(root);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> treeNodes = {
        {1, 2, 5, 3, 4, EMPTY, 6},
        {},
        {0}
    };

    vector<TreeNode*> rootVec;
    for (vector<int>& nodes: treeNodes)
        rootVec.push_back(makeTree(nodes));

    /* Output */
    for (TreeNode* root: rootVec)
        solution.flatten(root);

    /* Answer */
    vector<vector<int>> ansNodes = {
        {1, EMPTY, 2, EMPTY, 3, EMPTY, 4, EMPTY, 5, EMPTY, 6},
        {},
        {0}
    };

    vector<TreeNode*> answer;
    for (vector<int>& nodes: ansNodes)
        answer.push_back(makeTree(nodes));

    /* Check */
    bool match = true;
    for (int i = 0; i < answer.size(); i++)
        match = match && matchTree(rootVec[i], answer[i]);
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