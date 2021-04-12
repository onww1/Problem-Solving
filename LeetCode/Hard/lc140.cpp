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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
        vector<vector<string>> sentences(s.length() + 1, vector<string>());
        sentences[0].push_back("");

        int maxLen = 0;
        for (string& word: wordDict) 
            maxLen = max(maxLen, (int)word.length());

        for (int i = 0; i < s.length(); i++) {
            if (sentences[i].empty()) continue;
            string substring = "";
            for (int j = 1; j <= maxLen && i + j <= s.length(); j++) {
                substring += s[i + j - 1];
                if (hashSet.count(substring))
                    for (string& sentence: sentences[i]) {
                        sentences[i + j].push_back(sentence + (i > 0 ? " ": "") + substring);
                    }
            }
        }
        
        return sentences[s.length()];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {"catsanddog", "pineapplepenapple", "catsandog"};
    vector<vector<string>> wordDict = {
        {"cat", "cats", "and", "sand", "dog"},
        {"apple", "pen", "applepen", "pine", "pineapple"},
        {"cats", "dog", "sand", "and", "cat"}
    };

    /* Output */
    vector<vector<string>> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.wordBreak(s[i], wordDict[i]));

    /* Answer */
    vector<vector<string>> answer = {
        {"cats and dog","cat sand dog"},
        {"pine apple pen apple","pineapple pen apple","pine applepen apple"},
        {}
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