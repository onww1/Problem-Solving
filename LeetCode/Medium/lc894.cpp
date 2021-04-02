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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> allFBTs;

        if (n % 2 == 0) 
            return allFBTs;

        if (!cache.count(n)) {
            if (n == 1) {
                allFBTs.push_back(new TreeNode(0));
            } else {
                for (int i = 1; i < n; i += 2) {
                    for (TreeNode* leftFBT: allPossibleFBT(i)) {
                        for (TreeNode* rightFBT: allPossibleFBT(n - 1 - i)) {
                            TreeNode* root = new TreeNode(0);
                            root->left = leftFBT;
                            root->right = rightFBT;
                            allFBTs.push_back(root);
                        }
                    }
                }
            }
            cache[n] = allFBTs;
        }

        return cache[n];
    }

private:
    unordered_map<int, vector<TreeNode*>> cache;
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> nVec = {7, 3};

    /* Output */
    vector<vector<TreeNode*>> ret;
    for (int n: nVec)
        ret.push_back(solution.allPossibleFBT(n));

    /* Answer */
    vector<vector<vector<int>>> treeNodes = {
        {
            {0, 0, 0, EMPTY, EMPTY, 0, 0, EMPTY, EMPTY, 0, 0},
            {0, 0, 0, EMPTY, EMPTY, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, EMPTY, EMPTY, EMPTY, EMPTY, 0, 0},
            {0, 0, 0, 0, 0, EMPTY, EMPTY, 0, 0}
        },
        {
            {0, 0, 0}
        }
    };

    vector<vector<TreeNode*>> answer;
    for (vector<vector<int>>& nodesVec: treeNodes) {
        vector<TreeNode*> answerVec;
        for (vector<int>& nodes: nodesVec) 
            answerVec.push_back(makeTree(nodes));
        answer.push_back(answerVec);
    }

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            match &= matchTree(ret[i][j], answer[i][j]);
        }
    }
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
