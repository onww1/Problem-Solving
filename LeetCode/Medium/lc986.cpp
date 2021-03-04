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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> intersections;
        int firstPtr = 0, secondPtr = 0;
        while (firstPtr < firstList.size() && secondPtr < secondList.size()) {
            int compare = compareInterval(firstList[firstPtr], secondList[secondPtr]);
            if (!compare) {
                vector<int> intersection = getIntersection(firstList[firstPtr], secondList[secondPtr]);
                intersections.push_back(intersection);
                compare = strictCompareInterval(firstList[firstPtr], secondList[secondPtr]);
            }
            if (compare == -1) 
                firstPtr++;
            else if (compare == 1) 
                secondPtr++;
        }
        return intersections;
    }

private:
    /**
     *  If two intervals are intersected, return 0. 
     *  If {intervalA} precedes {intervalB}, return -1.
     *  Otherwise, return 1.
     */
    int compareInterval(vector<int>& intervalA, vector<int>& intervalB) {
        if (intervalA[1] < intervalB[0])
            return -1;
        if (intervalB[1] < intervalA[0])
            return 1;
        return 0;
    }

    /**
     *  If {intervalA.end} <= {intervalB.end}, return -1.
     *  Otherwise, return 1.
     */
    int strictCompareInterval(vector<int>& intervalA, vector<int>& intervalB) {
        return intervalA[1] <= intervalB[1] ? -1 : 1;
    }

    vector<int> getIntersection(vector<int>& intervalA, vector<int>& intervalB) {
        int left = max(intervalA[0], intervalB[0]);
        int right = min(intervalA[1], intervalB[1]);
        vector<int> intersection = {left, right};
        return intersection;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> firstList = {
        {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
        {{1, 3}, {5, 9}},
        {},
        {{1, 7}}
    };
    vector<vector<vector<int>>> secondList = {
        {{1, 5}, {8, 12}, {15, 24}, {25, 26}},
        {},
        {{4, 8}, {10, 12}},
        {{3, 10}}
    };

    /* Output */
    vector<vector<vector<int>>> ret;
    for (int i = 0; i < firstList.size(); i++)
        ret.push_back(solution.intervalIntersection(firstList[i], secondList[i]));

    /* Answer */
    vector<vector<vector<int>>> answer = {
        {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}},
        {},
        {},
        {{3, 7}}
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