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
    int countArrangement(int n) {
        vector<vector<int>> candidates = getCandidates(n);
        int count = countAllArrangement(1, 0, n, candidates);
        return count;
    }

private:
    int countAllArrangement(int index, int state, int n, vector<vector<int>>& candidates) {
        if (state + 1 == (1 << n))
            return 1;
        
        int count = 0;
        for (int candidate: candidates[index]) {
            if (state & (1 << (candidate - 1)))
                continue;
            count += countAllArrangement(index + 1, state | (1 << (candidate - 1)), n, candidates);
        }
        return count;
    }

    vector<vector<int>> getCandidates(int n) {
        vector<vector<int>> candidates(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                if (i % j == 0 || j % i == 0)
                    candidates[i].push_back(j);
        return candidates;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> inputs = {2, 1};

    /* Output */
    vector<int> ret;
    for (int n: inputs)
        ret.push_back(solution.countArrangement(n));

    /* Answer */
    vector<int> answer = {2, 1};

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