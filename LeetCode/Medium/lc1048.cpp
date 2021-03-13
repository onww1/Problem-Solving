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
    int longestStrChain(vector<string>& words) {
        preprocess(words);
        int longestChainLength = 1;
        for (int i = 2; i <= 16; i++) {
            for (int j = 0; j < wordList[i].size(); j++) {
                for (int k = 0; k < wordList[i - 1].size(); k++) {
                    if (isSubsequence(wordList[i][j], wordList[i - 1][k])) {
                        longestChain[i][j] = max(longestChain[i][j], longestChain[i - 1][k] + 1);
                        longestChainLength = max(longestChainLength, longestChain[i][j]);
                    }
                }
            }
        }
        return longestChainLength;
    }

private:
    vector<vector<string>> wordList;
    vector<vector<int>> longestChain;

    void preprocess(vector<string>& words) {
        wordList.clear();
        wordList.resize(17);
        wordList.assign(17, vector<string>());

        longestChain.clear();
        longestChain.resize(17);
        longestChain.assign(17, vector<int>());

        for (string& word: words) {
            int length = word.length();
            wordList[length].push_back(word);
            longestChain[length].push_back(1);
        }
    }

    bool isSubsequence(string& longer, string& shorter) {
        int i = 0, j = 0;
        while (i < longer.length() && j < shorter.length()) {
            if (longer[i] != shorter[j]) {
                i++;
            } else {
                i++; j++;
            }
        }
        return i == j || i == j + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<string>> wordsVec = {
        {"a", "b", "ba", "bca", "bda", "bdca"},
        {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"}
    };

    /* Output */
    vector<int> ret;
    for (vector<string>& words: wordsVec)
        ret.push_back(solution.longestStrChain(words));

    /* Answer */
    vector<int> answer = {4, 5};

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