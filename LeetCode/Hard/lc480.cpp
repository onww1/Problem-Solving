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
class IndexTree {
public:
    IndexTree(int n) {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.resize(size << 1);
        tree.assign(size << 1, 0);
    }

    void update(int node, int value) {
        node += size;
        while (node) {
            tree[node] += value;
            node >>= 1;
        }
    }

    int kth(int k) {
        int node = 1;
        while (node < size) {
            if (tree[node << 1] < k) {
                k -= tree[node << 1];
                node = node << 1 | 1;
            } else {
                node <<= 1;
            }
        }
        return node - size;
    }
private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> uniqueNums = nums;
        sort(uniqueNums.begin(), uniqueNums.end());
        uniqueNums.resize(unique(uniqueNums.begin(), uniqueNums.end()) - uniqueNums.begin());

        IndexTree* indexTree = new IndexTree((int)uniqueNums.size());
        for (int i = 0; i < k; i++) 
            indexTree->update(find(uniqueNums, nums[i]), 1);
        
        vector<double> result = {median(indexTree, k, uniqueNums)};
        for (int i = k; i < nums.size(); i++) {
            indexTree->update(find(uniqueNums, nums[i]), 1);
            indexTree->update(find(uniqueNums, nums[i - k]) , -1);
            result.push_back(median(indexTree, k, uniqueNums));
        }

        return result;
    }

private:
    int find(vector<int>& vec, int target) {
        int idx = lower_bound(vec.begin(), vec.end(), target) - vec.begin();
        if (idx < vec.size() && vec[idx] == target)
            return idx;
        return -1;
    }

    double median(IndexTree* indexTree, int k, vector<int>& uniqueNums) {
        int idx = (k + 1) / 2;
        double medianValue = uniqueNums[indexTree->kth(idx)];
        if (k % 2 == 0) 
            medianValue = (medianValue + uniqueNums[indexTree->kth(idx + 1)]) / 2.0;
        return medianValue;    
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 3, -1, -3, 5, 3, 6, 7}
    };
    vector<int> k = {3};

    /* Output */
    vector<vector<double>> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.medianSlidingWindow(nums[i], k[i]));

    /* Answer */
    vector<vector<double>> answer = {
        {1.0, -1.0, -1.0, 3.0, 5.0, 6.0}
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