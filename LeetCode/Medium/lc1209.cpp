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
struct Data {
    char c;
    int count;
    Data(): Data('a', 0) {}
    Data(char _c, int _count): c(_c), count(_count) {}
    string toString() {
        return string(count, c);
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<Data> stack;
        for (int i = 0; i < s.length(); i++) {
            if (stack.empty() || stack.back().c != s[i])
                stack.emplace_back(s[i], 1);
            else
                stack.back().count++;
            
            while (!stack.empty() && stack.back().count >= k) {
                stack.back().count -= k;
                if (stack.back().count == 0)
                    stack.pop_back();
            }
        }

        string answer = "";
        for (int i = 0; i < stack.size(); i++)
            answer += stack[i].toString();

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "abcd",
        "deeedbbcccbdaa",
        "pbbcggttciiippooaais"
    };
    vector<int> k = {2, 3, 2};

    /* Output */
    vector<string> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.removeDuplicates(s[i], k[i]));

    /* Answer */
    vector<string> answer = {
        "abcd",
        "aa",
        "ps"
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