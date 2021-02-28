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
    vector<int> dailyTemperaturesV1(vector<int>& T) {
        // naive
        int n = T.size();
        vector<int> recentPosition(101, n);
        vector<int> answer(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int recentPos = n;
            for (int j = T[i] + 1; j <= 100; j++) 
                recentPos = min(recentPos, recentPosition[j]);
            if (recentPos != n)
                answer[i] = recentPos - i;
            recentPosition[T[i]] = i;
        }
        return answer;
    }

    vector<int> dailyTemperaturesV2(vector<int>& T) {
        // segment tree
        int n = T.size();
        initTree(n);

        priority_queue<pair<int,int>> maxHeap;
        for (int i = 0; i < n; i++)
            maxHeap.emplace(T[i], -i);
        
        vector<int> answer(n, 0);
        while (!maxHeap.empty()) {
            int temperature = maxHeap.top().first;
            int index = -maxHeap.top().second;
            maxHeap.pop();

            int nearestIndex = getMin(1, 0, n - 1, index + 1, n - 1);
            if (nearestIndex != INF)
                answer[index] = nearestIndex - index;
            
            updateTree(1, 0, n - 1, index, index);
        }
        
        return answer;
    }

    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> answer(n, 0);

        vector<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && T[stack.back()] < T[i]) {
                int index = stack.back();
                stack.pop_back();
                answer[index] = i - index;
            }
            stack.push_back(i);
        }

        return answer;
    }

private:
    const int INF = 0x3f3f3f3f;
    int size;
    vector<int> tree;

    void initTree(int n) {
        size = 1;
        while (size < n) 
            size <<= 1;
        tree.resize(size << 1);
        tree.assign(size << 1, INF);
    }

    void updateTree(int node, int start, int end, int pos, int value) {
        if (pos < start || end < pos)
            return;
        if (start == end) {
            tree[node] = value;
            return;
        }
        int mid = (start + end) >> 1;
        updateTree(node << 1, start, mid, pos, value);
        updateTree(node << 1 | 1, mid + 1, end, pos, value);
        tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    }

    int getMin(int node, int start, int end, int left, int right) {
        if (end < left || right < start)
            return INF;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) >> 1;
        return min(getMin(node << 1, start, mid, left, right),
                   getMin(node << 1 | 1, mid + 1, end, left, right));
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> T = {
        {73, 74, 75, 71, 69, 72, 76, 73}
    };

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < T.size(); i++)
        ret.push_back(solution.dailyTemperatures(T[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {1, 1, 4, 2, 1, 1, 0, 0}
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