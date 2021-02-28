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
TreeNode* findNode(TreeNode* node, int value);

const int EMPTY = 0x7f7f7f7f;

/* Solution Class */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) 
            return root;
        if (left)
            return left;
        if (right)
            return right;
        return NULL;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nodes = {
        {3, 5, 1, 6, 2, 0, 8, EMPTY, EMPTY, 7, 4},
        {3, 5, 1, 6, 2, 0, 8, EMPTY, EMPTY, 7, 4},
        {1, 2}
    };
    vector<int> pnode = {5, 5, 1};
    vector<int> qnode = {1, 4, 2};

    vector<TreeNode*> root, p, q;
    for (int i = 0; i < nodes.size(); i++) {
        root.push_back(makeTree(nodes[i]));
        p.push_back(findNode(root[i], pnode[i]));
        q.push_back(findNode(root[i], qnode[i]));
    }

    /* Output */
    vector<TreeNode*> ret;
    for (int i = 0; i < root.size(); i++)
        ret.push_back(solution.lowestCommonAncestor(root[i], p[i], q[i]));

    /* Answer */
    vector<int> answer = {3, 5, 1};

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++)
        if (ret[i]->val != answer[i])
            match = false;
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

        if (idx < nodes.size() && nodes[idx] != EMPTY) {
            node->left = new TreeNode(nodes[idx]);
            que.push(node->left);
        }
        idx++;

        if (idx < nodes.size() && nodes[idx] != EMPTY) {
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

TreeNode* findNode(TreeNode* node, int value) {
    if (!node)
        return NULL;
    if (node->val == value)
        return node;
    TreeNode* ret = NULL;
    if (ret = findNode(node->left, value))
        return ret;
    if (ret = findNode(node->right, value))
        return ret;
    return ret;
}