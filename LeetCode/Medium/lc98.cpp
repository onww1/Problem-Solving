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
struct Info {
    int minValue;
    int maxValue;
    bool valid;
    Info(): Info(0x7fffffff, 0x80000000, true) {}
    Info(int _min, int _max, bool _valid): minValue(_min), maxValue(_max), valid(_valid) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root).valid;
    }

private:
    Info check(TreeNode* node) {
        Info ret(node->val, node->val, true);
        if (node->left) {
            Info leftResult = check(node->left);
            if (leftResult.maxValue >= node->val)
                ret.valid = false;
            ret.minValue = min(ret.minValue, leftResult.minValue);
            ret.maxValue = max(ret.maxValue, leftResult.maxValue);
            ret.valid &= leftResult.valid;
        }
        if (node->right) {
            Info rightResult = check(node->right);
            if (rightResult.minValue <= node->val)
                ret.valid = false;
            ret.minValue = min(ret.minValue, rightResult.minValue);
            ret.maxValue = max(ret.maxValue, rightResult.maxValue);
            ret.valid &= rightResult.valid;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {2, 1, 3},
        {5, 1, 4, EMPTY, EMPTY, 3, 6}
    };

    vector<TreeNode*> root;
    for (vector<int>& treeNodes: nodes)
        root.push_back(makeTree(treeNodes));

    /* Output */
    vector<bool> ret;
    for (TreeNode* rootNode: root)
        ret.push_back(solution.isValidBST(rootNode));

    /* Answer */
    vector<bool> answer = {true, false};

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