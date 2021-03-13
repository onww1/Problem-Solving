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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (!isPossible(gas, cost))
            return -1;
        
        vector<int> candidates = getCandidates(gas, cost);
        for (int candidate: candidates) 
            if (canTravel(gas, cost, candidate))
                return candidate;
        
        return -1;
    }

private:
    bool isPossible(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for (int i = 0; i < gas.size(); i++)
            sum += gas[i] - cost[i];
        return sum >= 0;
    }

    vector<int> getCandidates(vector<int>& gas, vector<int>& cost) {
        vector<int> candidates;
        int minusIndex = -1;
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] >= cost[i]) {
                if (minusIndex + 1 == i)
                    candidates.push_back(i);
            } else {
                minusIndex = i;
            }
        }
        return candidates;
    }

    bool canTravel(vector<int>& gas, vector<int>& cost, int startIndex) {
        int n = gas.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int idx = (i + startIndex) % n;
            sum += gas[idx] - cost[idx];
            if (sum < 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> gas = {
        {1, 2, 3, 4, 5},
        {2, 3, 4}
    };
    vector<vector<int>> cost = {
        {3, 4, 5, 1, 2},
        {3, 4, 3}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < gas.size(); i++)
        ret.push_back(solution.canCompleteCircuit(gas[i], cost[i]));

    /* Answer */
    vector<int> answer = {3, -1};

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