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
    int minAbsDifference(vector<int>& nums, int goal) {
        int size = nums.size();
        int hsize = size / 2;
        int answer = INF;
        
        vector<int> sums;
        int lim = 1 << hsize;
        for (int i = 0; i < lim; i++) {
            int sum = 0;
            for (int j = 0; j < hsize; j++) 
                if (i & (1 << j)) 
                    sum += nums[j];
            answer = min(answer, abs(goal - sum));
            sums.push_back(sum);
        }

        sort(sums.begin(), sums.end());

        lim = 1 << (size - hsize);
        for (int i = 0; i < lim; i++) {
            int sum = 0;
            for (int j = hsize; j < size; j++)
                if (i & (1 << (j - hsize)))
                    sum += nums[j];
            answer = min(answer, abs(goal - sum));

            int idx = upper_bound(sums.begin(), sums.end(), goal - sum) - sums.begin();
            if (idx < sums.size()) answer = min(answer, abs(goal - sum - sums[idx]));
            idx--;
            if (idx >= 0) answer = min(answer, abs(goal - sum - sums[idx]));
        }

        return answer;
    }

private:
    const int INF = 0x3f3f3f3f;
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {5, -7, 3, 5},
        {7, -9, 15, -2},
        {1, 2, 3}
    };
    vector<int> goal = {6, -5, -7};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.minAbsDifference(nums[i], goal[i]));

    /* Answer */
    vector<int> answer = {0, 1, 7};

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