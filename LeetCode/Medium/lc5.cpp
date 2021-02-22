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
    string longestPalindrome(string s) {
        string t = "";
        t += "#";
        for (int i = 0; i < s.length(); i++) {
            t += s[i];
            t += "#";
        }
        
        vector<int> radius(t.length(), 0);
        int len = 0, idx = 0;
        int r = 0, p = 0;
        for (int i = 0; i < t.length(); i++) {
            if (i <= r)
                radius[i] = min(r - i, radius[2 * p - i]);
            else
                radius[i] = 0;
            
            while (i - radius[i] - 1 >= 0 && i + radius[i] + 1 < t.length() && t[i - radius[i] - 1] == t[i + radius[i] + 1])
                radius[i]++;
            
            if (r < i + radius[i]) {
                r = i + radius[i];
                p = i;
            }

            if (len < radius[i]) {
                len = radius[i];
                idx = i;
            }
        }
        
        idx = (idx - 1) / 2 - (len - 1) / 2;
        string answer = s.substr(idx, len);
        return answer;
    }

    string longestPalindromeV1(string s) {
        string answer = "";
        for (int i = 0, j; i < s.length(); i++) {
            for (j = 0; i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]; j++);
            if (2 * j - 1 > answer.length())
                answer = s.substr(i - j + 1, 2 * j - 1);
            if (i + 1 >= s.length() || s[i] != s[i + 1])
                continue;
            for (j = 0; i - j >= 0 && i + j + 1 < s.length() && s[i - j] == s[i + j + 1]; j++);
            if (2 * j > answer.length())
                answer = s.substr(i - j + 1, 2 * j);
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "babad",
        "cbbd",
        "a",
        "ac"
    };

    /* Output */
    vector<string> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.longestPalindrome(s[i]));

    /* Answer */
    vector<string> answer = {
        "bab",
        "bb",
        "a",
        "a"
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