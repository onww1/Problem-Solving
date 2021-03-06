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
    int divide(int dividend, int divisor) {
        if (dividend == 0x80000000 && divisor == -1)
            return 0x7fffffff;
        if (divisor == 1)
            return dividend;
        if (dividend == divisor)
            return 1;
        if (divisor == 0x80000000)
            return 0;

        int answer = 0;
        if (dividend == 0x80000000) {
            if (divisor > 0) dividend += divisor;
            else dividend -= divisor;
            answer++;
        }

        bool isMinus = true;
        if (dividend < 0) {
            dividend = ~dividend + 1;
            isMinus ^= true;
        }
        if (divisor < 0) {
            divisor = ~divisor + 1;
            isMinus ^= true;
        }

        int firstPos = 30;
        while ((divisor & (1 << firstPos)) == 0)
            firstPos--;

        int lim = 30 - firstPos;
        for (int pos = lim; pos >= 0; pos--) {
            if (dividend >= (divisor << pos)) {
                answer += (1 << pos);
                dividend -= (divisor << pos);
            }
        }

        if (!isMinus)
            answer = ~answer + 1;
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> dividend = {10, 7, 0, 1};
    vector<int> divisor = {3, -3, 1, 1};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < dividend.size(); i++)
        ret.push_back(solution.divide(dividend[i], divisor[i]));

    /* Answer */
    vector<int> answer = {3, -2, 0, 1};

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