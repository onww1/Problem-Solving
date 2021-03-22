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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int high = min((int)arr.size() - 1, (int)(lower_bound(arr.begin(), arr.end(), x) - arr.begin()));
        int low = max(0, high - 1);
        if (abs(arr[low] - x) <= abs(arr[high] - x))
            high = low;
        else
            low = high;
        
        while (high - low + 1 < k) {
            if (low > 0 && high + 1 < arr.size()) {
                if (abs(arr[low - 1] - x) <= abs(arr[high + 1] - x)) low--;
                else high++;
            }
            else if (low > 0) low--;
            else high++;
        }

        return vector<int>(arr.begin() + low, arr.begin() + high + 1);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    vector<int> k = {4, 4};
    vector<int> x = {3, -1};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < arr.size(); i++)
        ret.push_back(solution.findClosestElements(arr[i], k[i], x[i]));

    /* Answer */
    vector<vector<int>> answer = {{1, 2, 3, 4}, {1, 2, 3, 4}};

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