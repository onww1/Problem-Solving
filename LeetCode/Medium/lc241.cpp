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
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        parseExpression(expression, nums, ops);

        if (ops.empty()) return nums;

        int n = nums.size(), m = ops.size();
        vector<vector<vector<int>>> values(m, vector<vector<int>>(m, vector<int>()));

        for (int i = 0; i < m; i++)
            values[i][i].push_back(calculate(ops[i], nums[i], nums[i + 1]));

        for (int len = 2; len <= m; len++) {
            for (int left = 0; left + len - 1 < m; left++) {
                int right = left + len - 1;
                // leftmost
                for (int value: values[left + 1][right])
                    values[left][right].push_back(calculate(ops[left], nums[left], value));

                // rightmost
                for (int value: values[left][right - 1])
                    values[left][right].push_back(calculate(ops[right], value, nums[right + 1]));

                // between
                for (int k = left + 1; k < right; k++) {
                    for (int lValue: values[left][k - 1])
                        for (int rValue: values[k + 1][right])
                            values[left][right].push_back(calculate(ops[k], lValue, rValue));
                }
            }
        }

        return values[0][m - 1];
    }

private:
    int calculate(char op, int a, int b) {
        if (op == '+') 
            return a + b;
        else if (op == '-') 
            return a - b;
        else 
            return a * b;
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    void parseExpression(string& expression, vector<int>& nums, vector<char>& ops) {
        int num = 0;
        for (char c: expression) {
            if (isDigit(c)) {
                num = num * 10 + c - '0';
            } else {
                ops.push_back(c);
                nums.push_back(num);
                num = 0;
            }
        }
        nums.push_back(num);
    }
};

// nums = [2, 1, 1], ops = ['-', '-']
// values[0][0] = [1], values[1][1] = [0]
// values[0][1] = [1 - 1, 2 - 0] = [0, 2]

// nums = [2, 3, 4, 5], ops = ['*', '-', '*']
// values[0][0] = [6], values[1][1] = [-1], values[2][2] = [20]
// values[0][1] = [6 - 4, 2 * -1] = [2, -2], values[1][2] = [-1 * 5, 3 - 20] = [-5, -17]
// values[0][2] = [2 * -5, 2 * -17, 6 - 20, 2 * 5, -2 * 5] = [-10, -34, -14, 10, -10]

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> expressions = {
        "2-1-1",
        "2*3-4*5"
    };

    /* Output */
    vector<vector<int>> ret;
    for (string& expression: expressions) {
        vector<int> result = solution.diffWaysToCompute(expression);
        sort(result.begin(), result.end());
        ret.push_back(result);
    }

    /* Answer */
    vector<vector<int>> answer = {
        {0, 2},
        {-34, -14, -10, -10, 10}
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