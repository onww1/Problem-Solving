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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> kNodes;
        solve(root, target, K, INF, kNodes);
        return kNodes;
    }

private:
    const int INF = 0x3f3f3f3f;

    int solve(TreeNode* node, TreeNode* target, int K, int dist, vector<int>& kNodes) {
        if (!node) return INF;
        if (node->val == target->val) dist = 0;
        if (dist == K) {
            kNodes.push_back(node->val);
            return dist + 1;
        }

        if (dist < INF) {
            dist = min(dist, solve(node->left, target, K, dist + 1, kNodes));
            dist = min(dist, solve(node->right, target, K, dist + 1, kNodes));
        } else {
            int ret = solve(node->left, target, K, dist + 1, kNodes);
            dist = min(dist, ret);
            ret = solve(node->right, target, K, dist + 1, kNodes);
            if (dist >= INF && ret < INF) {
                dist = ret;
                ret = solve(node->left, target, K, dist + 1, kNodes);
            }
            if (dist == K) kNodes.push_back(node->val);
        }
        return dist + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> treeNodes = {
        {3, 5, 1, 6, 2, 0, 8, EMPTY, EMPTY, 7, 4}
    };
    vector<int> tNodes = {5};
    vector<int> K = {2};

    vector<TreeNode*> root;
    for (vector<int>& nodes: treeNodes)
        root.push_back(makeTree(nodes));

    vector<TreeNode*> target;
    for (int tnode: tNodes)
        target.push_back(new TreeNode(tnode));

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < target.size(); i++)
        ret.push_back(solution.distanceK(root[i], target[i], K[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {7, 4, 1}
    };

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