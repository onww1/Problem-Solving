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
    int calculate(string s) {
        vector<char> operators;
        vector<int> numbers;

        int number = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isOperator(s[i])) {
                if (!operators.empty() && isMulDiv(operators.back())) {
                    if (operators.back() == '*')
                        numbers.back() *= number;
                    else
                        numbers.back() /= number;
                    operators.pop_back();
                } else {
                    numbers.push_back(number);
                }
                operators.push_back(s[i]);
                number = 0;
            }
            else if (isDigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
        }
        if (!operators.empty() && isMulDiv(operators.back())) {
            if (operators.back() == '*')
                numbers.back() *= number;
            else
                numbers.back() /= number;
            operators.pop_back();
        } else {
            numbers.push_back(number);
        }

        for (int i = 0; i < operators.size(); i++) {
            switch (operators[i]) {
                case '+':
                    numbers[i + 1] = numbers[i] + numbers[i + 1];
                    break;
                case '-':
                    numbers[i + 1] = numbers[i] - numbers[i + 1];
                    break;
                case '*':
                    numbers[i + 1] = numbers[i] * numbers[i + 1];
                    break;
                case '/':
                    numbers[i + 1] = numbers[i] / numbers[i + 1];
                    break;
            }
        }

        return numbers.back();
    }

private:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool isMulDiv(char c) {
        return c == '*' || c == '/';
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "3+2*2",
        " 3/2 ",
        " 3+5 / 2 "
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.calculate(s[i]));

    /* Answer */
    vector<int> answer = {7, 1, 5};

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