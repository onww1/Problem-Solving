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
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.length(), vector<int>(p.length(), -1));
        return solve(0, 0, s, p, cache) == 1;
    }

private:
    int solve(int sidx, int pidx, string& s, string& p, vector<vector<int>>& cache) {
        if (sidx == s.length() && pidx == p.length()) 
            return 1;
        if (pidx == p.length()) 
            return 0;
        if (sidx == s.length()) {
            int rest = (int)p.length() - pidx;
            int asterisks = (rest % 2 == 0);
            for (int i = pidx + 1; i < p.length(); i += 2)
                asterisks &= (p[i] == '*');
            return asterisks;
        }
            
        int& ret = cache[sidx][pidx];
        if (ret != -1) return ret;
        ret = 0;
        
        bool asterisk = (pidx + 1 < p.length() && p[pidx + 1] == '*');
        if (asterisk) {
            ret = solve(sidx, pidx + 2, s, p, cache);
            for (int i = sidx; i < s.length(); i++) {
                if (!canMatch(s[i], p[pidx]) || ret == 1) break;
                ret = solve(i + 1, pidx + 2, s, p, cache);
            }
        } 
        else if (canMatch(s[sidx], p[pidx])) {
            ret = solve(sidx + 1, pidx + 1, s, p, cache);
        }

        return ret;
    }

    bool canMatch(char a, char b) {
        if (b == '.') 
            return true;
        return a == b;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {"aa", "aa", "ab", "aab", "mississippi"};
    vector<string> p = {"a", "a*", ".*", "c*a*b", "mis*is*p*."};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.isMatch(s[i], p[i]));

    /* Answer */
    vector<bool> answer = {false, true, true, true, false};
    
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