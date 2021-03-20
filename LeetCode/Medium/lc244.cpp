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
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) 
            wordsIndex[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        if (word1 == word2) return 0;
        vector<int>& index1 = wordsIndex[word1];
        vector<int>& index2 = wordsIndex[word2];
        int i = 0, j = 0, mn = 0x3f3f3f3f;
        while (i < index1.size() && j < index2.size()) {
            mn = min(mn, abs(index1[i] - index2[j]));
            if (index1[i] < index2[j]) i++;
            else j++;
        }
        return mn;
    }

private:
    unordered_map<string,vector<int>> wordsIndex;
};

vector<int> simulation(vector<string>& wordsDict, vector<vector<string>>& queryWords) {
    WordDistance* wordDistance = new WordDistance(wordsDict);
    vector<int> result;
    for (vector<string>& query: queryWords)
        result.push_back(wordDistance->shortest(query[0], query[1]));
    return result;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<string> wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    vector<vector<string>> queryWords = {{"coding", "practice"}, {"makes", "coding"}};

    /* Output */
    vector<int> ret = simulation(wordsDict, queryWords);

    /* Answer */
    vector<int> answer = {3, 1};

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