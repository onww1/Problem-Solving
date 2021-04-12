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
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*,TreeNode*)> isSame = [&](TreeNode* u, TreeNode* v) {
            if (!u && !v) return true;
            if (!u || !v) return false;
            if (u->val != v->val) return false;
            return isSame(u->left, v->right) && isSame(u->right, v->left);
        };
        return isSame(root->left, root->right);
    }

    bool isSymmetricV1(TreeNode* root) {
        if (!root->left && !root->right)
            return true;
        if (!isSameV1(root->left, root->right)) 
            return false;

        queue<TreeNode*> lq, rq;
        lq.push(root->left);
        rq.push(root->right);

        while (!lq.empty() && !rq.empty()) {
            TreeNode* lv = lq.front(); lq.pop();
            TreeNode* rv = rq.front(); rq.pop();
            if (!isSameV1(lv->left, rv->right) || !isSameV1(lv->right, rv->left)) 
                return false;
            if (lv->left) {
                lq.push(lv->left);
                rq.push(rv->right);
            }
            if (lv->right) {
                lq.push(lv->right);
                rq.push(rv->left);
            }
        }

        return true;
    }

private:
    bool isSameV1(TreeNode* u, TreeNode* v) {
        if (!u && !v) return true;
        if (!u || !v) return false;
        return u->val == v->val;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> treeNodes = {
        {1, 2, 2, 3, 4, 4, 3},
        {1, 2, 2, EMPTY, 3, EMPTY, 3}
    };
    vector<TreeNode*> root;
    for (vector<int>& nodes: treeNodes)
        root.push_back(makeTree(nodes));

    /* Output */
    vector<bool> ret;
    for (TreeNode* node: root)
        ret.push_back(solution.isSymmetric(node));

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