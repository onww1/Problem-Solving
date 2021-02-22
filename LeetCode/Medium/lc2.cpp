#include <algorithm>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        while (l1 || l2) {
            if (!ptr->next)
                ptr->next = new ListNode(0);
            if (ptr->val > 9) {
                ptr->next->val += ptr->val / 10;
                ptr->val %= 10;
            }
            if (l1) {
                ptr->next->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                ptr->next->val += l2->val;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (ptr->val > 9) {
            ptr->next = new ListNode(ptr->val / 10);
            ptr->val %= 10;
        }
        return head->next;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> l1Nodes = {
        {2, 4, 3},
        {0},
        {9, 9, 9, 9, 9, 9, 9}
    };
    vector<vector<int>> l2Nodes = {
        {5, 6, 4},
        {0},
        {9, 9, 9, 9}
    };

    vector<ListNode*> l1, l2;
    for (int i = 0; i < l1Nodes.size(); i++) {
        l1.push_back(makeList(l1Nodes[i]));
        l2.push_back(makeList(l2Nodes[i]));
    }

    /* Output */
    vector<ListNode*> ret;
    for (int i = 0; i < l1.size(); i++)
        ret.push_back(solution.addTwoNumbers(l1[i], l2[i]));

    /* Answer */
    vector<vector<int>> answerNodes = {
        {7, 0, 8},
        {0},
        {8, 9, 9, 9, 0, 0, 0, 1}
    };
    vector<ListNode*> answer;
    for (int i = 0; i < answerNodes.size(); i++)
        answer.push_back(makeList(answerNodes[i]));

    /* Check */
    bool accept = true;
    for (int i = 0; i < ret.size(); i++)
        accept &= matchList(ret[i], answer[i]);

    assert(accept);

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