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
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        if (x < y) swap(x, y);
        if (x == 1 && y == 0) return 3;
        if (x == 2 && y == 2) return 4;
        int delta = x - y;
        if (y > delta) 
            return delta - (delta - y - 3) / 3 * 2;
        else 
            return delta - (delta - y) / 4 * 2;
    }

    int minKnightMovesV1(int x, int y) {
        vector<vector<int>> dp(MAX, vector<int>(MAX, -1));
        dp[0][0] = 0;
        dp[1][1] = 2;
        dp[2][2] = 4;
        dp[0][1] = dp[1][0] = 3;
        dp[0][2] = dp[2][0] = 2;
        dp[1][2] = dp[2][1] = 1;
        return solve(x, y, dp);
    }

private:
    const int MAX = 3e2 + 1;

    int solve(int x, int y, vector<vector<int>>& dp) {
        x = abs(x);
        y = abs(y);
        
        if (dp[x][y] != -1)
            return dp[x][y];
        
        dp[x][y] = min(solve(x - 1, y - 2, dp), solve(x - 2, y - 1, dp)) + 1;
        return dp[x][y];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> x = {2, 5};
    vector<int> y = {1, 5};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < x.size(); i++)
        ret.push_back(solution.minKnightMoves(x[i], y[i]));

    /* Answer */
    vector<int> answer = {1, 4};

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

