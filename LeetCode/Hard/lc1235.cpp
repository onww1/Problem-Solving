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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        init(startTime, endTime);

        int size = (int)numbers.size();
        vector<int> dp(size + 1, 0);
        for (int i = 1, j = 0; i <= size; i++) {
            dp[i] = dp[i - 1];
            while (j < index.size() && i == endTime[index[j]]) {
                dp[i] = max(dp[i], dp[startTime[index[j]] - 1] + profit[index[j]]);
                j++;
            }
        }
        return dp[size];
    }

private:
    vector<int> numbers;
    vector<int> index;

    int getIndex(int number) {
        return (int)(lower_bound(numbers.begin(), numbers.end(), number) - numbers.begin()) + 1;
    }

    void init(vector<int>& startTime, vector<int>& endTime) {
        numbers.clear();
        for (int &t: startTime)
            numbers.push_back(t);
        for (int &t: endTime)
            numbers.push_back(--t);
        sort(numbers.begin(), numbers.end());
        numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());

        for (int& start: startTime)
            start = getIndex(start);
        for (int& end: endTime)
            end = getIndex(end);

        index.clear();
        for (int i = 0; i < startTime.size(); i++)
            index.push_back(i);
        sort(index.begin(), index.end(), [&startTime, &endTime](int a, int b) {
            return endTime[a] == endTime[b] ? startTime[a] < startTime[b] : endTime[a] < endTime[b];
        });
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> startTimes = {
        {1, 2, 3, 3},
        {1, 2, 3, 4, 6},
        {1, 1, 1}
    };
    vector<vector<int>> endTimes = {
        {3, 4, 5, 6},
        {3, 5, 10, 6, 9},
        {2, 3, 4}
    };
    vector<vector<int>> profits = {
        {50, 10, 40, 70},
        {20, 20, 100, 70, 60},
        {5, 6, 4}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < startTimes.size(); i++)
        ret.push_back(solution.jobScheduling(startTimes[i], endTimes[i], profits[i]));

    /* Answer */
    vector<int> answer = {120, 150, 6};
    
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