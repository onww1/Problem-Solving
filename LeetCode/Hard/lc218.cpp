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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline;
        priority_queue<pair<int,int>> maxHeap;  // (Height, Right)

        sort(buildings.begin(), buildings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[2] > b[2] : a[0] < b[0];
        });
        
        for (int i = 0; i < buildings.size(); i++) {
            while (!maxHeap.empty() && maxHeap.top().second < buildings[i][0]) {
                pair<int,int> cur = maxHeap.top();
                maxHeap.pop();

                while (!maxHeap.empty() && maxHeap.top().second <= cur.second)
                    maxHeap.pop();

                if (maxHeap.empty()) skyline.push_back({cur.second, 0});
                else skyline.push_back({cur.second, maxHeap.top().first});
            }

            if (maxHeap.empty() || maxHeap.top().first < buildings[i][2]) 
                skyline.push_back({buildings[i][0], buildings[i][2]});
            maxHeap.emplace(buildings[i][2], buildings[i][1]);
        }

        while (!maxHeap.empty()) {
            pair<int,int> cur = maxHeap.top();
            maxHeap.pop();

            while (!maxHeap.empty() && maxHeap.top().second <= cur.second)
                maxHeap.pop();

            if (maxHeap.empty()) skyline.push_back({cur.second, 0});
            else skyline.push_back({cur.second, maxHeap.top().first});
        }

        return skyline;
    }
};

/*
    
*/

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> buildingsVec = {
        {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}},
        {{0, 2, 3}, {2, 5, 3}}
    };

    /* Output */
    vector<vector<vector<int>>> ret;
    for (vector<vector<int>>& buildings: buildingsVec)
        ret.push_back(solution.getSkyline(buildings));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}},
        {{0, 3}, {5, 0}}
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