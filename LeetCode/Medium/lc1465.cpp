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
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxH = getMaxGap(h, horizontalCuts);
        int maxW = getMaxGap(w, verticalCuts);
        int answer = 1LL * maxH * maxW % MOD;
        return answer;
    }

private:
    const int MOD = 1e9 + 7;

    int getMaxGap(int length, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int maxGap = length - cuts.back();
        int prevCut = 0;
        for (int cut: cuts) {
            maxGap = max(maxGap, cut - prevCut);
            prevCut = cut;
        }
        return maxGap;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> h = {5, 5, 5};
    vector<int> w = {4, 4, 4};
    vector<vector<int>> horizontalCuts = {
        {1, 2, 4},
        {3, 1},
        {3}
    };
    vector<vector<int>> verticalCuts = {
        {1, 3},
        {1},
        {3}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < h.size(); i++)
        ret.push_back(solution.maxArea(h[i], w[i], horizontalCuts[i], verticalCuts[i]));

    /* Answer */
    vector<int> answer = {4, 6, 9};
    
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