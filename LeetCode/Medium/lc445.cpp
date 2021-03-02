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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        vector<ListNode*> l1Vector = listToVector(l1);
        vector<ListNode*> l2Vector = listToVector(l2);

        if (l1Vector.size() < l2Vector.size()) {
            swap(l1, l2);
            swap(l1Vector, l2Vector);
        }

        int carry = 0;
        while (!l1Vector.empty()) {
            int sum = carry + l1Vector.back()->val;
            if (!l2Vector.empty()) {
                sum += l2Vector.back()->val;
                l2Vector.pop_back();
            }
            carry = sum / 10;
            l1Vector.back()->val = sum % 10;
            l1Vector.pop_back();
        }
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = l1;
            l1 = newHead;
            carry = 0;
        }
        return l1;
    }

private:
    vector<ListNode*> listToVector(ListNode* head) {
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        return vec;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> l1Nodes = {
        {7, 2, 4, 3}
    };
    vector<vector<int>> l2Nodes = {
        {5, 6, 4}
    };

    vector<ListNode*> l1;
    vector<ListNode*> l2;

    for (vector<int>& nodes: l1Nodes)
        l1.push_back(makeList(nodes));
    for (vector<int>& nodes: l2Nodes)
        l2.push_back(makeList(nodes));

    /* Output */
    vector<ListNode*> ret;
    for (int i = 0; i < l1.size(); i++)
        ret.push_back(solution.addTwoNumbers(l1[i], l2[i]));

    /* Answer */
    vector<vector<int>> ansNodes = {
        {7, 8, 0, 7}
    };

    vector<ListNode*> answer;

    for (vector<int>& nodes: ansNodes)
        answer.push_back(makeList(nodes));

    /* Check */
    bool match = true;
    for (int i = 0; i < ret.size(); i++)
        match &= matchList(ret[i], answer[i]);
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