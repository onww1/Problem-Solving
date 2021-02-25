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
    Solution(vector<int>& w) {
        prefixSum = w;
        n = prefixSum.size();
        for (int i = 1; i < prefixSum.size(); i++)
            prefixSum[i] += prefixSum[i - 1];
        size = prefixSum.back();
    }
    
    int pickIndex() {
        int value = rand() % size + 1;
        int index = binarySearch(value);
        return index;
    }

private:
    int n;
    int size;
    vector<int> prefixSum;

    int binarySearch(int value) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (value <= prefixSum[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

vector<int> simulation(vector<int>& weights, int k) {
    Solution* solution = new Solution(weights);
    vector<int> results;
    for (int i = 0; i < k; i++)
        results.push_back(solution->pickIndex());
    return results;
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<vector<int>> weights = {
        {1},
        {1, 3}
    };
    vector<int> k = {1, 5};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < weights.size(); i++) 
        ret.push_back(simulation(weights[i], k[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {0},
        {1, 1, 1, 1, 0}
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