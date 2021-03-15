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
class SparseVector {
public:
    vector<pair<int,int>> elements;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                elements.emplace_back(nums[i], i);
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int answer = 0;
        int i = 0, j = 0;
        while (i < elements.size() && j < vec.elements.size()) {
            if (elements[i].second == vec.elements[j].second) {
                answer += elements[i].first * vec.elements[j].first;
                i++; j++;
            }
            else if (elements[i].second > vec.elements[j].second) {
                j++;
            }
            else {
                i++;
            }
        }
        return answer;
    }
};

int dotProduct(vector<int>& nums1, vector<int>& nums2) {
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    return v1.dotProduct(v2);
}

int main(int argc, char *argv[]) {
    /* Input */
    vector<vector<int>> nums1 = {
        {1, 0, 0, 2, 3},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 2, 0, 0}
    };
    vector<vector<int>> nums2 = {
        {0, 3, 0, 4, 0},
        {0, 0, 0, 0, 2},
        {1, 0, 0, 0, 3, 0, 4}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums1.size(); i++)
        ret.push_back(dotProduct(nums1[i], nums2[i]));

    /* Answer */
    vector<int> answer = {8, 0, 6};
    
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