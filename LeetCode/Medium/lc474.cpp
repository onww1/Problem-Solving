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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (string& str : strs) {
            pair<int,int> count = countBinary(str);
            for (int r = m; r >= count.first; r--) {
                for (int c = n; c >= count.second; c--) {
                    dp[r][c] = max(dp[r][c], dp[r - count.first][c - count.second] + 1);
                }
            }
        }

        return dp[m][n];
    }

private:
    pair<int,int> countBinary(string& binary) {
        int zero = 0;
        int one = 0;
        for (char c : binary) {
            if (c == '0') {
                zero++;
            } else {
                one++;
            }
        }
        return {zero, one};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    const int numOfTestCase = 2;
    vector<string> strs[numOfTestCase] = {
        {"10", "0001", "111001", "1", "0"},
        {"10", "0", "1"}
    };
    int m[numOfTestCase] = {5, 1};
    int n[numOfTestCase] = {3, 1};

    /* Output */
    vector<int> output;
    for (int i = 0; i < numOfTestCase; i++) {
        output.push_back(solution.findMaxForm(strs[i], m[i], n[i]));
    }

    /* Answer */
    vector<int> answer = {4, 2};

    /* Check */
    assert(output == answer);

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