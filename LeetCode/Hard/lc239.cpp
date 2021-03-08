#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include <deque>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        
        deque<pair<int,int>> dq;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front().second + k <= i)
                dq.pop_front();
            while (!dq.empty() && dq.back().first <= nums[i])
                dq.pop_back();
            dq.emplace_back(nums[i], i);
            if (i >= k - 1)
                result.push_back(dq.front().first);
        }

        return result;
    }

    vector<int> maxSlidingWindowV1(vector<int>& nums, int k) {
        vector<int> result;

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < k - 1; i++)
            pq.emplace(nums[i], i);
        
        for (int i = k - 1; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
            while (!pq.empty() && pq.top().second + k <= i)
                pq.pop();
            result.push_back(pq.top().first);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 3, -1, -3, 5, 3, 6, 7},
        {1},
        {1, -1},
        {9, 11},
        {4, -2}
    };
    vector<int> k = {3, 1, 1, 2, 2};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.maxSlidingWindow(nums[i], k[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {3, 3, 5, 5, 6, 7},
        {1},
        {1, -1},
        {11},
        {4}
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