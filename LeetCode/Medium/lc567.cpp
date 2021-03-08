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
    bool checkInclusion(string s1, string s2) {
        int length = s1.length();
        int numNonZero = 0;
        int count[26]{};

        for (char c: s1)
            if (!count[c - 'a']++)
                numNonZero++;

        for (int i = 0; i < s2.length(); i++) {
            int right = s2[i] - 'a';
            --count[right];
            if (count[right] == 0) numNonZero--;
            if (count[right] == -1) numNonZero++;

            if (i >= length) {
                int left = s2[i - length] - 'a';
                ++count[left];
                if (count[left] == 0) numNonZero--;
                if (count[left] == 1) numNonZero++;
            }

            if (i >= length - 1 && numNonZero == 0)
                return true;
        }

        return false;    
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s1 = {"ab", "ab"};
    vector<string> s2 = {"eidbaooo", "eidboaoo"};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < s1.size(); i++)
        ret.push_back(solution.checkInclusion(s1[i], s2[i]));

    /* Answer */
    vector<bool> answer = {true, false};

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